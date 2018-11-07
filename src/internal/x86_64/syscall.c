typedef long syscall_arg_t;

extern __attribute__ ((weak)) long mythos_musl_syscall(syscall_arg_t num, syscall_arg_t a1, syscall_arg_t a2, syscall_arg_t a3,
	             syscall_arg_t a4, syscall_arg_t a5, syscall_arg_t a6);

long __syscall(syscall_arg_t num, syscall_arg_t a1, syscall_arg_t a2, syscall_arg_t a3,
	             syscall_arg_t a4, syscall_arg_t a5, syscall_arg_t a6) {
        return mythos_musl_syscall(num, a1, a2, a3, a4, a5, a6);
}
