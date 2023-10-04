obj-m += fast_module.o
all:
	make -C ${LINUX_TREE} M=$(PWD) modules
clean:
	make -C ${LINUX_TREE} M=$(PWD) clean
install:
	insmod fast_module.ko
uninstall:
	rmmod fast_module
