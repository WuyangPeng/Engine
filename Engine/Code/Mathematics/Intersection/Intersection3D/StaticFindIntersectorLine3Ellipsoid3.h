///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:06)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Ellipsoid3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorLine3Ellipsoid3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Ellipsoid3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Line3 = Line3<Real>;
        using Ellipsoid3 = Ellipsoid3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine3Ellipsoid3(const Line3& line, const Ellipsoid3& ellipsoid, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3 GetLine() const noexcept;
        NODISCARD Ellipsoid3 GetEllipsoid() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3 GetPoint(int index) const;

        /// 小阈值用于测试与计算有关的二次方程的判别式：Q(t) = a2 * t^2 + 2 * a1 * t + a0。
        /// 判别式为D = a1 * a1 - a0 * a2。
        ///  Q(t)在D < 0时没有实值根，在D = 0时有一个实值根，在D > 0时有两个实值根。
        /// 代码逻辑涉及用户定义的阈值：if(D < negThreshold){ 无根（无交集）}，
        /// else if (D > posThreshold) { 两根（两个交集）}
        ///  else { 一个根（一个交集）}阈值的默认值为零，但您可以将其设置为非零 （negThreshold <= 0 和 posThreshold >= 0）。
        /// 以前，负阈值被硬编码为零。 正阈值被硬编码为Math<Real>::GetZeroTolerance()，
        /// 该阈值不适用于某些数据集（即，当椭圆范围很大时）。现在默认值为零。
        void SetNegativeThreshold(Real negThreshold);
        NODISCARD Real GetNegativeThreshold() const noexcept;
        void SetPositiveThreshold(Real posThreshold);
        NODISCARD Real GetPositiveThreshold() const noexcept;

    private:
        void Find();

    private:
        Line3 line;
        Ellipsoid3 ellipsoid;

        int quantity;
        Vector3 point0;
        Vector3 point1;

        /// 用于测试判别式。 默认值为零。 您可以将负阈值设置为（小）负数，将正阈值设置为（小）正数。
        Real negativeThreshold;
        Real positiveThreshold;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_H
