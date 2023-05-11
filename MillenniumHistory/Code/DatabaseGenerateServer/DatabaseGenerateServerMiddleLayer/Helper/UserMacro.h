///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.5 (2023/04/03 09:55)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_HELPER_USER_MACRO_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLOSE 0x00

static_assert(0 <= COMPILE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLOSE, "COMPILE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLOSE <= CLOSE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_MAX, "COMPILE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLOSE Must be less than or equal CLOSE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_MAX.");

#if !defined(COMPILE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLOSE) || (COMPILE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLOSE) || (COMPILE_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

// �Ƿ����ɾ�̬��
#ifdef BUILDING_STATIC

    #define BUILDING_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_STATIC

#endif  // BUILDING_STATIC

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_HELPER_USER_MACRO_H