///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef GROKKING_ALGORITHMS_HELPER_USER_MACRO_H
#define GROKKING_ALGORITHMS_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define GROKKING_ALGORITHMS_ClOSE_BEGIN (0x01)

#define CLOSE_USE_GROKKING_ALGORITHMS (GROKKING_ALGORITHMS_ClOSE_BEGIN)

#define GROKKING_ALGORITHMS_ClOSE_END CLOSE_USE_GROKKING_ALGORITHMS

#define CLOSE_GROKKING_ALGORITHMS_MAX ((GROKKING_ALGORITHMS_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_GROKKING_ALGORITHMS_CLOSE 0x00

static_assert(0 <= COMPILE_GROKKING_ALGORITHMS_CLOSE, "COMPILE_GROKKING_ALGORITHMS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_GROKKING_ALGORITHMS_CLOSE <= CLOSE_GROKKING_ALGORITHMS_MAX, "COMPILE_GROKKING_ALGORITHMS_CLOSE Must be less than or equal CLOSE_GROKKING_ALGORITHMS_MAX.");

#if !defined(COMPILE_GROKKING_ALGORITHMS_CLOSE) || (COMPILE_GROKKING_ALGORITHMS_CLOSE & CLOSE_USE_GROKKING_ALGORITHMS) != CLOSE_USE_GROKKING_ALGORITHMS

#endif  // !defined(COMPILE_GROKKING_ALGORITHMS_CLOSE) || (COMPILE_GROKKING_ALGORITHMS_CLOSE & CLOSE_USE_GROKKING_ALGORITHMS) != CLOSE_USE_GROKKING_ALGORITHMS

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_GROKKING_ALGORITHMS_STATIC
#endif  // BUILDING_STATIC

#endif  // GROKKING_ALGORITHMS_HELPER_USER_MACRO_H