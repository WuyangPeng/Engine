///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/10 21:43)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Query/QueryBase.h"

namespace Mathematics
{
    template <typename Real>
    class ContMinBox3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContMinBox3<Real>;

    public:
        ContMinBox3(const std::vector<Vector3<Real>>& points, Real epsilon, QueryType queryType);

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator Box3<Real>() const noexcept;

    private:
        Box3<Real> minBox;
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_H
