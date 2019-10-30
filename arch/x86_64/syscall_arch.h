#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

extern weak long mythos_musl_syscall(long num, long a1, long a2, long a3,
	             long a4, long a5, long a6);

static __inline long __syscall0(long n)
{
	return mythos_musl_syscall(n,0,0,0,0,0,0);
}

static __inline long __syscall1(long n, long a1)
{
	return mythos_musl_syscall(n,a1,0,0,0,0,0);
}

static __inline long __syscall2(long n, long a1, long a2)
{
	return mythos_musl_syscall(n,a1,a2,0,0,0,0);
}

static __inline long __syscall3(long n, long a1, long a2, long a3)
{
	return mythos_musl_syscall(n,a1,a2,a3,0,0,0);
}

static __inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
	return mythos_musl_syscall(n,a1,a2,a3,a4,0,0);
}

static __inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
	return mythos_musl_syscall(n,a1,a2,a3,a4,a5,0);
}

static __inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
	return mythos_musl_syscall(n,a1,a2,a3,a4,a5,a6);
}

#define VDSO_USEFUL
#define VDSO_CGT_SYM "__vdso_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6"
#define VDSO_GETCPU_SYM "__vdso_getcpu"
#define VDSO_GETCPU_VER "LINUX_2.6"

#define IPC_64 0

