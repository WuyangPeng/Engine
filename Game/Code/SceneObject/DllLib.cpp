///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 10:39)

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
