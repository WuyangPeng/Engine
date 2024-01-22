/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:35)

#include "Animation/AnimationExport.h"

#include "Animation/Animation.h"

#ifndef BUILDING_ANIMATION_STATIC

    #include "DllLib.h"

#else  // BUILDING_ANIMATION_STATIC

namespace Animation
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ANIMATION_STATIC