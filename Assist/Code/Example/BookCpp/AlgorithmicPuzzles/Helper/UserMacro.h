///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/28 12:58)

#ifndef ALGORITHMIC_PUZZLES_HELPER_USER_MACRO_H
#define ALGORITHMIC_PUZZLES_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define ALGORITHMIC_PUZZLES_ClOSE_BEGIN (0x01)

#define CLOSE_USE_ALGORITHMIC_PUZZLES (ALGORITHMIC_PUZZLES_ClOSE_BEGIN)

#define ALGORITHMIC_PUZZLES_ClOSE_END CLOSE_USE_ALGORITHMIC_PUZZLES

#define CLOSE_ALGORITHMIC_PUZZLES_MAX ((ALGORITHMIC_PUZZLES_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_ALGORITHMIC_PUZZLES_CLOSE 0x00

static_assert(0 <= COMPILE_ALGORITHMIC_PUZZLES_CLOSE, "COMPILE_ALGORITHMIC_PUZZLES_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ALGORITHMIC_PUZZLES_CLOSE <= CLOSE_ALGORITHMIC_PUZZLES_MAX, "COMPILE_ALGORITHMIC_PUZZLES_CLOSE Must be less than or equal CLOSE_ALGORITHMIC_PUZZLES_MAX.");

#if !defined(COMPILE_ALGORITHMIC_PUZZLES_CLOSE) || (COMPILE_ALGORITHMIC_PUZZLES_CLOSE & CLOSE_USE_ALGORITHMIC_PUZZLES) != CLOSE_USE_ALGORITHMIC_PUZZLES

#endif  // !defined(COMPILE_ALGORITHMIC_PUZZLES_CLOSE) || (COMPILE_ALGORITHMIC_PUZZLES_CLOSE & CLOSE_USE_ALGORITHMIC_PUZZLES) != CLOSE_USE_ALGORITHMIC_PUZZLES

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_ALGORITHMIC_PUZZLES_STATIC
#endif  // BUILDING_STATIC

#endif  // ALGORITHMIC_PUZZLES_HELPER_USER_MACRO_H