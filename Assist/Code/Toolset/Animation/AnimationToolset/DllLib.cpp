///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:42)

#include "Toolset/Animation/AnimationToolset/AnimationToolsetExport.h"

#include "Toolset/Animation/AnimationToolset/AnimationToolset.h"

#ifndef BUILDING_ANIMATION_STATIC

    #include "DllLib.h"

#else  // BUILDING_ANIMATION_STATIC

namespace AnimationToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ANIMATION_STATIC