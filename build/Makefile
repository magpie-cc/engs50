CFLAGS=-Wall -pedantic -std=c11 -g -I../src
SRC_DIR=../src
TEST_DIR=../test
BUILD_DIR=.

all: test_lput test_lget test_lapply test_lremove

# Object files
$(BUILD_DIR)/list.o: $(SRC_DIR)/list.c $(SRC_DIR)/list.h
	gcc $(CFLAGS) -c $(SRC_DIR)/list.c -o $(BUILD_DIR)/list.o

$(BUILD_DIR)/test_lput.o: $(TEST_DIR)/test_lput.c $(SRC_DIR)/list.h
	gcc $(CFLAGS) -c $(TEST_DIR)/test_lput.c -o $(BUILD_DIR)/test_lput.o

$(BUILD_DIR)/test_lget.o: $(TEST_DIR)/test_lget.c $(SRC_DIR)/list.h
	gcc $(CFLAGS) -c $(TEST_DIR)/test_lget.c -o $(BUILD_DIR)/test_lget.o

$(BUILD_DIR)/test_lapply.o: $(TEST_DIR)/test_lapply.c $(SRC_DIR)/list.h
	gcc $(CFLAGS) -c $(TEST_DIR)/test_lapply.c -o $(BUILD_DIR)/test_lapply.o

$(BUILD_DIR)/test_lremove.o: $(TEST_DIR)/test_lremove.c $(SRC_DIR)/list.h
	gcc $(CFLAGS) -c $(TEST_DIR)/test_lremove.c -o $(BUILD_DIR)/test_lremove.o

# Binaries
test_lput: $(BUILD_DIR)/list.o $(BUILD_DIR)/test_lput.o
	gcc $(CFLAGS) $(BUILD_DIR)/list.o $(BUILD_DIR)/test_lput.o -o test_lput

test_lget: $(BUILD_DIR)/list.o $(BUILD_DIR)/test_lget.o
	gcc $(CFLAGS) $(BUILD_DIR)/list.o $(BUILD_DIR)/test_lget.o -o test_lget

test_lapply: $(BUILD_DIR)/list.o $(BUILD_DIR)/test_lapply.o
	gcc $(CFLAGS) $(BUILD_DIR)/list.o $(BUILD_DIR)/test_lapply.o -o test_lapply

test_lremove: $(BUILD_DIR)/list.o $(BUILD_DIR)/test_lremove.o
	gcc $(CFLAGS) $(BUILD_DIR)/list.o $(BUILD_DIR)/test_lremove.o -o test_lremove

# Maintinance
# note: object files and binaries get put into the /build directory (the current folder)
clean:
	rm -f *.o test_lput test_lget test_lapply test_lremove
