///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/12 18:02)

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