#include "tinyprintf.h"
#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int print(char *s, int written) {
  int l = 0;
  if (s == NULL)
  {
    fputs("(null)", stdout);
    return 6;
  }
  while (s[l]) {
    putchar(s[l]);
    written++;
    l++;
  }
  return written;
}

int len(const char str[]) {
  int l = 0;
  while (str[l] != '\0') {
    l++;
  }
  return l;
}

void str_revert(char str[]) {
  int l = len(str) - 1;
  if (l <= 0)
    return;
  int i = 0;
  char tmp;
  for (; i < l; i++) {
    tmp = str[i];
    str[i] = str[l];
    str[l] = tmp;
    l--;
  }
}

void my_itoa_base(int n, const char *base, char negative, int written) {
  char s[500];
  int i = 0;
  int lb = len(base);
  if (n == 0) {
    s[i] = '0';
    print(s, written);
  }

  if (n < 0 && lb == 10) {
    negative = 1;
    n = -n;
  }

  while (n != 0) {
    int remainder = n % lb;
    s[i++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
    n /= lb;
  }

  if (negative)
    s[i++] = '-';
  s[i] = '\0';
  str_revert(s);
  print(s, written);
}

int argument(const char *traverse, va_list args, unsigned int i, int j,
             int written) {
  switch (*traverse) {
  case '%':
    putchar('%');
    written++;
    break;
  case 'd':
    j = va_arg(args, int);
    j < 0 ? my_itoa_base(j, "0123456789", 1, written)
          : my_itoa_base(j, "0123456789", 0, written);
    break;
  case 'u':
    i = va_arg(args, unsigned);
    my_itoa_base(i, "0123456789", 0, written);
    break;
  case 's':
    print(va_arg(args, char *), written);
    break;
  case 'c':
    putchar(va_arg(args, int));
    written++;
    break;
  case 'o':
    i = va_arg(args, unsigned);
    my_itoa_base(i, "01234567", 0, written);
    break;
  case 'x':
    i = va_arg(args, unsigned);
    my_itoa_base(i, "0123456789abcdef", 0, written);
    break;
  }
  return written;
}

int tinyprintf(const char *format, ...) {
  if (!format || format[0] == '\0')
    return 0;
  const char *traversal;
  int written = 0;
  unsigned int i = 0;
  int j = 0;

  va_list arg;
  va_start(arg, format);

  for (traversal = format; *traversal != '\0'; traversal++) {
    if (*traversal != '%') {
      putchar(*traversal);
      written++;
      continue;
    }
    traversal++;
    written += argument(traversal, arg, i, j, written);
  }
  va_end(arg);
  fflush(stdout);
  return written;
}
