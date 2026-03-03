CFLAGS = -I./src -Wall -Wextra
OBJDIR = obj

main: $(OBJDIR) obj/main.o
	gcc -o main obj/main.o $(OBJDIR)/*.o 2>/dev/null || gcc -o main obj/main.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

obj/main.o: src/main.c | $(OBJDIR)
	gcc $(CFLAGS) -c src/main.c -o obj/main.o
