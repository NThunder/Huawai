CC=gcc        # компилятор по умолчанию
LINK=gcc      # линковщик по умолчанию
CFLAGS=-fPIC  # флаги компилятора по умолчанию

# первая цель для сборки
first: all

# виртуальная цель для сборки всего
all: rootsseacher.so rootsseacher

# библиотека rootsseacher.so зависит от rootsseacher.o
rootsseacher.so: rootsseacher.o 
	$(LINK) -shared -o rootsseacher.so rootsseacher.o

# программа тоже зависит от объектного файла
rootsseacher: rootsseacher.o main.o
	$(LINK) -o rootsseacher rootsseacher.o main.o -lm

# правило для сборки объектного файла
rootsseacher.o: rootsseacher.c
	$(CC) -c $(CFLAGS) rootsseacher.c

# правило для сборки объектного файла
main.o: main.c
	$(CC) -c $(CFLAGS) main.c

# правило для очистки проекта
clean:
	rm main.o 
	rm rootsseacher.o 
