/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/09 13:34)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_H

#include "Mathematics/MathematicsDll.h"

#include "ApproximationCone3EllipseAndPointsControl.h"
#include "Mathematics/Objects3D/Algebra/Ellipse3.h"
#include "Mathematics/Primitives/Cone.h"

/// 将无限单面圆锥体拟合到已知平面与圆锥体相交的三维椭圆。
/// 椭圆本身没有足够的信息，产生了作为锥角函数的锥顶点和锥方向。
/// 需要锥体上的其他点来确定锥体角度。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationCone3EllipseAndPoints
    {
    public:
        using ClassType = ApproximationCone3EllipseAndPoints<Real>;

        using Cone3 = Algebra::Cone3<Real>;
        using Vector3 = Algebra::Vector3<Real>;
        using Vector3Container = std::vector<Vector3>;
        using Ellipse3 = Algebra::Ellipse3<Real>;
        using MathType = Math<Real>;
        using ApproximationCone3EllipseAndPointsControlType = ApproximationCone3EllipseAndPointsControl<Real>;

    public:
        /// 椭圆必须是平面与圆锥体的交点。
        /// 在应用中，通常从交点的点样本来估计椭圆，然后将交点样本与椭圆拟合。
        ///
        /// 默认的控制参数对于应用程序来说似乎是合理的，但它们会暴露给调用方进行调优。
        ApproximationCone3EllipseAndPoints() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static Cone3 Fit(const Ellipse3& ellipse,
                                   const Vector3Container& points,
                                   ApproximationCone3EllipseAndPointsControlType control = ApproximationCone3EllipseAndPointsControlType{});

    private:
        NODISCARD static Cone3 ComputeCone(Real theta,
                                           Real sigma0,
                                           Real sigma1,
                                           const Ellipse3& ellipse);
    };
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_H
