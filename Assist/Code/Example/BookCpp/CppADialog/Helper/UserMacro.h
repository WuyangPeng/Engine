///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/27 18:47)

#ifndef CPP_A_DIALOG_HELPER_USER_MACRO_H
#define CPP_A_DIALOG_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CPP_A_DIALOG_ClOSE_BEGIN (0x01)

#define CLOSE_USE_CPP_A_DIALOG (CPP_A_DIALOG_ClOSE_BEGIN)

#define CPP_A_DIALOG_ClOSE_END CLOSE_USE_CPP_A_DIALOG

#define CLOSE_CPP_A_DIALOG_MAX ((CPP_A_DIALOG_ClOSE_END << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_CPP_A_DIALOG_CLOSE 0x00

static_assert(0 <= COMPILE_CPP_A_DIALOG_CLOSE, "COMPILE_CPP_A_DIALOG_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CPP_A_DIALOG_CLOSE <= CLOSE_CPP_A_DIALOG_MAX, "COMPILE_CPP_A_DIALOG_CLOSE Must be less than or equal CLOSE_CPP_A_DIALOG_MAX.");

#if !defined(COMPILE_CPP_A_DIALOG_CLOSE) || (COMPILE_CPP_A_DIALOG_CLOSE & CLOSE_USE_CPP_A_DIALOG) != CLOSE_USE_CPP_A_DIALOG

#endif  // !defined(COMPILE_CPP_A_DIALOG_CLOSE) || (COMPILE_CPP_A_DIALOG_CLOSE & CLOSE_USE_CPP_A_DIALOG) != CLOSE_USE_CPP_A_DIALOG

// 是否编译为静态库
#ifdef BUILDING_STATIC
    #define BUILDING_CPP_A_DIALOG_STATIC
#endif  // BUILDING_STATIC

#endif  // CPP_A_DIALOG_HELPER_USER_MACRO_H
