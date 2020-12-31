///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 14:32)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
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
        using Triangle3 = Triangle3<Real>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Math = Math<Real>;

    public:
        TrianglePlaneRelations(const Triangle3& triangle, const Plane3& plane, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetDistance(int index) const;
        [[nodiscard]] NumericalValueSymbol GetSign(int index) const;
        [[nodiscard]] int GetPositive() const;
        [[nodiscard]] int GetNegative() const;
        [[nodiscard]] int GetZero() const;

    private:
        constexpr static auto sm_Size = 3;

        using DistanceType = std::array<Real, sm_Size>;
        using SignType = std::array<NumericalValueSymbol, sm_Size>;

    private:
        void Relations(const Triangle3& triangle, const Plane3& plane, const Real epsilon);

    private:
        DistanceType m_Distance;
        SignType m_Sign;
        int m_Positive;
        int m_Negative;
        int m_Zero;
    };

}

#endif  // MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_H
