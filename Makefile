
CC := gcc
NASM := nasm
X_FILE := program.x

FILES := main.o flags.o functions.o

TRG := compile_main compile_flags compile_functions

all: run clean ## Make run and clean

help: ## Show help
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)

link_files: ${TRG} ## Compile and link all files to program.x
	@${CC} -m32 ${FILES} -o $(X_FILE)

compile_main: main.c ## Сompile main.c
	@${CC} -m32 -std=c99 -c main.c -o main.o

compile_flags: src/flags.c ## Compile flags.c
	@${CC} -m32 -std=c99 -c src/flags.c -o flags.o

compile_functions: srasm/functions.asm ## Сompile functions.asm
	@${NASM} -f elf32 srasm/functions.asm -o functions.o

run: link_files ## Compile and link all files and run program
	@./${X_FILE} $(CFLAGS)

clean: ## Clean output file
	@rm *.o $(X_FILE) 2>/dev/null || true
