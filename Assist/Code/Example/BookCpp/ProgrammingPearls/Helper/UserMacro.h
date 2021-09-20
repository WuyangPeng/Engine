///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:03)

#ifndef PROGRAMMING_PEARLS_HELPER_USER_MACRO_H
#define PROGRAMMING_PEARLS_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define PROGRAMMING_PEARLS_ClOSE_BEGIN (0x01)

#define CLOSE_USE_PROGRAMMING_PEARLS (PROGRAMMING_PEARLS_ClOSE_BEGIN)

#define PROGRAMMING_PEARLS_ClOSE_END CLOSE_USE_PROGRAMMING_PEARLS

#define CLOSE_PROGRAMMING_PEARLS_MAX ((PROGRAMMING_PEARLS_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_PROGRAMMING_PEARLS_CLOSE 0x00

static_assert(0 <= COMPILE_PROGRAMMING_PEARLS_CLOSE, "COMPILE_PROGRAMMING_PEARLS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_PROGRAMMING_PEARLS_CLOSE <= CLOSE_PROGRAMMING_PEARLS_MAX, "COMPILE_PROGRAMMING_PEARLS_CLOSE Must be less than or equal CLOSE_PROGRAMMING_PEARLS_MAX.");

#if !defined(COMPILE_PROGRAMMING_PEARLS_CLOSE) || (COMPILE_PROGRAMMING_PEARLS_CLOSE & CLOSE_USE_PROGRAMMING_PEARLS) != CLOSE_USE_PROGRAMMING_PEARLS

#endif  // !defined(COMPILE_PROGRAMMING_PEARLS_CLOSE) || (COMPILE_PROGRAMMING_PEARLS_CLOSE & CLOSE_USE_PROGRAMMING_PEARLS) != CLOSE_USE_PROGRAMMING_PEARLS

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_PROGRAMMING_PEARLS_STATIC
#endif  // BUILDING_STATIC

#endif  // PROGRAMMING_PEARLS_HELPER_USER_MACRO_H