#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#
#   ________        _________________.________
#  /  _____/  ____ /   _____/   __   \   ____/
# /   \  ___ /  _ \\_____  \\____    /____  \
#  \    \_\  (  <_> )        \  /    //       \
#   \______  /\____/_______  / /____//______  /
#          \/              \/               \/
# 
# Autore....: Alessandro Fraschetti
# Funzione..: makefile dei demo della libreria FGoS'95 Micro Utility Library
# Input.....: -
# Output....: exec
# Note......:
#
#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

OBJECTS  = info_demo.o date_demo.o system_demo.o text_demo.o
INCLUDES = ../distrib
LIBNAME  = mul
LIBPATH  = ../distrib
CC       = gcc
RM       = del
CFLAGS   = -Wall -ansi -pedantic -O2 -I$(INCLUDES) -c


info_demo.exe date_demo.exe system_demo.exe : info_demo.o date_demo.o system_demo.o text_demo.o
	$(CC) -o info_demo.exe info_demo.o -L$(LIBPATH) -l$(LIBNAME)
	$(CC) -o date_demo.exe date_demo.o -L$(LIBPATH) -l$(LIBNAME)
	$(CC) -o system_demo.exe system_demo.o -L$(LIBPATH) -l$(LIBNAME)
	$(CC) -o text_demo.exe text_demo.o -L$(LIBPATH) -l$(LIBNAME)



info_demo.o date_demo.o system.o: info_demo.c date_demo.c system_demo.c text_demo.c
	$(CC) $(CFLAGS) info_demo.c date_demo.c system_demo.c text_demo.c


.PHONY: clean
clean:
	$(RM) *.o
	$(RM) *.exe