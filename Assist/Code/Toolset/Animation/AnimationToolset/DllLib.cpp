///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 15:24)

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