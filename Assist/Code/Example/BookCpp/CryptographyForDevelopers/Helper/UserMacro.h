///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:03)

#ifndef CRYPTOGRAPHY_FOR_DEVELOPERS_HELPER_USER_MACRO_H
#define CRYPTOGRAPHY_FOR_DEVELOPERS_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CRYPTOGRAPHY_FOR_DEVELOPERS_ClOSE_BEGIN (0x01)

#define CLOSE_USE_CRYPTOGRAPHY_FOR_DEVELOPERS (CRYPTOGRAPHY_FOR_DEVELOPERS_ClOSE_BEGIN)

#define CRYPTOGRAPHY_FOR_DEVELOPERS_ClOSE_END CLOSE_USE_CRYPTOGRAPHY_FOR_DEVELOPERS

#define CLOSE_CRYPTOGRAPHY_FOR_DEVELOPERS_MAX ((CRYPTOGRAPHY_FOR_DEVELOPERS_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_CRYPTOGRAPHY_FOR_DEVELOPERS_CLOSE 0x00

static_assert(0 <= COMPILE_CRYPTOGRAPHY_FOR_DEVELOPERS_CLOSE, "COMPILE_CRYPTOGRAPHY_FOR_DEVELOPERS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CRYPTOGRAPHY_FOR_DEVELOPERS_CLOSE <= CLOSE_CRYPTOGRAPHY_FOR_DEVELOPERS_MAX, "COMPILE_CRYPTOGRAPHY_FOR_DEVELOPERS_CLOSE Must be less than or equal CLOSE_CRYPTOGRAPHY_FOR_DEVELOPERS_MAX.");

#if !defined(COMPILE_CRYPTOGRAPHY_FOR_DEVELOPERS_CLOSE) || (COMPILE_CRYPTOGRAPHY_FOR_DEVELOPERS_CLOSE & CLOSE_USE_CRYPTOGRAPHY_FOR_DEVELOPERS) != CLOSE_USE_CRYPTOGRAPHY_FOR_DEVELOPERS

#endif  // !defined(COMPILE_CRYPTOGRAPHY_FOR_DEVELOPERS_CLOSE) || (COMPILE_CRYPTOGRAPHY_FOR_DEVELOPERS_CLOSE & CLOSE_USE_CRYPTOGRAPHY_FOR_DEVELOPERS) != CLOSE_USE_CRYPTOGRAPHY_FOR_DEVELOPERS

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_CRYPTOGRAPHY_FOR_DEVELOPERS_STATIC
#endif  // BUILDING_STATIC

#endif  // CRYPTOGRAPHY_FOR_DEVELOPERS_HELPER_USER_MACRO_H
