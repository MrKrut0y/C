#ifndef _LIST_H
#define _LIST_H

extern const char delimiters[];

int strToWords(const char str[81], char words[40][21]);
int findString(const char stringList[20][21], int count, const char str[21]);

#endif /* _LIST_H */