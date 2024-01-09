/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:17)

#ifndef SYSTEM_DIRECT_X_D12_USING_H
#define SYSTEM_DIRECT_X_D12_USING_H

#include "System/Helper/Platform.h"

#if defined(SYSTEM_PLATFORM_WIN32) && defined(SYSTEM_USE_DIRECTX_12)

    #include <D3D12.h>

#endif  // defined(SYSTEM_PLATFORM_WIN32) && defined(SYSTEM_USE_DIRECTX_12)

namespace System
{
#if defined(SYSTEM_PLATFORM_WIN32) && defined(SYSTEM_USE_DIRECTX_12)

#else  // !defined(SYSTEM_PLATFORM_WIN32) || !defined(SYSTEM_USE_DIRECTX_12)

#endif  // defined(SYSTEM_PLATFORM_WIN32) && defined(SYSTEM_USE_DIRECTX_12)
}

#endif  // SYSTEM_DIRECT_X_D12_USING_H