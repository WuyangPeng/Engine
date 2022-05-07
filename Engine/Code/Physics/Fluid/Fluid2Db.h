///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/25 15:10)

#ifndef PHYSICS_FLUID_FLUID2DB_H
#define PHYSICS_FLUID_FLUID2DB_H

#include "Physics/PhysicsDll.h"

#include "CoreTools/MemoryTools/Array2.h"
#include "Mathematics/Algebra/Vector2.h"

namespace Physics
{
    template <typename Real>
    class Fluid2Db
    {
    public:
        using ClassType = Fluid2Db<Real>;
        using Vector2D = Mathematics::Vector2<Real>;
    };
}

#endif  // PHYSICS_FLUID_FLUID2DB_H
