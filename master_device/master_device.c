#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/types.h>
#include <linux/kthread.h>
#include <linux/errno.h>
#include <linux/net.h>
#include <linux/fs.h>
#include <linux/netdevice.h>
#include <linux/ip.h>
#include <linux/in.h>
#include <linux/misdevice.h>
#include <linux/delay.h>
#include <linux/slabs.h>
#include <linux/mm.h>
#include <net/sock.h>
#include <asm/processor.h>
#include <asm/uaccess.h>
#include <asm/page.h>
#include <asm/pgtable.h>
#include <asm/highmem.h>

#define DEFAULT_PORT 2325
#define master_IOCTL_CREATESOCK 0x12345677
#define master_IOCTL_MMAP 0x12345678
#define master_IOCTL_EXIT 0x12345679
#define BUF_SIZE 512
#define MAP_SIZE PAGE_SIZE * 100
typedef struct socket * ksocket_t;

//exported functions
extern ksocket_t ksocket( int domain, int type, int protocol);
