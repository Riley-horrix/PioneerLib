all: generate-lib

test: generate-lib
	@ cd build && \
	make test && \
	./test

test-lint:
	cpplint --recursive --exclude=./build --filter=-whitespace/ending_newline,-build/namespaces,-whitespace/indent .

doc:
	doxygen
	open ./html/index.html

generate-lib:
	@ mkdir -p build && \
	cd build && \
	cmake .. && \
	make