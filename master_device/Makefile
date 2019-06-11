PWD         := $(shell pwd) 
KVERSION    := $(shell uname -r)
KERNEL_DIR   = /lib/modules/$(KVERSION)/build
MODULE_NAME  = master_device
obj-m       := $(MODULE_NAME).o   

all:
	cp ../ksocket/Module.symvers ./Module.symvers
	make -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean
