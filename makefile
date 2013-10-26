CXX = g++
CFLAGS = -I.

SRCDIR = src
OBJDIR = obj
OUTPUTDIR = out

DEPS = simpleNode.h simpleLinkedList.h dynamikArray.h binaryTreeNode.h simpleBinarySearchTree.h

_OBJS = mainApp.o simpleLinkedList.o dynamikArray.o binaryTreeNode.o simpleBinarySearchTree.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: %.cpp $(DEPS)
		$(CXX) -c -o $@ $< $(CFLAGS)


$(OUTPUTDIR)/mainApp:  $(OBJS)
		$(CXX) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f $(OBJDIR)/*.o 
	rm $(OUTPUTDIR)/mainApp