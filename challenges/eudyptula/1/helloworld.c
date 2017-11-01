#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jun Woo Shin");
MODULE_DESCRIPTION("Prints 'Hello World!' to debug output");

static int  __init hello_world_init(void) {
	printk(KERN_DEBUG "Hello World!\n");
	return 0;
}

static void __exit hello_world_exit(void) {
	printk(KERN_DEBUG "Bye World!\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);
