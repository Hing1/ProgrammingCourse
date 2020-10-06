package main

import "fmt"

func fibonacci() func() int {
	a, b := 0, 0
	return func() int {
		c := a + b
		if c == 0 {
			c = 1
		}
		a, b = b, c
		return c
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
