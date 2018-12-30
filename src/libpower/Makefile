CC=gcc

LIB_SRC=libpower.c
TEST_SRC=test_libpower.c
OUTPUT_NAME=test_libpower

RM=rm -f $(OUTPUT_NAME)

# Build the test program
test: $(TEST_SRC) $(LIB_SRC)
	$(CC) -o $(OUTPUT_NAME) $(TEST_SRC) $(LIB_SRC) -lm

clean:
	$(RM)
