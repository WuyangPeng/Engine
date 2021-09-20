///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/15 23:52)

#ifndef BOOK_EXPERIENCE_HELPER_USER_MACRO_H
#define BOOK_EXPERIENCE_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define BOOK_EXPERIENCE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_BOOK_EXPERIENCE (BOOK_EXPERIENCE_ClOSE_BEGIN)

#define BOOK_EXPERIENCE_ClOSE_END CLOSE_USE_BOOK_EXPERIENCE

#define CLOSE_BOOK_EXPERIENCE_MAX ((BOOK_EXPERIENCE_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_BOOK_EXPERIENCE_CLOSE 0x00

static_assert(0 <= COMPILE_BOOK_EXPERIENCE_CLOSE, "COMPILE_BOOK_EXPERIENCE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BOOK_EXPERIENCE_CLOSE <= CLOSE_BOOK_EXPERIENCE_MAX, "COMPILE_BOOK_EXPERIENCE_CLOSE Must be less than or equal CLOSE_BOOK_EXPERIENCE_MAX.");

#if !defined(COMPILE_BOOK_EXPERIENCE_CLOSE) || (COMPILE_BOOK_EXPERIENCE_CLOSE & CLOSE_USE_BOOK_EXPERIENCE) != CLOSE_USE_BOOK_EXPERIENCE

#endif  // !defined(COMPILE_BOOK_EXPERIENCE_CLOSE) || (COMPILE_BOOK_EXPERIENCE_CLOSE & CLOSE_USE_BOOK_EXPERIENCE) != CLOSE_USE_BOOK_EXPERIENCE

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_BOOK_EXPERIENCE_STATIC
#endif  // BUILDING_STATIC

#endif  // BOOK_EXPERIENCE_HELPER_USER_MACRO_H
