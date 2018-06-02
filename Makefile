# This is the root makefile of the Amperose project
# It will call component makefiles in their respective directories

MIC_DIR = ./microcontroller

build:
	make -C $(MIC_DIR) build
