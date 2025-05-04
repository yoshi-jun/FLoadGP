package main

import (
  "fmt"
  "os"
  "time"
)

func main(){
  fmt.Println("##### Begin read file #####")
  s := time.Now()
  for i := 0; i < 200; i++ {
    filename := fmt.Sprintf("input_data/%d.txt", i+1)
    f, err := os.Open(filename)
    if err != nil {
      fmt.Println("error")
    }
    defer f.Close()
    
    buf := make([]byte, 1024)
    for {
      n, err := f.Read(buf)
      if n == 0 {
        break
      }
      if err != nil {
        break
      }
      // fmt.Println(string(buf[:n]))
    }
  }
  fmt.Printf("process time: %s\n", time.Since(s))
}
