///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/09 15:21)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Box3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceLine3Box3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Line3 = Line3<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine3Box3(const Line3& line, const Box3& box) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 对象访问。
        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Box3 GetBox() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 动态距离查询的函数计算。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Real Face(int i0, int i1, int i2, const Vector3D& dir, const Vector3D& pointMinusExtent) const;

        Real CaseNoZeros(const Vector3D& direction) const;

        Real Case0(int i0, int i1, int i2, const Vector3D& direction) const;

        Real Case00(int i0, int i1, int i2, const Vector3D& direction) const;

        Real Case000() const;

    private:
        Line3 m_Line;
        Box3 m_Box;
        mutable Real m_LineParameter;
        mutable Vector3D m_Point;
    };

    using FloatDistanceLine3Box3 = DistanceLine3Box3<float>;
    using DoubleDistanceLine3Box3 = DistanceLine3Box3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_H
