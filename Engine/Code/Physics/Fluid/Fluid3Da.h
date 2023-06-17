///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 16:37)

#ifndef PHYSICS_FLUID_FLUID3DA_H
#define PHYSICS_FLUID_FLUID3DA_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

namespace Physics
{
    template <typename Real>
    class Fluid3Da
    {
    public:
        using ClassType = Fluid3Da<Real>;
        using Vector3D = Mathematics::Vector3<Real>;
    };
}

#endif  // PHYSICS_FLUID_FLUID3DA_H
