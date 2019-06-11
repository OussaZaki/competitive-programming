package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var N int
	var result []int

	io := bufio.NewReader(os.Stdin)
    fmt.Fscan(io, &N)

	testCase(N, &result, io)
	result_string := sliceToString(result, "")
	
	print(result_string)
}

func testCase(N int, result *[]int, io *bufio.Reader) int{
	if N == 0 {
    	return 0
	}
	
	var X, S int
	fmt.Fscan(io, &X)
	*result = append(*result, sumSquaredPositive(S, X, io))
	
    return testCase(N - 1, result, io)
}

func sumSquaredPositive(S int, X int, io *bufio.Reader) int{
	var tmp int
	if X == 0 {
		return S
	}

	fmt.Fscan(io, &tmp)
	if tmp > 0 {
		return sumSquaredPositive(S + tmp * tmp, X - 1, io)
	} else {
        return sumSquaredPositive(S, X - 1, io)
    }
}

func sliceToString(result []int, s string) string{
	if (cap(result) == 0) {
		return s
	}
	s += strconv.Itoa(result[0]) + "\n"
	return sliceToString(result[1:], s)
}