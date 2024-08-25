all: generate-lib

clean:
	@ rm -rf ./build
	@ rm -rf ./html

test: generate-lib
	@ cd build && \
	make test && \
	./test

test-lint:
	cpplint --recursive --exclude=./build --filter=-whitespace/ending_newline,-build/namespaces,-whitespace/indent .

doc:
	mkdir -p doc && \
	doxygen && \
	open ./doc/html/index.html

generate-lib:
	@ mkdir -p build && \
	cd build && \
	cmake .. && \
	make


.PHONY: all test test-lint doc generate-lib clean