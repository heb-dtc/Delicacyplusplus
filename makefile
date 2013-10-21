CXX = g++
CFLAGS = -I.

ODIR = obj

DEPS = simpleNode.h simpleLinkedList.h dynamikArray.h

OBJ = mainApp.o simpleLinkedList.o dynamikArray.o

$(ODIR)/%.o: %.c $(DEPS)
		$(CXX) -c -o $@ $< $(CFLAGS)

mainApp:  $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o 