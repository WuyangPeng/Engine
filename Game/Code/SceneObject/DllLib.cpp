///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 10:39)

#include "SceneObject/SceneObjectExport.h"

#include "SceneObject/SceneObject.h"

#ifndef BUILDING_SCENE_OBJECT_STATIC

    #include "DllLib.h"

#else  // !BUILDING_SCENE_OBJECT_STATIC

namespace SceneObject
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SCENE_OBJECT_STATIC
