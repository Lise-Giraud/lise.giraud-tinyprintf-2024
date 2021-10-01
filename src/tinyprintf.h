#ifndef TINYPRINTF_H
#define TINYPRINTF_H

int len(const char str[]);

void str_revert(char str[]);

void my_itoa_base(int n, const char *base, char negative);

int argument(const char *traverse, va_list args, unsigned int i, int j, int written);

int tinyprintf(const char *format, ...);

#endif /* TINYPRINTF */
