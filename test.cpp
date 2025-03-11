typedef unsigned int __u32;
#define v4l2_fourcc(a, b, c, d) \
    ((__u32)(a) | ((__u32)(b) << 8) | ((__u32)(c) << 16) | ((__u32)(d) << 24))
#define V4L2_PIX_FMT_YUV10 v4l2_fourcc('Y', 'U', 'V', 'A') /* 20  YUV422 10bit  */
int main()
{
    int a = V4L2_PIX_FMT_YUV10;
}