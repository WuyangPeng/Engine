///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/12 16:40)

#include "Toolset/Physics/PhysicsToolset/PhysicsToolsetExport.h"

#include "Toolset/Physics/PhysicsToolset/PhysicsToolset.h"

#ifndef BUILDING_PHYSICS_STATIC

    #include "DllLib.h"

#else  // BUILDING_PHYSICS_STATIC

namespace PhysicsToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_PHYSICS_STATIC
