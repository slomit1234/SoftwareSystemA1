CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB1=basicClassification.o
OBJECTS_LIB2=advancedClassificationLoop.o
OBJECTS_LIB3=advancedClassificationRecursion.o
FLAGS= -Wall -fPIC -g

all: libclassloops.so libclassrec.so libclassloops.a libclassrec.a mains maindloop maindrec
maindrec: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o  maindrec $(OBJECTS_MAIN) ./libclassrec.so -lm
maindloop: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o  maindloop $(OBJECTS_MAIN) ./libclassloops.so -lm
mains: $(OBJECTS_MAIN) libclassrec.a 
	$(CC) $(FLAGS) -o  mains $(OBJECTS_MAIN) libclassrec.a -lm
libclassloops.so: $(OBJECTS_LIB1) $(OBJECTS_LIB2)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LIB1) $(OBJECTS_LIB2)
libclassrec.so: $(OBJECTS_LIB1) $(OBJECTS_LIB3)
	$(CC) -shared -o libclassrec.so $(OBJECTS_LIB1) $(OBJECTS_LIB3)
libclassloops.a: $(OBJECTS_LIB1) $(OBJECTS_LIB2)
	$(AR) -rcs  libclassloops.a $(OBJECTS_LIB1) $(OBJECTS_LIB2)
libclassrec.a: $(OBJECTS_LIB1) $(OBJECTS_LIB3)
	$(AR) -rcs  libclassrec.a $(OBJECTS_LIB1) $(OBJECTS_LIB3)
basicClassification.o: basicClassification.c  NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c 
advancedClassificationLoop.o: advancedClassificationLoop.c  NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -lm
advancedClassificationRecursion.o: advancedClassificationRecursion.c  NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -lm 
main.o: main.c  NumClass.h
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec