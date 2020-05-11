objects=main.o cutarg.o freem.o sh.o cmdline.o

mysh:$(objects)
	cc -o mysh $(objects)

main.o:
cutarg.o:
freem.o:
sh.o:
cmdline.o:

.PHONEY:clean
clean:
	rm mysh $(objects)
