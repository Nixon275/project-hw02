SRC=$(wildcard src/*c)
EXESRC=$(wildcard exesrc/*c)
OBJ=exesrc/*o
EXE_DIR = exe/*
INC=inc/
MATH = -lm
CFLAGS=-I $(INC) 
EXE=$(EXESRC:%.c=%)

.SECONDARY:

all: $(EXE)

$(EXE): %: %.o
	gcc $< $(CFLAGS) -o $@ $(MATH)
	mv $@ exe/

%.o: %.c
	gcc -c $< $(CFLAGS) -o $@

run: all
	for binary in $(EXE_DIR); do \
	echo "Testing $$binary..."; \
        ./$$binary; \
    done

clean:
	rm -rf $(OBJ) $(EXE_DIR)