TARGET:=app
SRC:=$(wildcard ./*.c)

.PHONY:clean

$(TARGET):$(SRC)
	gcc -g -Wall -O0 $^ -o $@

clean:
	rm $(TARGET)


