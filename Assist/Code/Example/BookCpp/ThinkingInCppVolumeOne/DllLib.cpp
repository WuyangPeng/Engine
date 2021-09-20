///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/22 22:03)

#include "Example/BookCpp/ThinkingInCppVolumeOne/ThinkingInCppVolumeOneExport.h"

#include "ThinkingInCppVolumeOne.h"

#ifndef BUILDING_THINKING_IN_CPP_VOLUME_ONE_STATIC

    #include "DllLib.h"

#else  // BUILDING_THINKING_IN_CPP_VOLUME_ONE_STATIC

namespace ThinkingInCppVolumeOne
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THINKING_IN_CPP_VOLUME_ONE_STATIC
