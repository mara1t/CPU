CFLAGS = -Wall -Wextra
CC = g++

assembler: main_asm.o asm.o
	$(CC) main_asm.o asm.o -o asm_do.exe $(CFLAGS)

cpu: stk_func_for_proc.o proc_execute.o proc_main.o
	$(CC) stk_func_for_proc.o proc_execute.o proc_main.o -o cpu_do.exe $(CFLAGS)

disassembler: main_disassemble.o
	$(CC) main_disassemble.o -o disasm_do.exe $(CFLAGS)

assembler_cpu: assembler asm_do cpu cpu_do



main_asm.o: assembler/main_asm.cpp
	$(CC) -c assembler/main_asm.cpp

asm.o: assembler/asm.cpp
	$(CC) -c assembler/asm.cpp

asm_do:
	./asm_do.exe



proc_main.o: cpu/proc_main.cpp
	$(CC) -c cpu/proc_main.cpp $(CFLAGS)

proc_execute.o: cpu/proc_execute.cpp
	$(CC) -c cpu/proc_execute.cpp

stk_func_for_proc.o: cpu/STACK/stk_func_for_proc.cpp
	$(CC) -c cpu/STACK/stk_func_for_proc.cpp

cpu_do:
	./cpu_do.exe



main_disassemble.o: disassembler/main_disassemble.cpp
	$(CC) -c disassembler/main_disassemble.cpp

disasm_do:
	./disasm_do.exe



clean_exe:
	rm -rf *.exe

clean_o:
	rm -rf *.o

clean: clean_exe clean_o
