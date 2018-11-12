CC=gcc
SOURCE=libpower.c
TESTAPP=test_libpower
TESTSOURCE=test_libpower.c
RM=rm -f $(TESTAPP)

# Build the test program
test: $(TESTSOURCE) $(SOURCE)
	$(CC) -o $(TESTAPP) $(TESTSOURCE) $(SOURCE) -lm

clean:
	$(RM)