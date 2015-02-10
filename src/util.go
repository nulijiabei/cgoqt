package main

import (
	"unicode/utf8"
)

// 字符串转换
func StringToUtf8(_str string) string {
	var utf string
	b := []byte(_str)
	for len(b) > 0 {
		r, size := utf8.DecodeRune(b)
		utf += string(r)
		b = b[size:]
	}
	return utf
}
