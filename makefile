# Makefile for generating Hello World HTML

# The default target
all: hello.html ag

# Rule to generate hello.html
hello.html: hello.html.in
	cp $< html/$@

ag: ag.o
	cc ag.o -o ag # Runs third

ag.o: ag.c
	cc -c ag.c -o ag.o # Runs second

# Typically ag.c would already exist, but I want to limit any additional required files
ag.c:
	echo "int main() { return 0; }" > ag.c # Runs first

# Rule to clean generated files
.PHONY: clean
clean:
	rm -f hello.html ag ag.* html/hello.html
