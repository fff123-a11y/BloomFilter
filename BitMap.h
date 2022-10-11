#pragma once
#ifndef _BITMAP_H_
#define _BITMAP_H_

typedef  unsigned long  size_t;

typedef struct  HashBitMap
{
    size_t* _BitMap;
    size_t _size;
    size_t _capacity;
}BitMap, * pBitMap;


void InitBitMap(pBitMap bm, size_t size);
int InsertBitMap(pBitMap bm, size_t data);
int FindBitMap(pBitMap bm, size_t data);

void Set(pBitMap bm, size_t seat, size_t num);//比特位置1
void ReSet(pBitMap bm, size_t seat, size_t num);//比特位置0

size_t SizeBitMap(BitMap* bmp);
size_t CountBitMap(BitMap* bmp);
void DestroyBitMap(BitMap* bmp);


#endif//!_BITMAP_H_
