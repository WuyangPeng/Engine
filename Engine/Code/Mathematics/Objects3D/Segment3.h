///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 14:47)

#ifndef MATHEMATICS_OBJECTS3D_SEGMENT3_H
#define MATHEMATICS_OBJECTS3D_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Segment3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Segment3<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;

    public:
        // 线段被表示为(1-s) * P0 + s * P1，其中P0和P1是线段的端点和0 <= s <= 1。
        //
        // 一些算法涉及线段可能更喜欢定义一个中点的表示和面向包围盒的方向。
        // 此表示为C + t * D，其中C = (P0 + P1) / 2是该线段的中心，
        // D = (P1-P0)/Length(P1-P0)是一个单位长度方向的矢量，
        // 且|t| <= e。值 e = Length(P1-P0)/2是该线段的“范围”（半径或半长）。

        // 构造函数计算center、direction和extent从beginPoint和endPoint
        Segment3(const Vector3D& beginPoint, const Vector3D& endPoint, const Real epsilon = Math::GetZeroTolerance());

        // 构造函数计算beginPoint和endPoint从center、direction和extent
        Segment3(Real extent, const Vector3D& center, const Vector3D& direction, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetBeginPoint() const noexcept;
        [[nodiscard]] const Vector3D GetEndPoint() const noexcept;
        [[nodiscard]] const Vector3D GetCenterPoint() const noexcept;
        [[nodiscard]] const Vector3D GetDirection() const noexcept;
        [[nodiscard]] Real GetExtent() const noexcept;

        const Segment3 GetMove(Real t, const Vector3D& velocity) const;

    private:
        // 当你改变beginPoint或endPoint时调用
        void ComputeCenterDirectionExtent();

        // 当你改变center或direction或extent时调用
        void ComputeEndPoints();

    private:
        // 终点表示。
        Vector3D m_BeginPoint;
        Vector3D m_EndPoint;

        // 中心—方向—范围表示。
        Vector3D m_Center;
        Vector3D m_Direction;
        Real m_Extent;

        Real m_Epsilon;
    };

    using FloatSegment3 = Segment3<float>;
    using DoubleSegment3 = Segment3<double>;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Segment3<Real>& lhs, const Segment3<Real>& rhs, const Real epsilon);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Segment3<Real>& segment);
}

#endif  // MATHEMATICS_OBJECTS3D_SEGMENT3_H
