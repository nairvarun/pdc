hello: hello.c
	@gcc -fopenmp hello.c -o build/hello
	@./build/hello

tst: tst.c
	@gcc -fopenmp tst.c -o build/tst
	@./build/tst

vector-addition: vector-addition.c
	@gcc -fopenmp vector-addition.c -o build/vector-addition
	@./build/vector-addition

dot-product: dot-product.c
	@gcc -fopenmp dot-product.c -o build/dot-product
	@./build/dot-product

loop-work-sharing: loop-work-sharing.c
	@gcc -fopenmp loop-work-sharing.c -o build/loop-work-sharing
	@./build/loop-work-sharing

section-work-sharing: section-work-sharing.c
	@gcc -fopenmp section-work-sharing.c -o build/section-work-sharing
	@./build/section-work-sharing

combined-parallel-loop-reduction: combined-parallel-loop-reduction.c
	@gcc -fopenmp combined-parallel-loop-reduction.c -o build/combined-parallel-loop-reduction
	@./build/combined-parallel-loop-reduction

orphaned-parallel-loop-reduction: orphaned-parallel-loop-reduction.c
	@gcc -fopenmp orphaned-parallel-loop-reduction.c -o build/orphaned-parallel-loop-reduction
	@./build/orphaned-parallel-loop-reduction

matrix-multiply: matrix-multiply.c
	@gcc -fopenmp matrix-multiply.c -o build/matrix-multiply
	@./build/matrix-multiply
