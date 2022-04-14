///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/11 16:52)

#ifndef MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_H
#define MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"

namespace Mathematics
{
    template <typename Real>
    class ContPointInPolygon2
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContPointInPolygon2<Real>;

    public:
        explicit ContPointInPolygon2(const std::vector<Vector2<Real>>& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Contains(const Vector2<Real>& p) const;

        NODISCARD bool ContainsConvexOrderN(const Vector2<Real>& p) const;

        NODISCARD bool ContainsConvexOrderLogN(const Vector2<Real>& p) const;

        NODISCARD bool ContainsQuadrilateral(const Vector2<Real>& p) const;

    private:
        NODISCARD bool SubContainsPoint(const Vector2<Real>& p, int i0, int i1) const;

    private:
        std::vector<Vector2<Real>> points;
    };

    using PointInPolygon2F = ContPointInPolygon2<float>;
    using PointInPolygon2D = ContPointInPolygon2<double>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_H
