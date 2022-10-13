///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.1 (2021/12/13 22:22)

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