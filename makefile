CXX = cl.exe
FLAGS = /EHsc /W4
EXE = main.exe
LNK = /link /out:$(EXE)

main: main.cpp
	$(CXX) $(FLAGS) main.cpp $(LNK)