///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 16:35)

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
