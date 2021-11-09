///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/08 21:15)

#ifndef COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_HELPER_USER_MACRO_H
#define COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_ClOSE_BEGIN (0x01)

#define CLOSE_USE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH (COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_ClOSE_BEGIN)

#define COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_ClOSE_END CLOSE_USE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH

#define CLOSE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_MAX ((COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_ClOSE_END << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_CLOSE 0x00

static_assert(0 <= COMPILE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_CLOSE, "COMPILE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_CLOSE <= CLOSE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_MAX, "COMPILE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_CLOSE Must be less than or equal CLOSE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_MAX.");

#if !defined(COMPILE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_CLOSE) || (COMPILE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_CLOSE & CLOSE_USE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH) != CLOSE_USE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH

#endif  // !defined(COMPILE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_CLOSE) || (COMPILE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_CLOSE & CLOSE_USE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH) != CLOSE_USE_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH

#ifdef BUILDING_STATIC
    #define BUILDING_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_STATIC
#endif  // BUILDING_STATIC

#endif  // COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_HELPER_USER_MACRO_H
