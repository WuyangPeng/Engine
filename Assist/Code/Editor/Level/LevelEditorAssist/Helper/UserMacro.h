///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 15:07)

#ifndef LEVEL_EDITOR_MACRO_USER_MACRO_H
#define LEVEL_EDITOR_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define LEVEL_EDITOR_ClOSE_BEGIN (0x01)

#define CLOSE_USE_LEVEL_EDITOR (LEVEL_EDITOR_ClOSE_BEGIN)

#define LEVEL_EDITOR_ClOSE_END CLOSE_USE_LEVEL_EDITOR

#define CLOSE_LEVEL_EDITOR_MAX (((LEVEL_EDITOR_ClOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_LEVEL_EDITOR_CLOSE 0x00

static_assert(0 <= COMPILE_LEVEL_EDITOR_CLOSE, "COMPILE_LEVEL_EDITOR_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_LEVEL_EDITOR_CLOSE <= CLOSE_LEVEL_EDITOR_MAX, "COMPILE_LEVEL_EDITOR_CLOSE Must be less than or equal CLOSE_LEVEL_EDITOR_MAX.");

#if !defined(COMPILE_LEVEL_EDITOR_CLOSE) || (COMPILE_LEVEL_EDITOR_CLOSE & CLOSE_USE_LEVEL_EDITOR) != CLOSE_USE_LEVEL_EDITOR

#endif  // !defined(COMPILE_LEVEL_EDITOR_CLOSE) || (COMPILE_LEVEL_EDITOR_CLOSE & CLOSE_USE_LEVEL_EDITOR) != CLOSE_USE_LEVEL_EDITOR

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_LEVEL_EDITOR_STATIC
#endif  // BUILDING_STATIC

#endif  // LEVEL_EDITOR_MACRO_USER_MACRO_H
