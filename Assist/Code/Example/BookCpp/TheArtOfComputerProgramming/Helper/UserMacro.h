///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:03)

#ifndef THE_ART_OF_COMPUTER_PROGRAMMING_HELPER_USER_MACRO_H
#define THE_ART_OF_COMPUTER_PROGRAMMING_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define THE_ART_OF_COMPUTER_PROGRAMMING_ClOSE_BEGIN (0x01)

#define CLOSE_USE_THE_ART_OF_COMPUTER_PROGRAMMING (THE_ART_OF_COMPUTER_PROGRAMMING_ClOSE_BEGIN)

#define THE_ART_OF_COMPUTER_PROGRAMMING_ClOSE_END CLOSE_USE_THE_ART_OF_COMPUTER_PROGRAMMING

#define CLOSE_THE_ART_OF_COMPUTER_PROGRAMMING_MAX ((THE_ART_OF_COMPUTER_PROGRAMMING_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_THE_ART_OF_COMPUTER_PROGRAMMING_CLOSE 0x00

static_assert(0 <= COMPILE_THE_ART_OF_COMPUTER_PROGRAMMING_CLOSE, "COMPILE_THE_ART_OF_COMPUTER_PROGRAMMING_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_THE_ART_OF_COMPUTER_PROGRAMMING_CLOSE <= CLOSE_THE_ART_OF_COMPUTER_PROGRAMMING_MAX, "COMPILE_THE_ART_OF_COMPUTER_PROGRAMMING_CLOSE Must be less than or equal CLOSE_THE_ART_OF_COMPUTER_PROGRAMMING_MAX.");

#if !defined(COMPILE_THE_ART_OF_COMPUTER_PROGRAMMING_CLOSE) || (COMPILE_THE_ART_OF_COMPUTER_PROGRAMMING_CLOSE & CLOSE_USE_THE_ART_OF_COMPUTER_PROGRAMMING) != CLOSE_USE_THE_ART_OF_COMPUTER_PROGRAMMING

#endif  // !defined(COMPILE_THE_ART_OF_COMPUTER_PROGRAMMING_CLOSE) || (COMPILE_THE_ART_OF_COMPUTER_PROGRAMMING_CLOSE & CLOSE_USE_THE_ART_OF_COMPUTER_PROGRAMMING) != CLOSE_USE_THE_ART_OF_COMPUTER_PROGRAMMING

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_THE_ART_OF_COMPUTER_PROGRAMMING_STATIC
#endif  // BUILDING_STATIC

#endif  // THE_ART_OF_COMPUTER_PROGRAMMING_HELPER_USER_MACRO_H