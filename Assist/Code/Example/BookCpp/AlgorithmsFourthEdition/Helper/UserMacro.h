///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/07 0:27)

#ifndef ALGORITHMS_FOURTH_EDITION_HELPER_USER_MACRO_H
#define ALGORITHMS_FOURTH_EDITION_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define ALGORITHMS_FOURTH_EDITION_ClOSE_BEGIN (0x01)

#define CLOSE_USE_ALGORITHMS_FOURTH_EDITION (ALGORITHMS_FOURTH_EDITION_ClOSE_BEGIN)

#define ALGORITHMS_FOURTH_EDITION_ClOSE_END CLOSE_USE_ALGORITHMS_FOURTH_EDITION

#define CLOSE_ALGORITHMS_FOURTH_EDITION_MAX ((ALGORITHMS_FOURTH_EDITION_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_ALGORITHMS_FOURTH_EDITION_CLOSE 0x00

static_assert(0 <= COMPILE_ALGORITHMS_FOURTH_EDITION_CLOSE, "COMPILE_ALGORITHMS_FOURTH_EDITION_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ALGORITHMS_FOURTH_EDITION_CLOSE <= CLOSE_ALGORITHMS_FOURTH_EDITION_MAX, "COMPILE_ALGORITHMS_FOURTH_EDITION_CLOSE Must be less than or equal CLOSE_ALGORITHMS_FOURTH_EDITION_MAX.");

#if !defined(COMPILE_ALGORITHMS_FOURTH_EDITION_CLOSE) || (COMPILE_ALGORITHMS_FOURTH_EDITION_CLOSE & CLOSE_USE_ALGORITHMS_FOURTH_EDITION) != CLOSE_USE_ALGORITHMS_FOURTH_EDITION

#endif  // !defined(COMPILE_ALGORITHMS_FOURTH_EDITION_CLOSE) || (COMPILE_ALGORITHMS_FOURTH_EDITION_CLOSE & CLOSE_USE_ALGORITHMS_FOURTH_EDITION) != CLOSE_USE_ALGORITHMS_FOURTH_EDITION

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC
#endif  // BUILDING_STATIC

#endif  // ALGORITHMS_FOURTH_EDITION_HELPER_USER_MACRO_H