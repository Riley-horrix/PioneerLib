all: generate-lib

test: generate-lib
	@ cd build && \
	make test && \
	./test

generate-lib:
	@ mkdir -p build && \
	cd build && \
	cmake .. && \
	make