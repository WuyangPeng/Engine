///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 15:10)

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
