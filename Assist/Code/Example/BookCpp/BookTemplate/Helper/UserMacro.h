///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/06 23:43)

#ifndef BOOK_TEMPLATE_HELPER_USER_MACRO_H
#define BOOK_TEMPLATE_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define BOOK_TEMPLATE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_BOOK_TEMPLATE (BOOK_TEMPLATE_ClOSE_BEGIN)

#define BOOK_TEMPLATE_ClOSE_END CLOSE_USE_BOOK_TEMPLATE

#define CLOSE_BOOK_TEMPLATE_MAX ((BOOK_TEMPLATE_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_BOOK_TEMPLATE_CLOSE 0x00

static_assert(0 <= COMPILE_BOOK_TEMPLATE_CLOSE, "COMPILE_BOOK_TEMPLATE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BOOK_TEMPLATE_CLOSE <= CLOSE_BOOK_TEMPLATE_MAX, "COMPILE_BOOK_TEMPLATE_CLOSE Must be less than or equal CLOSE_BOOK_TEMPLATE_MAX.");

#if !defined(COMPILE_BOOK_TEMPLATE_CLOSE) || (COMPILE_BOOK_TEMPLATE_CLOSE & CLOSE_USE_BOOK_TEMPLATE) != CLOSE_USE_BOOK_TEMPLATE

#endif  // !defined(COMPILE_BOOK_TEMPLATE_CLOSE) || (COMPILE_BOOK_TEMPLATE_CLOSE & CLOSE_USE_BOOK_TEMPLATE) != CLOSE_USE_BOOK_TEMPLATE

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_BOOK_TEMPLATE_STATIC
#endif  // BUILDING_STATIC

#endif  // BOOK_TEMPLATE_HELPER_USER_MACRO_H