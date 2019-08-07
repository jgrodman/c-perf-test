# build statically linked
gcc -O3 -o visitor_static visitor.c ../visit.o

# build dynamically linked
gcc -O3 -o visitor_dynamic visitor.c ../libvisit.so
