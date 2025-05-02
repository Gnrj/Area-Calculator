
CC := gcc
NASM := nasm
X_FILE := program.x

FILES := main.o flags.o functions.o

TRG := compile_main compile_flags compile_functions

all: run clean ## make run and clean

help: ## Show help
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)

link_files: ${TRG} ## Link all files and compile to program.x
	@${CC} -m32 ${FILES} -o $(X_FILE)

compile_main: main.c ## Сompile main.c
	@${CC} -m32 -std=c99 -c main.c -o main.o

compile_flags: src/flags.c ## Compile flags.c
	@${CC} -m32 -std=c99 -c src/flags.c -o flags.o

compile_functions: srasm/functions.asm ## Сompile functions.asm
	@${NASM} -f elf32 srasm/functions.asm -o functions.o

run: link_files ## Compile and run programm
	@./${X_FILE} $(CFLAGS)

clean: ## Clean output file
	@rm *.o $(X_FILE) 2>/dev/null || true
