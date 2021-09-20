///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/04/24 20:49)

#ifndef BOOK_OPERATING_SYSTEM_HELPER_USER_MACRO_H
#define BOOK_OPERATING_SYSTEM_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define BOOK_OPERATING_SYSTEM_ClOSE_BEGIN (0x01)

#define CLOSE_USE_BOOK_OPERATING_SYSTEM (BOOK_OPERATING_SYSTEM_ClOSE_BEGIN)

#define BOOK_OPERATING_SYSTEM_ClOSE_END CLOSE_USE_BOOK_OPERATING_SYSTEM

#define CLOSE_BOOK_OPERATING_SYSTEM_MAX ((BOOK_OPERATING_SYSTEM_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_BOOK_OPERATING_SYSTEM_CLOSE 0x00

static_assert(0 <= COMPILE_BOOK_OPERATING_SYSTEM_CLOSE, "COMPILE_BOOK_OPERATING_SYSTEM_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BOOK_OPERATING_SYSTEM_CLOSE <= CLOSE_BOOK_OPERATING_SYSTEM_MAX, "COMPILE_BOOK_OPERATING_SYSTEM_CLOSE Must be less than or equal CLOSE_BOOK_OPERATING_SYSTEM_MAX.");

#if !defined(COMPILE_BOOK_OPERATING_SYSTEM_CLOSE) || (COMPILE_BOOK_OPERATING_SYSTEM_CLOSE & CLOSE_USE_BOOK_OPERATING_SYSTEM) != CLOSE_USE_BOOK_OPERATING_SYSTEM

#endif  // !defined(COMPILE_BOOK_OPERATING_SYSTEM_CLOSE) || (COMPILE_BOOK_OPERATING_SYSTEM_CLOSE & CLOSE_USE_BOOK_OPERATING_SYSTEM) != CLOSE_USE_BOOK_OPERATING_SYSTEM

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_BOOK_OPERATING_SYSTEM_STATIC static_cast<void>(0)
#endif  // BUILDING_STATIC

#endif  // BOOK_OPERATING_SYSTEM_HELPER_USER_MACRO_H