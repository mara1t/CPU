CFLAGS = -Wall -Wextra
CC = g++


assembler: main_asm.o asm.o header_og.o cmd_def.h assembler/asm.h
	$(CC) main_asm.o asm.o header_og.o -o asm_do.exe $(CFLAGS)

cpu: stk_func_for_proc.o proc.o proc_main.o cmd_def.h cpu/proc.h cpu/STACK/stk_header_for_proc.h
	$(CC) stk_func_for_proc.o proc.o proc_main.o -o cpu_do.exe $(CFLAGS)

disassembler: main_dis.o dis.o cmd_def.h disassembler/dis.h
	$(CC) main_dis.o dis.o -o dis_do.exe $(CFLAGS)

assembler_cpu: assembler asm_do cpu cpu_do



main_asm.o: assembler/main_asm.cpp
	$(CC) -c assembler/main_asm.cpp

asm.o: assembler/asm.cpp
	$(CC) -c assembler/asm.cpp

header_og.o: ../og/ONEGIN/header_og.cpp
	$(CC) -c ../og/ONEGIN/header_og.cpp

asm_do:
	./asm_do.exe



proc_main.o: cpu/proc_main.cpp
	$(CC) -c cpu/proc_main.cpp 

proc.o: cpu/proc.cpp
	$(CC) -c cpu/proc.cpp

stk_func_for_proc.o: cpu/STACK/stk_func_for_proc.cpp
	$(CC) -c cpu/STACK/stk_func_for_proc.cpp

cpu_do:
	./cpu_do.exe



main_dis.o: disassembler/main_dis.cpp
	$(CC) -c disassembler/main_dis.cpp

dis.o: disassembler/dis.cpp
	$(CC) -c disassembler/dis.cpp

dis_do:
	./dis_do.exe



clean_exe:
	rm *.exe

clean_o:
	rm *.o

clean: clean_exe clean_o
