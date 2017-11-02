#include <iconv.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;
 
int code_convert(const char *from_charset, const char *to_charset, char *inbuf,
		size_t inlen, char *outbuf, size_t outlen)
{
	iconv_t cd;
	char **pin = &inbuf;
	char **pout = &outbuf;
 
	cd = iconv_open(to_charset, from_charset);
	if (cd == 0)
		return -1;
	memset(outbuf, 0, outlen);
	if (iconv(cd, pin, &inlen, pout, &outlen) != 0)
		return -1;
	iconv_close(cd);
	return 0;
}
 
int u2g(char *inbuf, int inlen, char *outbuf, int outlen)
{
	return code_convert("utf-8", "gbk", inbuf, inlen, outbuf, outlen);
}
 
int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
	return code_convert("gb2312", "utf-8", inbuf, inlen, outbuf, outlen);
}
 
int main()
{
	// const char* utf8 = "您好中国";
	string utf8 = "您好中国";
	char *pUtf8 = (char *)utf8.c_str();
	char buff[1024] = { 0 };
	u2g(pUtf8, strlen(pUtf8), buff, sizeof(buff));
	printf("g2u=%s\n", buff);
	return 0;
}
