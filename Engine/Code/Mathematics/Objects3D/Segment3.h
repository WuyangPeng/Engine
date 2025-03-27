/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:25)

#ifndef MATHEMATICS_OBJECTS_3D_SEGMENT3_H
#define MATHEMATICS_OBJECTS_3D_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Segment3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Segment3<Real>;

        using MathType = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Vector3Tools = Vector3Tools<Real>;

    public:
        // 线段被表示为(1-s) * P0 + s * P1，其中P0和P1是线段的端点和0 <= s <= 1。
        //
        // 一些算法涉及线段可能更喜欢定义一个中点的表示和面向包围盒的方向。
        // 此表示为C + t * D，其中C = (P0 + P1) / 2是该线段的中心，
        // D = (P1-P0)/Length(P1-P0)是一个单位长度方向的矢量，
        // 且|t| <= e。值 e = Length(P1-P0)/2是该线段的“范围”（半径或半长）。

        // 构造函数计算center、direction和extent从beginPoint和endPoint
        Segment3(const Vector3& beginPoint, const Vector3& endPoint, Real epsilon = MathType::GetZeroTolerance());

        // 构造函数计算beginPoint和endPoint从center、direction和extent
        Segment3(Real extent, const Vector3& center, const Vector3& direction, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetBeginPoint() const noexcept;
        NODISCARD Vector3 GetEndPoint() const noexcept;
        NODISCARD Vector3 GetCenterPoint() const noexcept;
        NODISCARD Vector3 GetDirection() const noexcept;
        NODISCARD Real GetExtent() const noexcept;

        NODISCARD Segment3 GetMove(Real t, const Vector3& velocity) const;

    private:
        // 当你改变beginPoint或endPoint时调用
        void ComputeCenterDirectionExtent();

        // 当你改变center或direction或extent时调用
        void ComputeEndPoints();

    private:
        // 终点表示。
        Vector3 beginPoint;
        Vector3 endPoint;

        // 中心—方向—范围表示。
        Vector3 center;
        Vector3 direction;
        Real extent;

        Real epsilon;
    };

    using Segment3F = Segment3<float>;
    using Segment3D = Segment3<double>;

    template <typename Real>
    NODISCARD bool Approximate(const Segment3<Real>& lhs, const Segment3<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Segment3<Real>& segment);
}

#endif  // MATHEMATICS_OBJECTS_3D_SEGMENT3_H
