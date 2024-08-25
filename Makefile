all: generate-lib

clean:
	@ rm -rf ./build
	@ rm -rf ./html

ci: generate-lib-ci

test: generate-lib 
	@ cd build && \
	make test && \
	./test

test-ci: generate-lib-ci
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

generate-lib-ci:
	@ mkdir -p build && \
	cd build && \
	cmake -DCI=ON .. && \
	make


.PHONY: all test test-lint doc generate-lib clean