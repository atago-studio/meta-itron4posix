objs = main.o tsk_sample1.o tsk_sample2.o

.PHONY : all

all : tsksample

tsksample : $(objs)
	$(CC) -o $@ $^ -litron -lpthread

clean :
	rm -f *.o sample
