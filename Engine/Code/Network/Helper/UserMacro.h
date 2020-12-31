///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/06 10:08)

#ifndef NETWORK_HELPER_USER_MACRO_H
#define NETWORK_HELPER_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define NETWORK_ClOSE_BEGIN (0x01)

#define CLOSE_USE_ACE (NETWORK_ClOSE_BEGIN)
#define CLOSE_USE_OPENSSL (NETWORK_ClOSE_BEGIN << 1)
#define CLOSE_USE_ACE_WCHAR (NETWORK_ClOSE_BEGIN << 2)  // 默认关闭

#define NETWORK_ClOSE_END CLOSE_USE_ACE_WCHAR

#define CLOSE_NETWORK_MAX (((NETWORK_ClOSE_END) << 1) - 1)

// 编译测试（默认为0x04，最大值为0x07）
#define COMPILE_NETWORK_CLOSE 0x04

static_assert(0 <= COMPILE_NETWORK_CLOSE, "COMPILE_NETWORK_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_NETWORK_CLOSE <= CLOSE_NETWORK_MAX, "COMPILE_NETWORK_CLOSE Must be less than or equal CLOSE_NETWORK_MAX.");

#if !defined(COMPILE_NETWORK_CLOSE) || (COMPILE_NETWORK_CLOSE & CLOSE_USE_ACE) != CLOSE_USE_ACE
    #define NETWORK_USE_ACE static_cast<void>(0)
#endif  // !defined(COMPILE_NETWORK_CLOSE) || (COMPILE_NETWORK_CLOSE & CLOSE_USE_ACE) != CLOSE_USE_ACE

#if !defined(COMPILE_NETWORK_CLOSE) || (COMPILE_NETWORK_CLOSE & CLOSE_USE_ACE_WCHAR) != CLOSE_USE_ACE_WCHAR
    #define NETWORK_USE_ACE_WCHAR static_cast<void>(0)
#endif  // !defined(COMPILE_NETWORK_CLOSE) || (COMPILE_NETWORK_CLOSE & CLOSE_USE_ACE_WCHAR) != CLOSE_USE_ACE_WCHAR

#if defined(NETWORK_USE_ACE) && defined(NETWORK_USE_ACE_WCHAR)
    #define NETWORK_USES_ACE_WCHAR static_cast<void>(0)
#endif  // defined(NETWORK_USE_ACE) && defined(NETWORK_USE_ACE_WCHAR)

#if !defined(COMPILE_NETWORK_CLOSE) || (COMPILE_NETWORK_CLOSE & CLOSE_USE_OPENSSL) != CLOSE_USE_OPENSSL
    #define NETWORK_USE_OPENSSL static_cast<void>(0)
#endif  // !defined(COMPILE_NETWORK_CLOSE) || (COMPILE_NETWORK_CLOSE & CLOSE_USE_OPENSSL) != CLOSE_USE_OPENSSL

#define BOOST_ASIO_NO_DEPRECATED

// 是否编译为静态库
#ifdef BUILDING_STATIC
    #define BUILDING_NETWORK_STATIC static_cast<void>(0)
#endif  // BUILDING_STATIC

#endif  // NETWORK_HELPER_USER_MACRO_H
