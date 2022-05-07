///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 15:29)

#ifndef PHYSICS_LCP_SOLVER_LCP_POLY_DIST_H
#define PHYSICS_LCP_SOLVER_LCP_POLY_DIST_H

#include "Physics/PhysicsDll.h"

#include "LCPSolverManager.h"
#include "CoreTools/DataTypes/Tuple.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Physics
{
    template <int Dimension, typename FVector, typename DVector>
    class LCPPolyDist
    {
    public:
        using ClassType = LCPPolyDist<Dimension, FVector, DVector>;
    };

}

#endif  // PHYSICS_LCP_SOLVER_LCP_POLY_DIST_H
