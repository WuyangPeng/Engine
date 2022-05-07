///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 15:13)

#ifndef PHYSICS_FLUID_FLUID3DB_H
#define PHYSICS_FLUID_FLUID3DB_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

namespace Physics
{
    template <typename Real>
    class Fluid3Db
    {
    public:
        using ClassType = Fluid3Db<Real>;
        using Vector3D = Mathematics::Vector3<Real>;
    };
}

#endif  // PHYSICS_FLUID_FLUID3DB_H
