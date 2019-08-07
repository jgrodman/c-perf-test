# build .o file
gcc -O3 -o visit.o -c visit.c

# build .so file
gcc -O3 -shared -o libvisit.so -fPIC visit.c
