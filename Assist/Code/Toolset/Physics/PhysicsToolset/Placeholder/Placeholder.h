///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/12 16:41)

#ifndef PHYSICS_TOOLSET_PLACEHOLDER_H
#define PHYSICS_TOOLSET_PLACEHOLDER_H

#include "Toolset/Physics/PhysicsToolset/PhysicsToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace PhysicsToolset
{
    class PHYSICS_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // PHYSICS_TOOLSET_PLACEHOLDER_H