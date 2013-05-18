#
# makefile
#
# ****

include ./build/config.env
include ./build/config/$(BASIC_CONFIG)


EXENAME = mdspi_test


OBJS32 = ./src/MdSpi.o32 ./src/MdSpi_test.o32

OBJS64 = ./src/MdSpi.o64 ./src/MdSpi_test.o64


CCFLAGS =-I./src \
	-I/home/young001/Documents/ctp/include \
	-I/usr/local/log4cxx/include

LDFLAGS =-L/home/young001/Documents/ctp/lib -lthostmduserapi  -lthosttraderapi \
	-L/usr/local/log4cxx/lib -llog4cxx

include ./build/rules/exebuild
