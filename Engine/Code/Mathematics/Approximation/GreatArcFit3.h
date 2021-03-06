///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 14:29)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    // 除了最小二乘的一个大圆，输入向量投影到圆。
    // 最小角的扇形(可能的)包含点计算。
    // 弧的端点的扇形被返回。返回的端点A0和A1是垂直于返回的法线N。
    // 此外,当你查看弧通过观察平面的大圆的 N方向,圆弧是遍历逆时针从A0到A1。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE GreatArcFit3 final
    {
    public:
        using ClassType = GreatArcFit3<Real>;
        using Vector3D = Vector3D<Real>;
        using Points = std::vector<Vector3D>;
        using Math = Math<Real>;

    public:
        explicit GreatArcFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetNormal() const noexcept;
        [[nodiscard]] const Vector3D GetArcEnd0() const noexcept;
        [[nodiscard]] const Vector3D GetArcEnd1() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        Vector3D m_Normal;
        Vector3D m_ArcEnd0;
        Vector3D m_ArcEnd1;
    };

    using FloatGreatArcFit3 = GreatArcFit3<float>;
    using DoubleGreatArcFit3 = GreatArcFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H
