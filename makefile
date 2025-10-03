FLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -Wlarger-than=8192 -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,nonnull-attribute,null,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

ASM_INCLUDES = -I./Compiler/headers_comp
STK_INCLUDES = -I./headers

ASM_FILES = Compiler/ArrPtrCtor.cpp Compiler/assembly.cpp Compiler/CmdNumber.cpp Compiler/Compiler.cpp Compiler/ErrPrint.cpp Compiler/HashCmd.cpp IsBadPtr.cpp Compiler/SizeFile.cpp
STK_FILES = Compiler/ArrPtrCtor.cpp Compiler/CmdNumber.cpp Compiler/SizeFile.cpp CalcErrPrint.cpp Calculator.cpp HashFunc.cpp IsBadPtr.cpp StackDump.cpp StackFunc.cpp StackVerify.cpp

all: help

comp: Compiler/main_comp.cpp $(ASM_FILES)
	@echo "-----------------------------------------------------------------------------------------"
	g++ $(FLAGS) Compiler/main_comp.cpp $(ASM_FILES) $(ASM_INCLUDES) -o comp_program
	@echo "-----------------------------------------------------------------------------------------"

user: main_user.cpp $(STK_FILES)
	@echo "-----------------------------------------------------------------------------------------"
	g++ $(FLAGS) main_user.cpp $(STK_FILES) $(STK_INCLUDES) $(ASM_INCLUDES) -o user_program
	@echo "-----------------------------------------------------------------------------------------"

test: main_test.cpp $(STK_FILES)
	@echo "-----------------------------------------------------------------------------------------"
	g++ $(FLAGS) main_test.cpp $(STK_FILES) $(STK_INCLUDES) $(ASM_INCLUDES) -o test_program
	@echo "-----------------------------------------------------------------------------------------"

run-comp: comp
	./comp_program

run-user: user
	./user_program

run-test: test
	./test_program

run: run-test

clean:
	rm -f user_program test_program

help:
	@echo "Available commands:"
	@echo "  make comp      - compile a compiler (main_comp.cpp)"
	@echo "  make user      - compile a user version (main_user.cpp)"
	@echo "  make test      - compile a test version (main_test.cpp)"
	@echo "  make run-comp  - compile and run the compiler"
	@echo "  make run-user  - compile and run the user version"
	@echo "  make run-test  - compile and run the test version"
	@echo "  make run       - compile and run the user version (default)"
	@echo "  make clean     - remove compiled programs"

.PHONY: all user test run-user run-test run both clean help