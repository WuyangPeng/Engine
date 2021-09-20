///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:03)

#ifndef INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_HELPER_USER_MACRO_H
#define INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_ClOSE_BEGIN (0x01)

#define CLOSE_USE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION (INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_ClOSE_BEGIN)

#define INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_ClOSE_END CLOSE_USE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION

#define CLOSE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_MAX ((INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_CLOSE 0x00

static_assert(0 <= COMPILE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_CLOSE, "COMPILE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_CLOSE <= CLOSE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_MAX, "COMPILE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_CLOSE Must be less than or equal CLOSE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_MAX.");

#if !defined(COMPILE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_CLOSE) || (COMPILE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_CLOSE & CLOSE_USE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION) != CLOSE_USE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION

#endif  // !defined(COMPILE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_CLOSE) || (COMPILE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_CLOSE & CLOSE_USE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION) != CLOSE_USE_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_STATIC
#endif  // BUILDING_STATIC

#endif  // INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_HELPER_USER_MACRO_H
