package main

import (
	"sync"
)

type Data struct {
	data []string
	lock *sync.Mutex
}

func NewData() *Data {
	data := new(Data)
	data.data = make([]string, 10)
	data.lock = new(sync.Mutex)
	return data
}

func (this *Data) setData(_data string) {
	this.lock.Lock()
	defer this.lock.Unlock()
	this.data = append(this.data, _data)
}

func (this *Data) getData() string {
	this.lock.Lock()
	defer this.lock.Unlock()
	if len(this.data) > 0 {
		return this.data[0]
	}
	return ""
}

func (this *Data) delData() {
	this.lock.Lock()
	defer this.lock.Unlock()
	if len(this.data) > 0 {
		this.data = this.data[1:]
	}
}
