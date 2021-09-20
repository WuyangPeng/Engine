///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef DATA_STRUCTURES_WITH_CPP_USING_STL_HELPER_USER_MACRO_H
#define DATA_STRUCTURES_WITH_CPP_USING_STL_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define DATA_STRUCTURES_WITH_CPP_USING_STL_ClOSE_BEGIN (0x01)

#define CLOSE_USE_DATA_STRUCTURES_WITH_CPP_USING_STL (DATA_STRUCTURES_WITH_CPP_USING_STL_ClOSE_BEGIN)

#define DATA_STRUCTURES_WITH_CPP_USING_STL_ClOSE_END CLOSE_USE_DATA_STRUCTURES_WITH_CPP_USING_STL

#define CLOSE_DATA_STRUCTURES_WITH_CPP_USING_STL_MAX ((DATA_STRUCTURES_WITH_CPP_USING_STL_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_DATA_STRUCTURES_WITH_CPP_USING_STL_CLOSE 0x00

static_assert(0 <= COMPILE_DATA_STRUCTURES_WITH_CPP_USING_STL_CLOSE, "COMPILE_DATA_STRUCTURES_WITH_CPP_USING_STL_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_DATA_STRUCTURES_WITH_CPP_USING_STL_CLOSE <= CLOSE_DATA_STRUCTURES_WITH_CPP_USING_STL_MAX, "COMPILE_DATA_STRUCTURES_WITH_CPP_USING_STL_CLOSE Must be less than or equal CLOSE_DATA_STRUCTURES_WITH_CPP_USING_STL_MAX.");

#if !defined(COMPILE_DATA_STRUCTURES_WITH_CPP_USING_STL_CLOSE) || (COMPILE_DATA_STRUCTURES_WITH_CPP_USING_STL_CLOSE & CLOSE_USE_DATA_STRUCTURES_WITH_CPP_USING_STL) != CLOSE_USE_DATA_STRUCTURES_WITH_CPP_USING_STL

#endif  // !defined(COMPILE_DATA_STRUCTURES_WITH_CPP_USING_STL_CLOSE) || (COMPILE_DATA_STRUCTURES_WITH_CPP_USING_STL_CLOSE & CLOSE_USE_DATA_STRUCTURES_WITH_CPP_USING_STL) != CLOSE_USE_DATA_STRUCTURES_WITH_CPP_USING_STL

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_DATA_STRUCTURES_WITH_CPP_USING_STL_STATIC
#endif  // BUILDING_STATIC

#endif  // DATA_STRUCTURES_WITH_CPP_USING_STL_HELPER_USER_MACRO_H