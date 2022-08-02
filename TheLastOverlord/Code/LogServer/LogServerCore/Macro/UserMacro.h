///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/28 21:27)

#ifndef LOG_SERVER_CORE_MACRO_USER_MACRO_H
#define LOG_SERVER_CORE_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_LOG_SERVER_CORE_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_LOG_SERVER_CORE_CLOSE 0x00

static_assert(0 <= COMPILE_LOG_SERVER_CORE_CLOSE, "COMPILE_LOG_SERVER_CORE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_LOG_SERVER_CORE_CLOSE <= CLOSE_LOG_SERVER_CORE_MAX, "COMPILE_LOG_SERVER_CORE_CLOSE Must be less than or equal CLOSE_LOG_SERVER_CORE_MAX.");

#if !defined(COMPILE_LOG_SERVER_CORE_CLOSE) || (COMPILE_LOG_SERVER_CORE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_LOG_SERVER_CORE_CLOSE) || (COMPILE_LOG_SERVER_CORE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

// �Ƿ����ɾ�̬��
#ifdef BUILDING_STATIC
    #define BUILDING_LOG_SERVER_CORE_STATIC
#endif  // BUILDING_STATIC

#endif  // LOG_SERVER_CORE_MACRO_USER_MACRO_H
