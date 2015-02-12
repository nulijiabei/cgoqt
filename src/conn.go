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

func (this *Conn) Connect(_device, _version, _authorize string) error {
	url := fmt.Sprintf("ws://evolver.danoolive.com:6868/api/command?device=%s&version=%s&authorize=%s", _device, _version, _authorize)
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

		// 服务器返回信息
		// 只有在异常时才是False
		if !ok && !z.IsBlank(rd) {
			// CGO
			cgo_message(rd)
			// 返回
			continue
		}

		// 设备返回信息
		if ok {

			// 类型
			class, err := js.Get("type").String()
			if err != nil {
				log.Printf("Connect(Server) exception(%s)", err.Error())
				continue
			}

			// 文件类型
			if class == "reader" {
				// CGO
				cgo_content(rd)
				// 返回
				continue
			} else if class == "writer" {
				// CGO
				cgo_message(rd)
				// 返回
				continue
			}

			// 终端输出
			if !z.IsBlank(rd) {
				// CGO
				cgo_display(rd)
				// 返回
				continue
			}

		}

	}

}

func (this *Conn) SendReaderByConn(_command string) error {
	command := make(map[string]interface{})
	command["id"] = z.UnixNano()
	command["type"] = "reader"
	command["path"] = _command
	data, _ := json.MarshalIndent(command, "", "  ")
	log.Printf("Connect(Server) Command -> \n%s\n", data)
	return this.SendJsonByConn(command)
}

func (this *Conn) SendWriterByConn(_command string, _content string) error {
	command := make(map[string]interface{})
	command["id"] = z.UnixNano()
	command["type"] = "writer"
	command["path"] = _command
	command["content"] = _content
	data, _ := json.MarshalIndent(command, "", "  ")
	log.Printf("Connect(Server) Command -> \n%s\n", data)
	return this.SendJsonByConn(command)
}

func (this *Conn) SendCommandByConn(_command string) error {
	command := make(map[string]interface{})
	command["id"] = z.UnixNano()
	command["type"] = "command"
	command["command"] = _command
	data, _ := json.MarshalIndent(command, "", "  ")
	log.Printf("Connect(Server) Command -> \n%s\n", data)
	return this.SendJsonByConn(command)
}

func (this *Conn) SendGolineByConn(_ipaddr, _username, _password, _color string) error {
	command := make(map[string]interface{})
	command["id"] = z.UnixNano()
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
	return this.SendJsonByConn(command)
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

func (this *Conn) SendJsonByConn(data interface{}) error {
	if !this.CheckConn() {
		return fmt.Errorf(StringToUtf8("未连接到服务器,请连接."))
	}
	content, err := json.Marshal(data)
	if err != nil {
		return err
	}
	_, err = io.WriteString(this.Ws, string(content)+"\n")
	if err != nil {
		return err
	}
	return nil
}
