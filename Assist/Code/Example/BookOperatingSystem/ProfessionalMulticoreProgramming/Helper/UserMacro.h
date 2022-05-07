///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/28 22:20)

#ifndef PROFESSIONAL_MULTICORE_PROGRAMMING_HELPER_USER_MACRO_H
#define PROFESSIONAL_MULTICORE_PROGRAMMING_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define PROFESSIONAL_MULTICORE_PROGRAMMING_ClOSE_BEGIN (0x01)

#define CLOSE_USE_PROFESSIONAL_MULTICORE_PROGRAMMING (PROFESSIONAL_MULTICORE_PROGRAMMING_ClOSE_BEGIN)

#define PROFESSIONAL_MULTICORE_PROGRAMMING_ClOSE_END CLOSE_USE_PROFESSIONAL_MULTICORE_PROGRAMMING

#define CLOSE_PROFESSIONAL_MULTICORE_PROGRAMMING_MAX ((PROFESSIONAL_MULTICORE_PROGRAMMING_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_PROFESSIONAL_MULTICORE_PROGRAMMING_CLOSE 0x00

static_assert(0 <= COMPILE_PROFESSIONAL_MULTICORE_PROGRAMMING_CLOSE, "COMPILE_PROFESSIONAL_MULTICORE_PROGRAMMING_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_PROFESSIONAL_MULTICORE_PROGRAMMING_CLOSE <= CLOSE_PROFESSIONAL_MULTICORE_PROGRAMMING_MAX, "COMPILE_PROFESSIONAL_MULTICORE_PROGRAMMING_CLOSE Must be less than or equal CLOSE_PROFESSIONAL_MULTICORE_PROGRAMMING_MAX.");

#if !defined(COMPILE_PROFESSIONAL_MULTICORE_PROGRAMMING_CLOSE) || (COMPILE_PROFESSIONAL_MULTICORE_PROGRAMMING_CLOSE & CLOSE_USE_PROFESSIONAL_MULTICORE_PROGRAMMING) != CLOSE_USE_PROFESSIONAL_MULTICORE_PROGRAMMING

#endif  // !defined(COMPILE_PROFESSIONAL_MULTICORE_PROGRAMMING_CLOSE) || (COMPILE_PROFESSIONAL_MULTICORE_PROGRAMMING_CLOSE & CLOSE_USE_PROFESSIONAL_MULTICORE_PROGRAMMING) != CLOSE_USE_PROFESSIONAL_MULTICORE_PROGRAMMING

#ifdef BUILDING_STATIC
    #define BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC
#endif  // BUILDING_STATIC

#endif  // PROFESSIONAL_MULTICORE_PROGRAMMING_HELPER_USER_MACRO_H