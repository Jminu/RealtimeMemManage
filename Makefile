# 컴파일러 및 옵션
CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude

# 디렉토리
SRC_DIR = src
OBJ_DIR = build
BIN = memorytracker

# 소스 파일 목록
MAIN_SRC = main.c
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS)) $(OBJ_DIR)/main.o

# 기본 타겟
all: $(BIN)

# 실행 파일 빌드
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 오브젝트 파일 빌드 (src/*.c)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# main.o 따로 빌드
$(OBJ_DIR)/main.o: main.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# clean 명령
clean:
	rm -rf $(OBJ_DIR) $(BIN)

