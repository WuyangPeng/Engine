///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:55)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

#include <array>

namespace Mathematics
{
    template <typename Real>
    class TrianglePlaneRelations final
    {
    public:
        using ClassType = TrianglePlaneRelations<Real>;

        using Triangle3Type = Triangle3<Real>;
        using Vector3Type = Vector3<Real>;
        using Plane3Type = Plane3<Real>;
        using MathType = Math<Real>;

    public:
        TrianglePlaneRelations(const Triangle3Type& triangle, const Plane3Type& plane, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetDistance(int index) const;
        NODISCARD NumericalValueSymbol GetSign(int index) const;
        NODISCARD int GetPositive() const noexcept;
        NODISCARD int GetNegative() const noexcept;
        NODISCARD int GetZero() const noexcept;

    private:
        constexpr static auto size = 3;

        using DistanceType = std::array<Real, size>;
        using SignType = std::array<NumericalValueSymbol, size>;

    private:
        void Relations(const Triangle3Type& triangle, const Plane3Type& plane, const Real epsilon);

    private:
        DistanceType distance;
        SignType sign;
        int positive;
        int negative;
        int zero;
    };

}

#endif  // MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_H
