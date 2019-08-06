# build statically linked
g++ -o visitor_static visitor.cpp ../visit.o

# build dynamically linked
g++ -o visitor_dynamic visitor.cpp ../libvisit.so
