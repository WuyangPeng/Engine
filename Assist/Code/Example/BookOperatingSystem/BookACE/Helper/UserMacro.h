///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/04/29 22:23)

#ifndef BOOK_ACE_MACRO_USER_MACRO_H
#define BOOK_ACE_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define BOOK_ACE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_BOOK_ACE (BOOK_ACE_ClOSE_BEGIN)

#define BOOK_ACE_ClOSE_END CLOSE_USE_BOOK_ACE

#define CLOSE_BOOK_ACE_MAX ((BOOK_ACE_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_BOOK_ACE_CLOSE 0x00

static_assert(0 <= COMPILE_BOOK_ACE_CLOSE, "COMPILE_BOOK_ACE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BOOK_ACE_CLOSE <= CLOSE_BOOK_ACE_MAX, "COMPILE_BOOK_ACE_CLOSE Must be less than or equal CLOSE_BOOK_ACE_MAX.");

#if !defined(COMPILE_BOOK_ACE_CLOSE) || (COMPILE_BOOK_ACE_CLOSE & CLOSE_USE_BOOK_ACE) != CLOSE_USE_BOOK_ACE

#endif  // !defined(COMPILE_BOOK_ACE_CLOSE) || (COMPILE_BOOK_ACE_CLOSE & CLOSE_USE_BOOK_ACE) != CLOSE_USE_BOOK_ACE

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_BOOK_ACE_STATIC
#endif  // BUILDING_STATIC

#endif  // BOOK_ACE_MACRO_USER_MACRO_H
