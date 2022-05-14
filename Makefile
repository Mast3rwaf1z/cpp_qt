compiler = g++

c_flags = -DQT_WIDGETS_LIB -I/usr/include/qt/QtWidgets -I/usr/include/qt -I/usr/include/qt/QtCore -DQT_GUI_LIB -I/usr/include/qt/QtGui -DQT_CORE_LIB -lQt5Widgets -lQt5Gui -lQt5Core -fPIC
objects := $(wildcard src/*.cpp)
temp := $(objects:src/%=bin/%)
binaries := $(temp:%.cpp=%)

_:
	@echo "run: 		compile and run file"
	@echo "compile: 	compile files in directory"
	@echo "file:		set file variable (file=filename)"

compile: $(objects)
	@echo "compiling... $^"
	@${compiler} $(c_flags) $(objects) -o $(binaries)

run: compile
	@echo running...
	@./$(binaries)
