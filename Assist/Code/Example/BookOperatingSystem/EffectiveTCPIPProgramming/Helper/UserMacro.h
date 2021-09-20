///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/27 22:22)

#ifndef EFFECTIVE_TCP_IP_PROGRAMMING_HELPER_USER_MACRO_H
#define EFFECTIVE_TCP_IP_PROGRAMMING_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define EFFECTIVE_TCP_IP_PROGRAMMING_ClOSE_BEGIN (0x01)

#define CLOSE_USE_EFFECTIVE_TCP_IP_PROGRAMMING (EFFECTIVE_TCP_IP_PROGRAMMING_ClOSE_BEGIN)

#define EFFECTIVE_TCP_IP_PROGRAMMING_ClOSE_END CLOSE_USE_EFFECTIVE_TCP_IP_PROGRAMMING

#define CLOSE_EFFECTIVE_TCP_IP_PROGRAMMING_MAX ((EFFECTIVE_TCP_IP_PROGRAMMING_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_EFFECTIVE_TCP_IP_PROGRAMMING_CLOSE 0x00

static_assert(0 <= COMPILE_EFFECTIVE_TCP_IP_PROGRAMMING_CLOSE, "COMPILE_EFFECTIVE_TCP_IP_PROGRAMMING_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_EFFECTIVE_TCP_IP_PROGRAMMING_CLOSE <= CLOSE_EFFECTIVE_TCP_IP_PROGRAMMING_MAX, "COMPILE_EFFECTIVE_TCP_IP_PROGRAMMING_CLOSE Must be less than or equal CLOSE_EFFECTIVE_TCP_IP_PROGRAMMING_MAX.");

#if !defined(COMPILE_EFFECTIVE_TCP_IP_PROGRAMMING_CLOSE) || (COMPILE_EFFECTIVE_TCP_IP_PROGRAMMING_CLOSE & CLOSE_USE_EFFECTIVE_TCP_IP_PROGRAMMING) != CLOSE_USE_EFFECTIVE_TCP_IP_PROGRAMMING

#endif  // !defined(COMPILE_EFFECTIVE_TCP_IP_PROGRAMMING_CLOSE) || (COMPILE_EFFECTIVE_TCP_IP_PROGRAMMING_CLOSE & CLOSE_USE_EFFECTIVE_TCP_IP_PROGRAMMING) != CLOSE_USE_EFFECTIVE_TCP_IP_PROGRAMMING

#ifdef BUILDING_STATIC
    #define BUILDING_EFFECTIVE_TCP_IP_PROGRAMMING_STATIC
#endif  // BUILDING_STATIC

#endif  // EFFECTIVE_TCP_IP_PROGRAMMING_HELPER_USER_MACRO_H