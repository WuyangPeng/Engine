///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.5 (2023/04/03 09:32)

#ifndef MILLENNIUM_HISTORY_USER_MACRO_H
#define MILLENNIUM_HISTORY_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define MILLENNIUM_HISTORY_ClOSE_BEGIN (0x01)

#define CLOSE_USE_MILLENNIUM_HISTORY (MILLENNIUM_HISTORY_ClOSE_BEGIN)

#define MILLENNIUM_HISTORY_ClOSE_END CLOSE_USE_MILLENNIUM_HISTORY

#define CLOSE_MILLENNIUM_HISTORY_MAX ((MILLENNIUM_HISTORY_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_MILLENNIUM_HISTORY_CLOSE 0x00

static_assert(0 <= COMPILE_MILLENNIUM_HISTORY_CLOSE, "COMPILE_MILLENNIUM_HISTORY_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_MILLENNIUM_HISTORY_CLOSE <= CLOSE_MILLENNIUM_HISTORY_MAX, "COMPILE_MILLENNIUM_HISTORY_CLOSE Must be less than or equal CLOSE_MILLENNIUM_HISTORY_MAX.");

#if !defined(COMPILE_MILLENNIUM_HISTORY_CLOSE) || (COMPILE_MILLENNIUM_HISTORY_CLOSE & CLOSE_USE_MILLENNIUM_HISTORY) != CLOSE_USE_MILLENNIUM_HISTORY

#endif  // !defined(COMPILE_MILLENNIUM_HISTORY_CLOSE) || (COMPILE_MILLENNIUM_HISTORY_CLOSE & CLOSE_USE_MILLENNIUM_HISTORY) != CLOSE_USE_MILLENNIUM_HISTORY

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC

    #define BUILDING_MILLENNIUM_HISTORY_STATIC

#endif  // BUILDING_STATIC

#endif  // MILLENNIUM_HISTORY_USER_MACRO_H