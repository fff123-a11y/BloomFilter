#pragma once

#ifndef _COMMON_H_
#define _COMMON_H_

#define size_t unsigned long 

size_t BKDRHash(const char* str);

size_t SDBMHash(const char* str);

size_t RSHash(const char* str);

size_t APHash(const char* str);

size_t JSHash(const char* str);



#endif //!_COMMON_H_
