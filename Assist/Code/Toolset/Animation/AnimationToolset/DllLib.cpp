///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:42)

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