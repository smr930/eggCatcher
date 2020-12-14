# Egg Catcher makefile
TARGET = egg_catcher

OBJS = src/main.o src/lib/glib2d.o \
	src/Line.o \
	src/Sprite.o \
	src/Game.o \
	src/State.o \
	src/Intro.o \
	src/Title.o \
	src/LineBox.o \
	src/Parrot.o \
	src/Cat.o \
	src/Egg.o \
	src/Pause.o \
	src/Digit.o \
	src/Digits.o \
	src/Score.o \
	src/Results.o 


LIBS = -ljpeg -lpng -lz -lpspgum -lpspgu -lpsprtc -lm -lpspvram -lstdc++

CFLAGS = -O2 -G0 -Wall -I/src 
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti 
ASFLAGS = $(CFLAGS)

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Egg Catcher
PSP_EBOOT_ICON = ICON0.png
PSP_EBOOT_BG = PIC0.png
PSP_EBOOT_SND = SND0.AT3
PSP_LARGE_MEMORY = 1

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak 
install:
	cp ./EBOOT.PBP $(MEDIA)$(TARGET)
	rm *.elf
	rm *.sfo
dir:
	mkdir $(MEDIA)$(TARGET)
lclean:
	rm *.o

