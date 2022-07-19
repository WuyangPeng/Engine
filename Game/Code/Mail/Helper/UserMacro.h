///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 18:18)

#ifndef MAIL_HELPER_USER_HELPER_H
#define MAIL_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_MAIL_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_MAIL_CLOSE 0x00

static_assert(0 <= COMPILE_MAIL_CLOSE, "COMPILE_MAIL_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_MAIL_CLOSE <= CLOSE_MAIL_MAX, "COMPILE_MAIL_CLOSE Must be less than or equal CLOSE_MAIL_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_GAME_STATIC
    #define BUILDING_MAIL_STATIC
#endif  // BUILDING_GAME_STATIC

#if !defined(COMPILE_MAIL_CLOSE) || (COMPILE_MAIL_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_MAIL_CLOSE) || (COMPILE_MAIL_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // MAIL_HELPER_USER_HELPER_H
