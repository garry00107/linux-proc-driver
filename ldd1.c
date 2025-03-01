#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("InPyjama - Piyush");
MODULE_DESCRIPTION("Our first dynamically loadable kernel module");

static int __init pyjama_module_init(void) {
    printk(KERN_INFO "Hello again, World! (from InPyjama!)\n");
    return 0;
}

static void __exit pyjama_module_exit(void) {
    printk(KERN_INFO "Goodbye! (from InPyjama!)\n");
}

module_init(pyjama_module_init);
module_exit(pyjama_module_exit);
