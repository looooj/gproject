/* 
 * File:   main.cpp
 * Author: lijin
 *
 * Created on 2014年1月24日, 下午3:42
 */

#include <cstdlib>
#include <string.h>
#include <iconv.h>


//from http://blog.sina.com.cn/s/blog_4b69e3010100th1u.html

int code_convert(char *from_charset,char *to_charset,char *inbuf,int inlen,char *outbuf,int outlen)
{
        iconv_t cd;
        int rc;
        char **pin = &inbuf;
        char **pout = &outbuf;

        cd = iconv_open(to_charset,from_charset);
        if (cd==0)
                return -1;
        memset(outbuf,0,outlen);
        if (iconv(cd,pin,&inlen,pout,&outlen) == -1)
                return -1;
        iconv_close(cd);
        return 0;
}

int u2g(char *inbuf,int inlen,char *outbuf,int outlen)
{
        return code_convert("utf-8","gb2312",inbuf,inlen,outbuf,outlen);
}

int g2u(char *inbuf,size_t inlen,char *outbuf,size_t outlen)
{
      //  return code_convert("gb2312","utf-8",inbuf,inlen,outbuf,outlen);
      return code_convert("gbk","utf-8",inbuf,inlen,outbuf,outlen);
}

/*
 * 
 */
int main(int argc, char** argv) {

    return 0;
}

