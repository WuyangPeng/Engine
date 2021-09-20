///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/20 11:00)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_USER_MACRO_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define ASSIST_ClOSE_BEGIN (0x01)

#define CLOSE_USE_ASSIST (ASSIST_ClOSE_BEGIN)

#define ASSIST_ClOSE_END CLOSE_USE_ASSIST

#define CLOSE_ASSIST_MAX ((ASSIST_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_ASSIST_CLOSE 0x00

static_assert(0 <= COMPILE_ASSIST_CLOSE, "COMPILE_ASSIST_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ASSIST_CLOSE <= CLOSE_ASSIST_MAX, "COMPILE_ASSIST_CLOSE Must be less than or equal CLOSE_ASSIST_MAX.");

#if !defined(COMPILE_ASSIST_CLOSE) || (COMPILE_ASSIST_CLOSE & CLOSE_USE_ASSIST) != CLOSE_USE_ASSIST
    #define OPEN_ASSIST static_cast<void>(0)
#endif  // !defined(COMPILE_ASSIST_CLOSE) || (COMPILE_ASSIST_CLOSE & CLOSE_USE_ASSIST) != CLOSE_USE_ASSIST

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_ASSIST_STATIC
#endif  // BUILDING_STATIC

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_USER_MACRO_H
