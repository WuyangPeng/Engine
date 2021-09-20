///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef HOW_TO_SOLVE_HELPER_USER_MACRO_H
#define HOW_TO_SOLVE_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define HOW_TO_SOLVE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_HOW_TO_SOLVE (HOW_TO_SOLVE_ClOSE_BEGIN)

#define HOW_TO_SOLVE_ClOSE_END CLOSE_USE_HOW_TO_SOLVE

#define CLOSE_HOW_TO_SOLVE_MAX ((HOW_TO_SOLVE_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_HOW_TO_SOLVE_CLOSE 0x00

static_assert(0 <= COMPILE_HOW_TO_SOLVE_CLOSE, "COMPILE_HOW_TO_SOLVE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_HOW_TO_SOLVE_CLOSE <= CLOSE_HOW_TO_SOLVE_MAX, "COMPILE_HOW_TO_SOLVE_CLOSE Must be less than or equal CLOSE_HOW_TO_SOLVE_MAX.");

#if !defined(COMPILE_HOW_TO_SOLVE_CLOSE) || (COMPILE_HOW_TO_SOLVE_CLOSE & CLOSE_USE_HOW_TO_SOLVE) != CLOSE_USE_HOW_TO_SOLVE

#endif  // !defined(COMPILE_HOW_TO_SOLVE_CLOSE) || (COMPILE_HOW_TO_SOLVE_CLOSE & CLOSE_USE_HOW_TO_SOLVE) != CLOSE_USE_HOW_TO_SOLVE

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_HOW_TO_SOLVE_STATIC
#endif  // BUILDING_STATIC

#endif  // HOW_TO_SOLVE_HELPER_USER_MACRO_H
