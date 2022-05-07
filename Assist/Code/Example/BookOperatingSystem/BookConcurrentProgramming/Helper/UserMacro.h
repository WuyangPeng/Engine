///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/26 23:05)

#ifndef BOOK_CONCURRENT_PROGRAMMING_MACRO_USER_MACRO_H
#define BOOK_CONCURRENT_PROGRAMMING_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define BOOK_CONCURRENT_PROGRAMMING_ClOSE_BEGIN (0x01)

#define CLOSE_USE_BOOK_CONCURRENT_PROGRAMMING (BOOK_CONCURRENT_PROGRAMMING_ClOSE_BEGIN)

#define BOOK_CONCURRENT_PROGRAMMING_ClOSE_END CLOSE_USE_BOOK_CONCURRENT_PROGRAMMING

#define CLOSE_BOOK_CONCURRENT_PROGRAMMING_MAX ((BOOK_CONCURRENT_PROGRAMMING_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_BOOK_CONCURRENT_PROGRAMMING_CLOSE 0x00

static_assert(0 <= COMPILE_BOOK_CONCURRENT_PROGRAMMING_CLOSE, "COMPILE_BOOK_CONCURRENT_PROGRAMMING_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BOOK_CONCURRENT_PROGRAMMING_CLOSE <= CLOSE_BOOK_CONCURRENT_PROGRAMMING_MAX, "COMPILE_BOOK_CONCURRENT_PROGRAMMING_CLOSE Must be less than or equal CLOSE_BOOK_CONCURRENT_PROGRAMMING_MAX.");

#if !defined(COMPILE_BOOK_CONCURRENT_PROGRAMMING_CLOSE) || (COMPILE_BOOK_CONCURRENT_PROGRAMMING_CLOSE & CLOSE_USE_BOOK_CONCURRENT_PROGRAMMING) != CLOSE_USE_BOOK_CONCURRENT_PROGRAMMING

#endif  // !defined(COMPILE_BOOK_CONCURRENT_PROGRAMMING_CLOSE) || (COMPILE_BOOK_CONCURRENT_PROGRAMMING_CLOSE & CLOSE_USE_BOOK_CONCURRENT_PROGRAMMING) != CLOSE_USE_BOOK_CONCURRENT_PROGRAMMING

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_BOOK_CONCURRENT_PROGRAMMING_STATIC
#endif  // BUILDING_STATIC

#endif  // BOOK_CONCURRENT_PROGRAMMING_MACRO_USER_MACRO_H