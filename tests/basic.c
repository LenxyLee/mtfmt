// SPDX-License-Identifier: LGPL-3.0
/**
 * @file    basic.c
 * @author  向阳 (hinata.hoshino@foxmail.com)
 * @brief   基本测试
 * @version 1.0
 * @date    2023-05-28
 *
 * @copyright Copyright (c) 向阳, all rights reserved.
 *
 */
#include "mm_heap.h"
#include "unity.h"
#include <stddef.h>
#include <stdio.h>

void setUp(void)
{
#if !_MSTR_USE_MALLOC
    mheap_init();
#endif
}

void tearDown(void)
{
}

void allocate_then_free()
{
    void* p = mstr_heap_alloc(256);
    TEST_ASSERT_TRUE(p != NULL);
    mstr_heap_free(p);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(allocate_then_free);
    return UNITY_END();
}
