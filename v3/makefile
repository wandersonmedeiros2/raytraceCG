# Compila programas do curso de OpenGL
# digite: make programa.cpp

CC = gcc
CPP = g++
CFLAGS = -O2
XLIBS = -L/usr/X11/lib -L/usr/X11R6/lib -lX11

##### MACROS #####

INCDIR = /usr/include
LIBDIR = /usr/lib

GL_LIBS = -L$(LIBDIR) -lglut -lGLU -lGL -lm -lpng -std=gnu++11 $(XLIBS)

LIBDEP = $(LIBDIR)/$(GL_LIB)


##### RULES #####

.SUFFIXES:
.SUFFIXES: .c .cpp

.cpp: $(LIB_DEP)
	$(CPP) -I$(INCDIR) -w $(CFLAGS)  $< -o $@ $(GL_LIBS) 


.c: $(LIB_DEP)
	$(CC) -I$(INCDIR) $(CFLAGS) $< -o $@ $(GL_LIBS)


##### TARGETS ######

clean:
	-rm *.o *~	
