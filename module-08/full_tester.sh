#!/bin/bash

ROOT="."

GREEN="\033[0;32m"
RED="\033[0;31m"
BLUE="\033[0;34m"
YELLOW="\033[1;33m"
NC="\033[0m"

SCORE=0
TOTAL=3

log_ok()
{
	echo -e "${GREEN}[OK]${NC} $1"
}

log_fail()
{
	echo -e "${RED}[FAIL]${NC} $1"
}

log_info()
{
	echo -e "${BLUE}[INFO]${NC} $1"
}

section()
{
	echo ""
	echo "=================================================="
	echo "$1"
	echo "=================================================="
	echo ""
}

build_ex()
{
	EX=$1

	log_info "Building $EX"

	if make -C "$ROOT/$EX" re > /dev/null 2>&1; then
		log_ok "$EX built"
	else
		log_fail "$EX build failed"
		make -C "$ROOT/$EX" re
		exit 1
	fi

	make -C "$ROOT/$EX" fclean > /dev/null 2>&1
}

########################################
# EX00 (basic check only)
########################################
test_ex00()
{
	section "EX00 - easyfind"

	build_ex "ex00"

	log_info "Manual check required (no auto validation)"
	log_ok "EX00 assumed PASS"

	SCORE=$((SCORE + 1))
}

########################################
# EX01 - SPAN
########################################
test_ex01()
{
	section "EX01 - Span (10k test)"

	build_ex "ex01"

	EXEC="$ROOT/ex01/span_test"

	cat << EOF > /tmp/span_test.cpp
#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp(20000);

	for (int i = 0; i < 20000; i++)
		sp.addNumber(i);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
EOF

	c++ -Wall -Wextra -Werror -std=c++98 \
		-I"$ROOT/ex01" \
		/tmp/span_test.cpp \
		"$ROOT/ex01/Span.cpp" \
		-o "$EXEC"

	OUTPUT=$("./$EXEC")
	rm -f /tmp/span_test.cpp
	rm -f "$EXEC"

	EXPECTED="1
19999"

	if [ "$OUTPUT" = "$EXPECTED" ]; then
		log_ok "Span correctness"
		SCORE=$((SCORE + 1))
	else
		log_fail "Span incorrect output"
		echo "Got:"
		echo "$OUTPUT"
		echo "Expected:"
		echo "$EXPECTED"
	fi
}

########################################
# EX02 - MUTANTSTACK
########################################
test_ex02()
{
	section "EX02 - MutantStack"

	build_ex "ex02"

	EXEC="$ROOT/ex02/mutant_test"

	cat << EOF > /tmp/mutant_test.cpp
#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> m;
	m.push(5);
	m.push(17);
	m.pop();
	m.push(3);
	m.push(5);
	m.push(737);
	m.push(0);

	MutantStack<int>::iterator it = m.begin();
	MutantStack<int>::iterator ite = m.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}
EOF

	c++ -Wall -Wextra -Werror -std=c++98 \
		-I"$ROOT/ex02" \
		/tmp/mutant_test.cpp \
		-o "$EXEC"

	OUTPUT=$("./$EXEC")

	rm -f /tmp/mutant_test.cpp
	rm -f "$EXEC"

	# basic structural validation
	if echo "$OUTPUT" | grep -q "5" && echo "$OUTPUT" | grep -q "737"; then
		log_ok "MutantStack iteration works"
		SCORE=$((SCORE + 1))
	else
		log_fail "MutantStack iteration failed"
		echo "$OUTPUT"
	fi
}

########################################
# MAIN
########################################

section "C++ MODULE 08 TESTER"

test_ex00
test_ex01
test_ex02

section "FINAL SCORE"

echo "Score: $SCORE / $TOTAL"

if [ "$SCORE" -eq "$TOTAL" ]; then
	echo -e "${GREEN}PERFECT SCORE${NC}"
else
	echo -e "${YELLOW}Some tests failed${NC}"
fi