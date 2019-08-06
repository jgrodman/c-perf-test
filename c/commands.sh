# build statically linked
gcc -o visitor_static visitor.c ../visit.o

# build dynamically linked
gcc -o visitor_dynamic visitor.c ../libvisit.so
