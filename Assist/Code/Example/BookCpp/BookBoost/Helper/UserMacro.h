///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/21 19:19)

#ifndef BOOK_BOOST_HELPER_USER_MACRO_H
#define BOOK_BOOST_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define BOOK_BOOST_ClOSE_BEGIN (0x01)

#define CLOSE_USE_BOOK_BOOST (BOOK_BOOST_ClOSE_BEGIN)

#define BOOK_BOOST_ClOSE_END CLOSE_USE_BOOK_BOOST

#define CLOSE_BOOK_BOOST_MAX ((BOOK_BOOST_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_BOOK_BOOST_CLOSE 0x00

static_assert(0 <= COMPILE_BOOK_BOOST_CLOSE, "COMPILE_BOOK_BOOST_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BOOK_BOOST_CLOSE <= CLOSE_BOOK_BOOST_MAX, "COMPILE_BOOK_BOOST_CLOSE Must be less than or equal CLOSE_BOOK_BOOST_MAX.");

#if !defined(COMPILE_BOOK_BOOST_CLOSE) || (COMPILE_BOOK_BOOST_CLOSE & CLOSE_USE_BOOK_BOOST) != CLOSE_USE_BOOK_BOOST

#endif  // !defined(COMPILE_BOOK_BOOST_CLOSE) || (COMPILE_BOOK_BOOST_CLOSE & CLOSE_USE_BOOK_BOOST) != CLOSE_USE_BOOK_BOOST

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_BOOK_BOOST_STATIC
#endif  // BUILDING_STATIC

#endif  // BOOK_BOOST_HELPER_USER_MACRO_H
