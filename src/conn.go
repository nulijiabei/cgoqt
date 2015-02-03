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

func (this *Conn) Connect(_device, _version string) error {
	url := fmt.Sprintf("ws://evolver.danoolive.com:6868/api/command?device=%s&version=%s", _device, _version)
	origin := "http://evolver.danoolive.com:6868"
	ws, err := websocket.Dial(url, "", origin)
	if err != nil {
		return err
	} else {
		this.Ws = ws
		go this.ReadConn()
	}
	return nil
}

func (this *Conn) ReadConn() {

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

		// 设备返回信息
		if ok && !z.IsBlank(rd) {
			cgo_display(rd)
		}

		// 服务器返回信息
		if !ok && !z.IsBlank(rd) {
			StaticData.setData(rd)
		}

	}

}

func (this *Conn) SendCommandByConn(_command string) {
	command := make(map[string]interface{})
	command["type"] = "command"
	command["command"] = _command
	data, _ := json.MarshalIndent(command, "", "  ")
	log.Printf("Connect(Server) Command -> \n%s\n", data)
	this.SendJsonByConn(command)
}

func (this *Conn) SendGolineByConn(_ipaddr, _username, _password, _color string) {
	command := make(map[string]interface{})
	command["type"] = "goline"
	command["ipaddr"] = _ipaddr
	command["username"] = _username
	command["password"] = _password
	if _color == "true" {
		command["color"] = true
	} else {
		command["color"] = false
	}
	data, _ := json.MarshalIndent(command, "", "  ")
	log.Printf("Connect(Server) Command -> \n%s\n", data)
	this.SendJsonByConn(command)
}

func (this *Conn) CheckConn() bool {
	if this.Ws == nil {
		return false
	}
	return true
}

func (this *Conn) DisConn() {
	if this.CheckConn() {
		this.Ws.Close()
		this.Ws = nil
	}
}

func (this *Conn) SendJsonByConn(data interface{}) {
	if !this.CheckConn() {
		StaticData.setData("Connect Disconnect.")
		return
	}
	content, err := json.Marshal(data)
	if err != nil {
		StaticData.setData(err.Error())
		return
	}
	_, err = io.WriteString(this.Ws, string(content)+"\n")
	if err != nil {
		StaticData.setData(err.Error())
		return
	}
}
