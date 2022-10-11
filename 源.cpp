#include "bloomfilter.h"
#include <stdio.h>
#include <time.h>

#define MAX_ITEMS 	100000000      // 设置最大元素
#define P_ERROR 	0.0000001       // 设置误差


int main(int argc, char** argv)
{
    // 1. 定义BaseBloomFilter
    static BaseBloomFilter filter = { 0 };

    // 2. 初始化filter，调用时传入hash种子，存储容量，以及允许的误判率
    InitBloomFilter(&filter, 0, MAX_ITEMS, P_ERROR);

    // 3. 向BloomFilter中新增数值
    unsigned long time0 = time(NULL);
    printf("开始加载...\n");
    char url[128] = "";
    int n = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        sprintf(url, "https://www.github.com/%d.html", i + 1);
        if (BloomFilter_Add(&filter, (const void*)url, strlen(url))) {
            printf("add %s failed\n", url);
        }

        if ((i + 1) % 1000000 == 0) {
            printf("had loaded %d W\n", ++n * 100);
        }
    }

    unsigned long time1 = time(NULL);
    printf("数据已经加载完成, 耗时 %d s.\n", time1 - time0);

    printf("开始搜索...\n");
    char* str = "https://www.github.com/100000000.html";
    if (BloomFilter_Check(&filter, (const void*)str, strlen(str))) {
        printf("没有找到：%s\n", str);
    }
    else {
        printf("找到：%s\n", str);
    }

    unsigned long time2 = time(NULL);
    printf("搜索结束.耗时 %d s.\n", time2 - time1);

    // free bloomfilter
    FreeBloomFilter(&filter);
    getchar();
    return 0;
}
