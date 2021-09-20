///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:53)

#ifndef BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_HELPER_USER_MACRO_H
#define BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_ClOSE_BEGIN (0x01)

#define CLOSE_USE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST (BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_ClOSE_BEGIN)

#define BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_ClOSE_END CLOSE_USE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST

#define CLOSE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_MAX ((BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_CLOSE 0x00

static_assert(0 <= COMPILE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_CLOSE, "COMPILE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_CLOSE <= CLOSE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_MAX, "COMPILE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_CLOSE Must be less than or equal CLOSE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_MAX.");

#if !defined(COMPILE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_CLOSE) || (COMPILE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_CLOSE & CLOSE_USE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST) != CLOSE_USE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST

#endif  // !defined(COMPILE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_CLOSE) || (COMPILE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_CLOSE & CLOSE_USE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST) != CLOSE_USE_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_STATIC
#endif  // BUILDING_STATIC

#endif  // BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_HELPER_USER_MACRO_H
