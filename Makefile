.PHONY: all test clean distclean samples doc

OVERKILL = -pedantic -Wall -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wdouble-promotion -Wduplicated-branches -Wduplicated-cond -Werror -Wextra -Wfatal-errors -Wfloat-equal -Wformat=2 -Winit-self -Winline -Wlogical-op -Wlto-type-mismatch -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wpedantic -Wredundant-decls -Wshadow -Wshadow-local -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Wuseless-cast 

#CFLAGS = -Wall -Werror -Wpedantic -pedantic -Wfatal-errors

CFLAGS = ${OVERKILL}

all: samples

test:
	make -C test test CFLAGS="${CFLAGS}"

samples:
	make -C samples all CFLAGS="${CFLAGS}"

clean:
	make -C test clean
	make -C samples clean

distclean: clean
	find . -name "*.d" -delete || true
	find . -name "*~" -delete || true

doc: doc/Documentation.md

doc/Documentation.md: include/*.hpp
	echo "# Documentation" > "doc/Documentation.md"
	./ndoc.sh *.hpp .
