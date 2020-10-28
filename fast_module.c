#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/io.h>

#define SERIAL_ADDR (1016)
static int __init lkm_example_init(void)
{
	char word = 'a';
	u16 addr = SERIAL_ADDR;

	asm volatile ("out %0, (%1)\n"::"a"(word), "d"(addr):"memory");
	return 0;
}

static void __exit lkm_example_exit(void)
{
	printk("fast_module: Bye!");
}

module_init(lkm_example_init);
module_exit(lkm_example_exit);
