
CC := gcc
NASM := nasm
X_FILE := Area-Calculator.x

FILES := main.o flags.o difference.o chords.o integral.o derivative.o test.o functions.o

TRG := compile_functions compile_main compile_flags compile_test compile_chords compile_integral compile_derivative compile_difference

CFLAGS = -O2 -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wpointer-arith -Wtype-limits -Wempty-body -Wno-logical-op -Wstrict-prototypes -Wold-style-declaration -Wold-style-definition -Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs -Wno-pointer-sign -Wno-unused-result -std=c99 -lm -m32

all: link_files clean ## Make run and clean

help: ## Show help
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)

link_files: ${TRG} ## Compile and link all files to program.x
	@${CC} -m32 ${FILES} -o $(X_FILE) -lm

compile_main: main.c ## Сompile main.c
	@${CC} ${CFLAGS} -c main.c -o main.o

compile_flags: src/flags.c ## Compile flags.c
	@${CC} ${CFLAGS} -c src/flags.c -o flags.o

compile_functions: srasm/functions.asm ## Сompile functions.asm
	@${NASM} -f elf32 srasm/functions.asm -o functions.o

compile_chords: src/chords.c ## Compile chords.c
	@${CC} ${CFLAGS} -c src/chords.c -o chords.o

compile_difference: src/difference.c ## Compile difference.c
	@${CC} ${CFLAGS} -c src/difference.c -o difference.o

compile_integral: src/integral.c ## Compile integral.c
	@${CC} ${CFLAGS} -c src/integral.c -o integral.o

compile_derivative: src/derivative.c ## Compile derivate.c
	@${CC} ${CFLAGS} -c src/derivative.c -o derivative.o

compile_test: src/test.c ## Compile test.c
	@${CC} ${CFLAGS} -c src/test.c -o test.o

run: link_files ## Compile and link all files and run program
	@./${X_FILE}

clean: ## Delete output files without object file
	@rm *.o 2>/dev/null || true

clean_object: ## Delete object file
	@rm ${X_FILE} 2>/dev/null || true
