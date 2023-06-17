///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:24)

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
