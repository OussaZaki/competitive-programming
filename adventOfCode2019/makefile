CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17
YEAR = 2018
AoC_URL = https://adventofcode.com/${YEAR}/day/

# Making the daily folder
# Copy the src template and do the replacement.
# Fetch daily input
init:
	mkdir day${day} && \
	cd day${day} && \
	cp ../day0.cpp day${day}.cpp && \
	sed -i.bak "s/day0/day${day}/g" day${day}.cpp && \
	sed -i.bak "s/Day0/Day${day}/g" day${day}.cpp && \
	sed -i.bak "s/#0/${day}/g" day${day}.cpp && \
	rm day${day}.cpp.bak && \
	curl -s -b "session=${AOC_COOKIE}" \
	--referer ${AoC_URL}${day} \
	-o ${day}.in ${AoC_URL}${day}/input 

# Compile and run daily problem
run:
	cd day${day} && $(CXX) $(CXXFLAGS) day${day}.cpp -o ${day}.out && ./${day}.out < ${day}.in

# Clean folder from output files
clean:
	find . -name "*.out" -type f -delete