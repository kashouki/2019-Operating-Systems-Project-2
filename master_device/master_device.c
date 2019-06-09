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
struct debugentr *file1;




//exported functions
extern ksocket_t ksocket( int domain, int type, int protocol);
extern int kbind(ksocket_t socket, struct sockaddr *address, int address_len);
extern int klisten(ksocket_t socket, int backlog);
extern ksocket_t kaccept(ksocket_t socket, int backlog);
extern ssize_t ksend(ksocket_t socket, const void *buffer, size_t length, int flag);
extern int kclose(ksocket_t socket);
extern char *inet_ntoa(struct in_addr *in);

static int __init master_init(void);
static void __exit master_exit(void);

int master_close(struct inode *inode, struct file *filp);
int master_open(struct inode *inode, struct file *filp);
static long master_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param);
static ssize_t send_msg(struct file *file, const char __user *buf, size_t count, loff_t, *data);

static ksocket_t sockfd_srv, sockfd_cli;
static struct sockaddr_in addr_srv;
static struct sockaddr_in addr_cli;
static mm_segment_t old_fs;
static int addr_len;
