FLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -Wlarger-than=8192 -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,nonnull-attribute,null,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

COMMON_INCLUDES = -I./COMMON/headers
CONFIG_INCLUDES = -I./CONFIG
STK_INCLUDES    = -I./STACK/headers

COMMON_FILES   = COMMON/IsBadPtr.cpp COMMON/logger.cpp

all: help

stk: main.cpp $(COMMON_FILES)
	@echo "-----------------------------------------------------------------------------------------"
	g++ -o stk_program $(FLAGS) main.cpp $(COMMON_INCLUDES) $(CONFIG_INCLUDES) $(STK_INCLUDES) $(COMMON_FILES)
	@echo "-----------------------------------------------------------------------------------------"

run-stk: stk
	./stk_program

run: run-stk
	./stk_program

clean:
	rm -f stk_program

help:
	@echo "Available commands:"
	@echo ""
	@echo "  make stk                     - compile a stk"
	@echo "  make run-stk                 - compile and run stk"
	@echo "  make run                     - compile and run stk"
	@echo ""
	@echo "  make clean                    - remove compiled programs"

.PHONY: stk run-stk run clean help