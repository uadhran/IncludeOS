#include <arch/x86/cpu.hpp>
#include <arch/x86/syscall.hpp>

extern "C" void __syscall_entry();

namespace x86 {

void init_syscall_trap()
{
  uint64_t star_kernel_cs = 8ull << 32;
  uint64_t star_user_cs   = 8ull << 48;
  uint64_t star = star_kernel_cs | star_user_cs;
  CPU::write_msr(IA32_STAR, star);
  CPU::write_msr(IA32_LSTAR, (uintptr_t)&__syscall_entry);
}

}