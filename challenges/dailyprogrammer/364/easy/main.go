package main


import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
)


func main() {
	filename := "input.txt"

	file, _ := os.Open(filename)
	defer file.Close()

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		text := scanner.Text()
		nums := strings.Split(text, "d")
		diceCount, _ := strconv.Atoi(nums[0])
		faces, _ := strconv.Atoi(nums[1])

		var sum int
		for i := 0; i < diceCount; i++ {
			random := rand.Intn(faces) + 1
			sum += random
		}

		fmt.Printf("%s = %d\n", text, sum)
	}
}
