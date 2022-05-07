///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 15:34)

#ifndef PHYSICS_RIGID_BODY_RIGID_BODY_MANAGER_H
#define PHYSICS_RIGID_BODY_RIGID_BODY_MANAGER_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Quaternion.h"

namespace Physics
{
    template <typename Real>
    class RigidBodyManager
    {
    public:
        using ClassType = RigidBodyManager<Real>;
        using Matrix3 = Mathematics::Matrix3<Real>;
        using Quaternion = Mathematics::Quaternion<Real>;
        using Vector3D = Mathematics::Vector3<Real>;
    };

}

#endif  // PHYSICS_RIGID_BODY_RIGID_BODY_MANAGER_H
