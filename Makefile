CFLAGS = -I./src
OBJDIR = obj
SRCDIR = src

OBJS = $(OBJDIR)/main.o

main: $(OBJDIR) $(OBJS)
	gcc $(OBJS) -o main

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc $(CFLAGS) -c $< -o $@
