///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 11:31)

#ifndef MATHEMATICS_OBJECTS2D_SEGMENT2_H
#define MATHEMATICS_OBJECTS2D_SEGMENT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Segment2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Segment2<Real>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        // 线段被表示为(1-s) * P0 + s * P1，其中P0和P1是线段的端点和0 <= s <= 1。
        //
        // 一些算法涉及线段可能更喜欢定义一个中点的表示和面向包围盒的方向。
        // 此表示为C + t * D，其中C = (P0 + P1) / 2是该线段的中心，
        // D = (P1-P0)/Length(P1-P0)是一个单位长度方向的矢量，
        // 且|t| <= e。值 e = Length(P1-P0)/2是该线段的“范围”（半径或半长）。

        // 构造函数计算center、direction和extent从beginPoint和endPoint
        Segment2(const Vector2& beginPoint, const Vector2& endPoint, const Real epsilon = Math::GetZeroTolerance());

        // 构造函数计算beginPoint和endPoint从center、direction和extent
        Segment2(Real extent, const Vector2& center, const Vector2& direction, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2 GetBeginPoint() const noexcept;
        NODISCARD Vector2 GetEndPoint() const noexcept;
        NODISCARD Vector2 GetCenterPoint() const noexcept;
        NODISCARD Vector2 GetDirection() const noexcept;
        NODISCARD Real GetExtent() const noexcept;

        NODISCARD Segment2 GetMove(Real t, const Vector2& velocity) const;

    private:
        // 当你改变beginPoint或endPoint时调用
        void ComputeCenterDirectionExtent();

        // 当你改变center或direction或extent时调用
        void ComputeEndPoints();

    private:
        // 终点表示。
        Vector2 beginPoint;
        Vector2 endPoint;

        // 中心—方向—范围表示。
        Vector2 center;
        Vector2 direction;
        Real extent;

        Real epsilon;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Segment2<Real>& lhs, const Segment2<Real>& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Segment2<Real>& segment);

    using Segment2F = Segment2<float>;
    using Segment2D = Segment2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_SEGMENT2_H
