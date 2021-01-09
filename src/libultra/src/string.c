#include <stddef.h>

void *memcpy(void *dst, const void *src, size_t size) {
  unsigned char *_dst = dst;
  const unsigned char *_src = src;
  while (size > 0) {
    *_dst++ = *_src++;
    size--;
  }
  return dst;
}

size_t strlen(const unsigned char *str) {
  const unsigned char *ptr = str;
  while (*ptr)
    ptr++;
  return ptr - str;
}

const unsigned char *strchr(const unsigned char *str, unsigned int ch) {
  unsigned char c = ch;
  while (*str != c) {
    if (*str == 0)
      return NULL;
    str++;
  }
  return str;
}
