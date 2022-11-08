
compile: main.cpp 
	 g++ main.cpp 

run: $(main.cpp)
	 ./$(main.cpp)

clean: $(main.cpp)
	 rm $(main.cpp)
