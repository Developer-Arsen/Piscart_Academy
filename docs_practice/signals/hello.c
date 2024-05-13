#include <linux/module.h>       // Needed by all modules
#include <linux/kernel.h>       // Needed for kernel logging and other purposes

// Module loading function
int init_module(void)
{
    pr_info("Hello, world - this is the kernel speaking.\n");
    // Return 0 means module loaded successfully
    return 0;
}

// Module unloading function
void cleanup_module(void)
{
    pr_info("Goodbye world from the kernel.\n");
}

// MODULE_LICENSE("GPL");
// MODULE_AUTHOR("Your Name");
// MODULE_DESCRIPTION("A simple example Linux kernel module.");
