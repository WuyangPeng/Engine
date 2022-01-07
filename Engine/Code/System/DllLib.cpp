///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 12:36)

#include "System/SystemExport.h"

#include "System/System.h"

#ifndef BUILDING_SYSTEM_STATIC

    #include "DllLib.h"

#else  // BUILDING_SYSTEM_STATIC

namespace System
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SYSTEM_STATIC