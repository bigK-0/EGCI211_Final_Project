
compile: main.cpp 
	 g++ main.cpp -o final

run: $ final
	 ./$ final

clean: $(main.cpp)
	 rm $(main.cpp)
