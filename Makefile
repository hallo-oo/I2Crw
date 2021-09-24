
export RELEASE_DIR ?= $(PWD)

export ARCH ?= arm
export CHIP ?= T2K

export CROSS_COMPILE ?= arm-none-linux-gnueabi-

export CC := $(CROSS_COMPILE)gcc
export CXX := $(CROSS_COMPILE)g++
export AR := $(CROSS_COMPILE)ar

# ����ģ������.
APP_NAME := i2crw

LIBS := 
COMM_OBJ := 

CFLAGS := 

# Ԥ�����
#CFLAGS += -DCHIP=$(CHIP) -DDEBUG

# �������
# -ffunction-sections -fdata-sectionsѡ�������к�������Ϊ����section
# ��������-Wl,--gc-sections���Խ����õĺ����Ż���
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -Wl,-gc-sections

CFLAGS += -Wall -g

CFLAGS += -Os -pipe -mcpu=cortex-a9

# �������-sѡ����GCC ��strip��ʽ���ӣ�������С���ɵ��ļ����
LDFLAGS := -s
LDFLAGS += -lpthread -lm -ldl

# ���� library Ŀ¼,�����ں�����Ӷ��.
LIBS += 

# ���� include Ŀ¼,�����ں�����Ӷ��.
INC += -I.

# ���� source Ŀ¼.
DIR_SOURCE += .

# ���C�ļ�
SEARCH_SRC := $(foreach PATH, $(DIR_SOURCE), $(shell find $(PATH) -type f -name '*.c' -print))
SEARCH_OBJ := $(SEARCH_SRC:%.c=%.o)
OBJ += $(SEARCH_OBJ)

# ���� source Ŀ¼.ÿ��ֻ������һ��Ŀ¼
#DIR_SOURCE += .
# ���ñ�������ӵ�CԴ���ļ�.
#SRC := $(shell find $(DIR_SOURCE) -type f -name '*.c' -print)
#OBJ += $(SRC:%.c=%.o)

all: $(APP_NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(APP_NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INC) -o $@ $^

clean:
	@rm -f $(OBJ)
	@rm -f $(APP_NAME)
