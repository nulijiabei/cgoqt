package main

import (
	"bufio"
	"code.google.com/p/go.net/websocket"
	"encoding/json"
	"fmt"
	simplejson "github.com/bitly/go-simplejson"
	z "github.com/nutzam/zgo"
	"io"
	"log"
)

type Conn struct {
	Ws *websocket.Conn
}

func NewConn() *Conn {
	conn := new(Conn)
	return conn
}

func (this *Conn) Connect(_device string) error {
	url := fmt.Sprintf("ws://127.0.0.1:8080/api/command?device=%s", _device)
	origin := "http://127.0.0.1:8080"
	ws, err := websocket.Dial(url, "", origin)
	if err != nil {
		return err
	} else {
		this.Ws = ws
		go this.Read()
	}
	return nil
}

func (this *Conn) Read() {

	r := bufio.NewReader(this.Ws)
	for {

		data, err := r.ReadBytes('\n')
		if err != nil {
			log.Printf("Connect(Server) exception(%s)", err.Error())
			break
		}

		js, err := simplejson.NewJson(data)
		if err != nil {
			log.Printf("Connect(Server) exception(%s)", err.Error())
			continue
		}

		code, _ := js.EncodePretty()
		log.Printf("Connect(Server) Command -> \n%s\n", code)

		ok, err := js.Get("ok").Bool()
		if err != nil {
			log.Printf("Connect(Server) exception(%s)", err.Error())
			continue
		}

		rd, err := js.Get("data").String()
		if err != nil {
			log.Printf("Connect(Server) exception(%s)", err.Error())
			continue
		}

		if ok && !z.IsBlank(rd) {
			cgo_callback(rd)
		}

		if !ok && z.IsBlank(rd) {
			cgo_callback(rd)
		}

	}

}

func (this *Conn) Takeback() error {
	command := make(map[string]interface{})
	command["protocol"] = "pull"
	data, _ := json.MarshalIndent(command, "", "  ")
	log.Printf("Connect(Server) Command -> \n%s\n", data)
	return this.WriteJsonToConn(command)
}

func (this *Conn) Write(_command string) error {
	command := make(map[string]interface{})
	command["protocol"] = "execute"
	command["command"] = _command
	data, _ := json.MarshalIndent(command, "", "  ")
	log.Printf("Connect(Server) Command -> \n%s\n", data)
	return this.WriteJsonToConn(command)
}

func (this *Conn) WriteJsonToConn(data interface{}) error {
	content, err := json.Marshal(data)
	if err != nil {
		return err
	}
	if this.Ws == nil {
		return fmt.Errorf("...")
	}
	_, err = io.WriteString(this.Ws, string(content)+"\n")
	if err != nil {
		return err
	}
	return nil
}
