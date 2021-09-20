///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 21:32)

#ifndef A_TOUR_OF_CPP_HELPER_USER_MACRO_H
#define A_TOUR_OF_CPP_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define A_TOUR_OF_CPP_ClOSE_BEGIN (0x01)

#define CLOSE_USE_A_TOUR_OF_CPP (A_TOUR_OF_CPP_ClOSE_BEGIN)

#define A_TOUR_OF_CPP_ClOSE_END CLOSE_USE_A_TOUR_OF_CPP

#define CLOSE_A_TOUR_OF_CPP_MAX ((A_TOUR_OF_CPP_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_A_TOUR_OF_CPP_CLOSE 0x00

static_assert(0 <= COMPILE_A_TOUR_OF_CPP_CLOSE, "COMPILE_A_TOUR_OF_CPP_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_A_TOUR_OF_CPP_CLOSE <= CLOSE_A_TOUR_OF_CPP_MAX, "COMPILE_A_TOUR_OF_CPP_CLOSE Must be less than or equal CLOSE_A_TOUR_OF_CPP_MAX.");

#if !defined(COMPILE_A_TOUR_OF_CPP_CLOSE) || (COMPILE_A_TOUR_OF_CPP_CLOSE & CLOSE_USE_A_TOUR_OF_CPP) != CLOSE_USE_A_TOUR_OF_CPP

#endif  // !defined(COMPILE_A_TOUR_OF_CPP_CLOSE) || (COMPILE_A_TOUR_OF_CPP_CLOSE & CLOSE_USE_A_TOUR_OF_CPP) != CLOSE_USE_A_TOUR_OF_CPP

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_A_TOUR_OF_CPP_STATIC
#endif  // BUILDING_STATIC

#endif  // A_TOUR_OF_CPP_HELPER_USER_MACRO_H
