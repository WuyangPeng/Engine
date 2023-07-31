///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:13)

#include "Scene/SceneExport.h"

#include "Scene/Scene.h"

#ifndef BUILDING_SCENE_STATIC

    #include "DllLib.h"

#else  // !BUILDING_SCENE_STATIC

namespace Scene
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SCENE_STATIC
