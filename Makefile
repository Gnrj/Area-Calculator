
CC := gcc
NASM := nasm
X_FILE := program.x

FILES := main.o flags.o test.o chords.o integral.o

TRG := compile_main compile_flags compile_test compile_chords compile_integral

all: run clean ## Make run and clean

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

compile_test: src/test.c
	@${CC} -c src/test.c -o test.o

compile_integral: src/integral.c
	@${CC} -c src/integral.c -o integral.o

run: link_files ## Compile and link all files and run program
	@./${X_FILE} $(cflags)

clean: ## Clean output file
	@rm *.o $(X_FILE) 2>/dev/null || true
