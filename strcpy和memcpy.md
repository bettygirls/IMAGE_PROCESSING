
### strcpy ,strncpy 和 memcpy函数的区别
```
memcpy:
void  *memcpy(void *s1,  const void *s2,  size_t  n);
函数memcpy从s2指向的对象中复制n个字符到s1指向的对象中。如果复制发生在两个重叠的对象中，则这种行为未定义。

strpy:
char  *strcpy(char *s2, const char *s1);
函数strcpy把s1指向的串（包括空字符）复制到s2指向的数组中。如果复制发生在两个重叠的对象中，则这种行为未定义。

char  *strncpy(char *s2, const char *s1, size_t n);
函数strncpy从s1指向的数组中最多复制n个字符（不复制空字符后面的字符）到s2指向的数组中。
如果复制发生在两个重叠的对象中，则这种行为未定义。
如果s1指向的数组是一个比n短的字符串，则在s2定义的数组后面补空字符，直到写入了n个字符。

strcpy 是依据 “\0” 作为结束判断的，如果 s2 的空间不够，则会引起 buffer overflow。
memcpy用来在内存中复制数据，由于字符串是以“\0”结尾的，所以对于在数据中包含“\0”的数据只能用memcpy。

strncpy和memcpy很相似，只不过它在一个终止的空字符处停止。
当n>strlen(s1)时，给s2不够数的空间里填充“\0”；当n<=strlen(s1)时，s2是没有结束符“\0”的。

memcpy和memmove（）作用是一样的，唯一的区别是，当内存发生局部重叠的时候，memmove保证拷贝的结果是正确的，
memcpy 不保证正确

```
#### memcpy
```

void* my_memcpy(void* dst, const void* src, size_t n)

{

    char *tmp = (char*)dst;

    char *s_src = (char*)src;

 

    while(n--) {

        *tmp++ = *s_src++;

    }

    return dst;

}

```
#### memmove
```
void* my_memmove(void* dst, const void* src, size_t n)

{

    char* s_dst; //目标

    char* s_src; //源字符串

    s_dst = (char*)dst;

    s_src = (char*)src;

    if(s_dst>s_src && (s_src+n>s_dst)) {      //-------------------------第二种内存覆盖的情形。

        s_dst = s_dst+n-1; //从后面开始复制

        s_src = s_src+n-1; 

        while(n--) {

            *s_dst-- = *s_src--;

        }

    }else {

        while(n--) {

            *s_dst++ = *s_src++;

        }

    }

    return dst;

}
```
