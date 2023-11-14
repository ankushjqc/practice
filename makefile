ag: ag.o
        cc ag.o -o ag # Runs third

ag.o: ag.c
        cc -c ag.c -o ag.o # Runs second

# Typically ag.c would already exist, but I want to limit any additional required files
ag.c:
        echo "int main() { return 0; }" > ag.c # Runs first

.PHONY: clean
clean:
	rm ag.*
