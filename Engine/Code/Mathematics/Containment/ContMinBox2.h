///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:42)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Box2.h"
#include "Mathematics/Query/QueryBase.h"

namespace Mathematics
{
    template <typename Real>
    class ContMinBox2
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContMinBox2<Real>;

    public:
        ContMinBox2(const std::vector<Vector2<Real>>& points, Real epsilon, QueryType queryType, bool isConvexPolygon);

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator Box2<Real>() const noexcept;

    private:
        enum class MinBox2Flag
        {
            None,
            Left,
            Right,
            Bottom,
            Top
        };

        void UpdateBox(const Vector2<Real>& lPoint,
                       const Vector2<Real>& rPoint,
                       const Vector2<Real>& bPoint,
                       const Vector2<Real>& tPoint,
                       const Vector2<Real>& u,
                       const Vector2<Real>& v,
                       Real& minAreaDiv4);

    private:
        Box2<Real> minBox;
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_H
