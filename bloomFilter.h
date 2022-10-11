#pragma once
#ifndef  _BLOOMFILTER_H_
#define  _BLOOMFILRR_H_

#include"BitMap.h"
#include"Common.h"

typedef char* DataType;
typedef size_t(*PHF)(DataType);
#define FUNCNUM 5 


typedef struct BloomFilter
{
    BitMap _bmp;
    PHF _HashFunc[FUNCNUM];
    size_t _size;
}BF;

void InitBloomFilter(BF* bf, PHF hashFunc[FUNCNUM], size_t size);
int InsertBF(BF* bf, DataType key);
int IsInBloomFilter(BF* bf, DataType key);
void DestroyBloomFilter(BF* bf);

#endif // ! _BLOOMFILTE
