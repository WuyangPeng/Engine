///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 11:12)

#ifndef PHYSICS_EXAMPLE_PLACEHOLDER_H
#define PHYSICS_EXAMPLE_PLACEHOLDER_H

#include "Example/Physics/PhysicsExample/PhysicsExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace PhysicsExample
{
    class PHYSICS_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // PHYSICS_EXAMPLE_PLACEHOLDER_H
