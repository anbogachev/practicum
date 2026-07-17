/*
 * hello-world.c - Simple NetBSD kernel module.
 * It prints messages on load and unload.
 */

#include <sys/param.h>
#include <sys/module.h>

/*
 * Initialization the module with the kernel
 */

 MODULE(MODULE_CLASS_MISC, hello_world, NULL);
 
/*
 * Load handler - called when the module is loaded
 */
static int
hello_world_modcmd(modcmd_t cmd, void *arg __unused)
{
        int error = 0;

	switch (cmd) {
	case MODULE_CMD_INIT:
                printf("Hello, World! Example  module loaded.\n");
                break;
        case MODULE_CMD_FINI:
                printf("Goodbye, World! Example module unloaded.\n");
                break;
        case MODULE_CMD_STAT:
                printf("Stasus, World! Example module status queried.\n");
                break;
        default:
                error = ENOTTY;
                /* FALLTHROUGH*/
	}
        return (error);
}
