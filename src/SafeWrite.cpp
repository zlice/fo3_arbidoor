#include <memoryapi.h>

// a bunch of (PDWORD) to shut up compiler warnings

void SafeWrite8(uint32_t addr, uint32_t data) {
  uint32_t oldProtect;

  VirtualProtect((void *)addr, 4, PAGE_EXECUTE_READWRITE, (PDWORD)&oldProtect);
  *((uint8_t *)addr) = data;
  VirtualProtect((void *)addr, 4, oldProtect, (PDWORD)&oldProtect);
}

void SafeWrite16(uint32_t addr, uint32_t data) {
  uint32_t oldProtect;

  VirtualProtect((void *)addr, 4, PAGE_EXECUTE_READWRITE, (PDWORD)&oldProtect);
  *((uint16_t *)addr) = data;
  VirtualProtect((void *)addr, 4, oldProtect, (PDWORD)&oldProtect);
}

void SafeWrite32(uint32_t addr, uint32_t data) {
  uint32_t oldProtect;

  VirtualProtect((void *)addr, 4, PAGE_EXECUTE_READWRITE, (PDWORD)&oldProtect);
  *((uint32_t *)addr) = data;
  VirtualProtect((void *)addr, 4, oldProtect, (PDWORD)&oldProtect);
}

void SafeWriteBuf(uint32_t addr, void * data, uint32_t len) {
  uint32_t oldProtect;

  VirtualProtect((void *)addr, len, PAGE_EXECUTE_READWRITE, (PDWORD)&oldProtect);
  memcpy((void *)addr, data, len);
  VirtualProtect((void *)addr, len, oldProtect, (PDWORD)&oldProtect);
}

void WriteRelJump(uint32_t jumpSrc, uint32_t jumpTgt) {
  // jmp rel32
  SafeWrite8(jumpSrc, 0xE9);
  SafeWrite32(jumpSrc + 1, jumpTgt - jumpSrc - 1 - 4);
}

void WriteRelCall(uint32_t jumpSrc, uint32_t jumpTgt) {
  // call rel32
  SafeWrite8(jumpSrc, 0xE8);
  SafeWrite32(jumpSrc + 1, jumpTgt - jumpSrc - 1 - 4);
}
