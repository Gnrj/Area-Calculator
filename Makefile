
CC := gcc
NASM := nasm
X_FILE := Area-Calculator.x

FILES := main.o flags.o difference.o chords.o integral.o derivative.o

TRG := compile_main compile_flags compile_test compile_chords compile_integral compile_derivative

all: link_files clean ## Make run and clean

help: ## Show help
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)
	@echo "Чтобы запустить программу вместе с флагом нужно написать: make cflags=флаг"
	@echo "Флаг --help выводит вспомогательную информацию о программе"

link_files: ${TRG} ## Compile and link all files to program.x
	@${CC} ${FILES} -o $(X_FILE)

compile_main: main.c ## Сompile main.c
	@${CC} -c main.c -o main.o

compile_flags: src/flags.c ## Compile flags.c
	@${CC} -c src/flags.c -o flags.o

compile_functions: srasm/functions.asm ## Сompile functions.asm
	@${NASM} -f elf32 srasm/functions.asm -o functions.o

compile_chords: src/chords.c ## Compile chords.c
	@${CC} -c src/chords.c -o chords.o

compile_test: src/difference.c ## Compile difference.c
	@${CC} -c src/difference.c -o difference.o

compile_integral: src/integral.c ## Compile integral.c
	@${CC} -c src/integral.c -o integral.o

compile_derivative: src/derivative.c ## Compile derivate.c
	@${CC} -c src/derivative.c -o derivative.o

run: link_files ## Compile and link all files and run program
	@./${X_FILE} $(cflags)

clean: ## Delete output files without object file
	@rm *.o 2>/dev/null || true

clean_object: ## Delete object file
	@rm ${X_FILE} 2>/dev/null || true
