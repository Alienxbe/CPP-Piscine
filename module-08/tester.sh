#!/bin/bash

set -e

ROOT="."

GREEN="\033[0;32m"
RED="\033[0;31m"
BLUE="\033[0;34m"
YELLOW="\033[1;33m"
NC="\033[0m"

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

	# 🧹 clean after build
	make -C "$ROOT/$EX" fclean > /dev/null 2>&1
}

run_ex()
{
	EX=$1
	EXEC=$2

	log_info "Running $EX"

	./$ROOT/$EX/$EXEC
}

########################################
# EX00
########################################
test_ex00()
{
	build_ex "ex00"

	log_info "EX00 easyfind (manual check)"

	run_ex "ex00" "easyfind" || true
}

########################################
# EX01 SPAN
########################################
test_ex01()
{
	build_ex "ex01"

	log_info "EX01 Span stress test (10k elements)"

	EXEC="$ROOT/ex01/span_test"

	cat << EOF > /tmp/span_test.cpp
#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp(20000);

	for (int i = 0; i < 20000; i++)
		sp.addNumber(i);

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp.longestSpan() << std::endl;

	return 0;
}
EOF

	c++ -Wall -Wextra -Werror -std=c++98 \
		-I"$ROOT/ex01" \
		/tmp/span_test.cpp \
		"$ROOT/ex01/Span.cpp" \
		-o "$EXEC"

	./"$EXEC"

	rm -f /tmp/span_test.cpp
	rm -f "$EXEC"

	log_ok "EX01 passed"
}

########################################
# EX02 MUTANTSTACK
########################################
test_ex02()
{
	build_ex "ex02"

	log_info "EX02 MutantStack vs std::list"

	EXEC="$ROOT/ex02/mutant_test"

	cat << EOF > /tmp/mutant_test.cpp
#include <iostream>
#include <list>
#include "MutantStack.hpp"

template <typename T>
void print(T &c)
{
	typename T::iterator it = c.begin();
	typename T::iterator ite = c.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	std::cout << "${BLUE}MutantStack:${NC}" << std::endl;

	MutantStack<int> m;
	m.push(5);
	m.push(17);
	m.pop();
	m.push(3);
	m.push(5);
	m.push(737);
	m.push(0);

	print(m);

	std::cout << "${BLUE}List:${NC}" << std::endl;

	std::list<int> l;
	l.push_back(5);
	l.push_back(17);
	l.pop_back();
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);

	print(l);

	return 0;
}
EOF

	c++ -Wall -Wextra -Werror -std=c++98 \
		-I"$ROOT/ex02" \
		/tmp/mutant_test.cpp \
		-o "$EXEC"

	./"$EXEC"

	rm -f /tmp/mutant_test.cpp
	rm -f "$EXEC"

	log_ok "EX02 passed"
}

########################################
# MAIN
########################################

echo -e "${YELLOW}==============================${NC}"
echo -e "${YELLOW}   C++ MODULE 08 TESTER${NC}"
echo -e "${YELLOW}==============================${NC}"

echo ""

test_ex00

echo ""

test_ex01

echo ""

test_ex02

echo ""

echo -e "${GREEN}==============================${NC}"
echo -e "${GREEN} ALL TESTS DONE${NC}"
echo -e "${GREEN}==============================${NC}"