///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:16)

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
