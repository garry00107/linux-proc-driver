#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("InPyjama - Piyush");
MODULE_DESCRIPTION("Basic Read/Write Kernel Module");

#define BUFFER_SIZE 128
static struct proc_dir_entry *custom_proc_node;
static char kernel_buffer[BUFFER_SIZE];
static int message_length = 0;

/* Read function */
static ssize_t pyjama_read(struct file *file_pointer, char __user *user_space_buffer, size_t count, loff_t *offset) {
    if (*offset >= message_length) return 0;
    
    if (copy_to_user(user_space_buffer, kernel_buffer, message_length)) {
        return -EFAULT;
    }
    
    *offset += message_length;
    return message_length;
}

/* Write function */
static ssize_t pyjama_write(struct file *file_pointer, const char __user *user_space_buffer, size_t count, loff_t *offset) {
    if (count > BUFFER_SIZE) return -EINVAL;
    
    if (copy_from_user(kernel_buffer, user_space_buffer, count)) {
        return -EFAULT;
    }

    message_length = count;
    kernel_buffer[message_length] = '\0';
    printk(KERN_INFO "Received from user: %s\n", kernel_buffer);

    return count;
}

/* File operations */
static struct proc_ops driver_proc_ops = {
    .proc_read = pyjama_read,
    .proc_write = pyjama_write
};

/* Module Init */
static int __init pyjama_module_init(void) {
    printk(KERN_INFO "Pyjama_module_init: entry\n");
    custom_proc_node = proc_create("Pyjama_driver", 0666, NULL, &driver_proc_ops);
    if (!custom_proc_node) return -ENOMEM;
    
    printk(KERN_INFO "Pyjama_module_init: exit\n");
    return 0;
}

/* Module Exit */
static void __exit pyjama_module_exit(void) {
    printk(KERN_INFO "Pyjama_module_exit: entry\n");
    proc_remove(custom_proc_node);
    printk(KERN_INFO "Pyjama_module_exit: exit\n");
}

module_init(pyjama_module_init);
module_exit(pyjama_module_exit);
