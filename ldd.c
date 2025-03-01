#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("InPyjama - Piyush");
MODULE_DESCRIPTION("Basic Read loadable Kernel Module");
static struct proc_dir_entry *custom_proc_node;


static ssize_t pyjama_read(struct file* file_pointer,
                     char __user* user_space_buffer, 
                     size_t count,
                      loff_t* offset){
    char msg[]= "ack!\n";
    size_t len = strlen(msg);
    int result;
    printk("Pyjama_read\n");
    if(*offset >= len){
        return 0;
    }
    result = copy_to_user(user_space_buffer, msg , len);
    *offset += 1;
    

    
    return len;
}
struct proc_ops driver_proc_ops = {
    .proc_read= pyjama_read

};

static int __init pyjama_module_init(void) {

    printk("Pyjama_module_init: entry\n");
    custom_proc_node = proc_create("Pyjama_driver",
                            0, 
                            NULL, 
                            &driver_proc_ops);
    printk("Pyjama_module_init: exit\n");
    
    return 0;
}

static void __exit pyjama_module_exit(void) {
    printk("Pyjama_module_exit: entry\n");
    proc_remove(custom_proc_node);
    printk("Pyjama_module_exit: exit\n");
    
}



module_init(pyjama_module_init);
module_exit(pyjama_module_exit);

