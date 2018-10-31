PROJECT?=DefaualtName
ALSA_DEVICE?=hw:02
EMBED_BOARD?=STM32F4DISCOVERY

CC = gcc
CARG = 
LARG = -lm

PY = python
TOOLS = tools
PYREMOVE = $(TOOLS)/removeGUI.py
PYTEMPLATE = $(TOOLS)/templateEngine.py
MAINTEMPLATE = MainTemplate.c

FAUST = faust
FARG = -lang c -o $(PROJECT).c -a minimal.c -cn $(PROJECT)
F2ALSA = faust2alsa
F2WEB = faust2wasm

RM = rm
MV = mv

SRC = src
ALSA = alsa
WEB = web
EMBED = embed
EMBEDLIB = $(EMBED)/lib
LIB = lib

all: web alsa embed

web: $(SRC)/$(PROJECT)/$(PROJECT)Demo.dsp $(SRC)/$(PROJECT)/$(PROJECT).dsp
	$(F2WEB) $(SRC)/$(PROJECT)/$(PROJECT)Demo.dsp
	$(MV) $(PROJECT)Demo.js $(WEB)/$(PROJECT)
	$(MV) $(PROJECT)Demo.wasm $(WEB)/$(PROJECT)

alsa: $(SRC)/$(PROJECT)/$(PROJECT)Demo.dsp $(SRC)/$(PROJECT)/$(PROJECT).dsp
	$(F2ALSA) $(SRC)/$(PROJECT)/$(PROJECT)Demo.dsp
	$(MV) $(SRC)/$(PROJECT)/$(PROJECT)Demo $(ALSA)/$(PROJECT)

embed: $(EMBED)/$(PROJECT)/$(PROJECT)Main.o
	$(CC) -o $(EMBED)/$(PROJECT)/$(PROJECT) $(EMBED)/$(PROJECT)/$(PROJECT)Main.o $(LARG)
	$(RM) $(EMBED)/$(PROJECT)/$(PROJECT)Main.o

$(EMBED)/$(PROJECT)/$(PROJECT)Main.o: embed_gen
	$(CC) $(CARG) -o $(EMBED)/$(PROJECT)/$(PROJECT)Main.o -c $(EMBED)/$(PROJECT)/$(PROJECT)Main.c

embed_gen: $(SRC)/$(PROJECT)/$(PROJECT)Demo.dsp $(SRC)/$(PROJECT)/$(PROJECT).dsp
	$(FAUST) $(FARG) $(SRC)/$(PROJECT)/$(PROJECT)Demo.dsp
	$(PY) $(PYREMOVE) $(PROJECT).c
	$(MV) $(PROJECT).c $(EMBED)/$(PROJECT)
	$(PY) $(PYTEMPLATE) $(PROJECT) $(EMBEDLIB)/$(MAINTEMPLATE) $(EMBED)/$(PROJECT)/$(PROJECT)Main.c


