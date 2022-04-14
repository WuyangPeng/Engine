///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/25 21:03)

#ifndef RESOURCE_MANAGER_MACRO_USER_MACRO_H
#define RESOURCE_MANAGER_MACRO_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_X (0x01)
#define CLOSE_RESOURCE_MANAGER_MAX (((CLOSE_USE_X) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_RESOURCE_MANAGER_CLOSE 0x00

static_assert(0 <= COMPILE_RESOURCE_MANAGER_CLOSE, "COMPILE_RESOURCE_MANAGER_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_RESOURCE_MANAGER_CLOSE <= CLOSE_RESOURCE_MANAGER_MAX, "COMPILE_RESOURCE_MANAGER_CLOSE Must be less than or equal CLOSE_RESOURCE_MANAGER_MAX.");

#if !defined(COMPILE_RESOURCE_MANAGER_CLOSE) || (COMPILE_RESOURCE_MANAGER_CLOSE & CLOSE_USE_X) != CLOSE_USE_X
    #define RESOURCE_MANAGER_USE_X
#endif  // !defined(COMPILE_RESOURCE_MANAGER_CLOSE) || (COMPILE_RESOURCE_MANAGER_CLOSE & CLOSE_USE_X) != CLOSE_USE_X

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_RESOURCE_MANAGER_STATIC
#endif  // BUILDING_STATIC

#endif  // RESOURCE_MANAGER_MACRO_USER_MACRO_H
