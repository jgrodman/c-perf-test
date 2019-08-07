# build statically linked
g++ -O3 -o visitor_static visitor.cpp ../visit.o

# build dynamically linked
g++ -O3 -o visitor_dynamic visitor.cpp ../libvisit.so
