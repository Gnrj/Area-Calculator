CC := gcc
NASM := nasm
X_FILE := Area-Calculator
OBJ_DIR := obj
SRC_C := src/c
SRC_ASM := src/asm

CFLAGS = -O2 -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default \
-Wfloat-equal -Wpointer-arith -Wtype-limits -Wempty-body -Wno-logical-op -Wstrict-prototypes -Wold-style-declaration \
-Wold-style-definition -Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs -Wno-pointer-sign -Wno-unused-result \
-std=c99 -lm -m32

ASMFLAGS = -f elf32

LDFLAGS = -lm -m32

C_SRCS = $(wildcard $(SRC_C)/*.c)
ASM_SRCS = $(wildcard $(SRC_ASM)/*.asm)

C_OBJS = $(patsubst $(SRC_C)/%.c, $(OBJ_DIR)/%.o, $(C_SRCS)) 
ASM_OBJS = $(patsubst $(SRC_ASM)/%.asm, obj/%.o, $(ASM_SRCS))

OBJS = $(C_OBJS) $(ASM_OBJS)

.PHONY: all clean

all: $(X_FILE) ## Create Area-Calculator

help: ## Show help
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)

$(X_FILE): $(OBJS) ## Compile and link all files to Area-Calculator
	@$(CC) -m32 -o $@ $^ -lm

$(OBJ_DIR)/%.o: $(SRC_C)/%.c | $(OBJ_DIR) ## Compile all .c files to object
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_ASM)/%.asm | $(OBJ_DIR) ##Complile all .asm files to object
	@${NASM} $(ASMFLAGS) -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean: ## Delete all object files with directory obj
	@rm -rf $(OBJ_DIR) $(X_FILE)   2>/dev/null || true
