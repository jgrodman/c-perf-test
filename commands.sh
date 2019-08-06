# build .o file
gcc -o visit.o -c visit.c

# build .so file
gcc -shared -o libvisit.so -fPIC visit.c
