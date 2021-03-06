package main

import (
	"strings"
	"golang.org/x/tour/wc"
)

func WordCount(s string) map[string]int {
	var wordCount = make(map[string]int)
	var words = strings.Fields(s)
	for _, word := range words {
		wordCount[word]++
	}
	return wordCount
}

func main() {
	wc.Test(WordCount)
}

