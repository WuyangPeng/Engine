///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:29)

#ifndef THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_HELPER_USER_MACRO_H
#define THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE (THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_ClOSE_BEGIN)

#define THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_ClOSE_END CLOSE_USE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE

#define CLOSE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_MAX ((THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_CLOSE 0x00

static_assert(0 <= COMPILE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_CLOSE, "COMPILE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_CLOSE <= CLOSE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_MAX, "COMPILE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_CLOSE Must be less than or equal CLOSE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_MAX.");

#if !defined(COMPILE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_CLOSE) || (COMPILE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_CLOSE & CLOSE_USE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE) != CLOSE_USE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE

#endif  // !defined(COMPILE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_CLOSE) || (COMPILE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_CLOSE & CLOSE_USE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE) != CLOSE_USE_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_STATIC
#endif  // BUILDING_STATIC

#endif  // THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_HELPER_USER_MACRO_H