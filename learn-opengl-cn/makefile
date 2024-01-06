.PHONY: all build clean

app := window

all: clean build

build:
	@cmake -S . -B ./build -DCMAKE_EXPORT_COMPILE_COMMANDS=1

run:
	./build/${app}

clean:
	@rm -rf build