///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ������汾��0.8.1.0 (2022/08/03 10:59)

#ifndef RISE_OF_HISTORY_USER_MACRO_H
#define RISE_OF_HISTORY_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define RISE_OF_HISTORY_ClOSE_BEGIN (0x01)

#define CLOSE_USE_RISE_OF_HISTORY (RISE_OF_HISTORY_ClOSE_BEGIN)

#define RISE_OF_HISTORY_ClOSE_END CLOSE_USE_RISE_OF_HISTORY

#define CLOSE_RISE_OF_HISTORY_MAX ((RISE_OF_HISTORY_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_RISE_OF_HISTORY_CLOSE 0x00

static_assert(0 <= COMPILE_RISE_OF_HISTORY_CLOSE, "COMPILE_RISE_OF_HISTORY_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_RISE_OF_HISTORY_CLOSE <= CLOSE_RISE_OF_HISTORY_MAX, "COMPILE_RISE_OF_HISTORY_CLOSE Must be less than or equal CLOSE_RISE_OF_HISTORY_MAX.");

#if !defined(COMPILE_RISE_OF_HISTORY_CLOSE) || (COMPILE_RISE_OF_HISTORY_CLOSE & CLOSE_USE_RISE_OF_HISTORY) != CLOSE_USE_RISE_OF_HISTORY

#endif  // !defined(COMPILE_RISE_OF_HISTORY_CLOSE) || (COMPILE_RISE_OF_HISTORY_CLOSE & CLOSE_USE_RISE_OF_HISTORY) != CLOSE_USE_RISE_OF_HISTORY

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_RISE_OF_HISTORY_STATIC
#endif  // BUILDING_STATIC

#endif  // RISE_OF_HISTORY_USER_MACRO_H