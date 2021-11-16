.PHONY: build

build:
	g++ ./main.cpp -o cmd_parse_app

default_goal: build def 
.PHONY: def
def:
	./cmd_parse_app -l -h -v -V1

.PHONY: run

run:
	./cmd_parse_app -l
	./cmd_parse_app -h
	./cmd_parse_app -V1
	./cmd_parse_app -v


.DEFAULT_GOAL:=default_goal
