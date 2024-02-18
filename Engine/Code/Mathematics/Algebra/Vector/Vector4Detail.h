///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/01/30 14:06)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR4_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR4_DETAIL_H

#include "Vector4.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Algebra::Vector4<Real> Mathematics::Algebra::HyperCross(const Vector4<Real>& v0, const Vector4<Real>& v1, const Vector4<Real>& v2)
{
    const auto m01 = v0[0] * v1[1] - v0[1] * v1[0];  // x0*y1 - y0*x1
    const auto m02 = v0[0] * v1[2] - v0[2] * v1[0];  // x0*z1 - z0*x1
    const auto m03 = v0[0] * v1[3] - v0[3] * v1[0];  // x0*w1 - w0*x1
    const auto m12 = v0[1] * v1[2] - v0[2] * v1[1];  // y0*z1 - z0*y1
    const auto m13 = v0[1] * v1[3] - v0[3] * v1[1];  // y0*w1 - w0*y1
    const auto m23 = v0[2] * v1[3] - v0[3] * v1[2];  // z0*w1 - w0*z1

    return Vector4<Real>{
        +m23 * v2[1] - m13 * v2[2] + m12 * v2[3],  // +m23*y2 - m13*z2 + m12*w2
        -m23 * v2[0] + m03 * v2[2] - m02 * v2[3],  // -m23*x2 + m03*z2 - m02*w2
        +m13 * v2[0] - m03 * v2[1] + m01 * v2[3],  // +m13*x2 - m03*y2 + m01*w2
        -m12 * v2[0] + m02 * v2[1] - m01 * v2[2]  // -m12*x2 + m02*y2 - m01*z2
    };
}

template <typename Real>
Mathematics::Algebra::Vector4<Real> Mathematics::Algebra::UnitHyperCross(const Vector4<Real>& v0, const Vector4<Real>& v1, const Vector4<Real>& v2, bool robust)
{
    const auto unitHyperCross = HyperCross(v0, v1, v2);

    Normalize(unitHyperCross, robust);

    return unitHyperCross;
}

template <typename Real>
Real Mathematics::Algebra::DotHyperCross(const Vector4<Real>& v0, const Vector4<Real>& v1, const Vector4<Real>& v2, const Vector4<Real>& v3)
{
    return Dot(HyperCross(v0, v1, v2), v3);
}

template <typename Real>
Real Mathematics::Algebra::ComputeOrthogonalComplement(int numInputs, std::vector<Vector4<Real>>& vector, bool robust)
{
    if (numInputs == 1)
    {
        auto maxIndex = 0;
        auto maxComponent = Math<Real>::FAbs(vector.at(0)[0]);
        for (auto i = 1; i < 4; ++i)
        {
            auto component = Math<Real>::FAbs(vector.at(0)[i]);
            if (maxComponent < component)
            {
                maxIndex = i;
                maxComponent = component;
            }
        }

        if (maxIndex < 2)
        {
            vector.at(1)[0] = -vector.at(0)[1];
            vector.at(1)[1] = +vector.at(0)[0];
            vector.at(1)[2] = Real{};
            vector.at(1)[3] = Real{};
        }
        else if (maxIndex == 3)
        {
            /// 通常，您可以跳过此子句并交换最后两个组件。
            /// 然而，在这种情况下，通过交换2和3，
            /// 当输入是表示为4D仿射向量（w＝0）的3D向量时，我们允许函数正常工作。
            vector.at(1)[0] = Real{};
            vector.at(1)[1] = +vector.at(0)[2];
            vector.at(1)[2] = -vector.at(0)[1];
            vector.at(1)[3] = Real{};
        }
        else
        {
            vector.at(1)[0] = Real{};
            vector.at(1)[1] = Real{};
            vector.at(1)[2] = -vector.at(0)[3];
            vector.at(1)[3] = +vector.at(0)[2];
        }

        numInputs = 2;
    }

    if (numInputs == 2)
    {
        std::array<Real, 6> det{ vector.at(0)[0] * vector.at(1)[1] - vector.at(1)[0] * vector.at(0)[1],
                                 vector.at(0)[0] * vector.at(1)[2] - vector.at(1)[0] * vector.at(0)[2],
                                 vector.at(0)[0] * vector.at(1)[3] - vector.at(1)[0] * vector.at(0)[3],
                                 vector.at(0)[1] * vector.at(1)[2] - vector.at(1)[1] * vector.at(0)[2],
                                 vector.at(0)[1] * vector.at(1)[3] - vector.at(1)[1] * vector.at(0)[3],
                                 vector.at(0)[2] * vector.at(1)[3] - vector.at(1)[2] * vector.at(0)[3] };

        auto maxIndex = 0;
        auto maxComponent = std::fabs(det.at(0));
        for (auto i = 1; i < 6; ++i)
        {
            auto component = std::fabs(det.at(i));
            if (component > maxComponent)
            {
                maxIndex = i;
                maxComponent = component;
            }
        }

        if (maxIndex == 0)
        {
            vector.at(2) = { -det.at(4), +det.at(2), Real{}, -det.at(0) };
        }
        else if (maxIndex <= 2)
        {
            vector.at(2) = { +det.at(5), Real{}, -det.at(2), +det.at(1) };
        }
        else
        {
            vector.at(2) = { Real{}, -det.at(5), +det.at(4), -det.at(3) };
        }

        numInputs = 3;
    }

    if (numInputs == 3)
    {
        vector.at(3) = HyperCross(vector.at(0), vector.at(1), vector.at(2));

        return Orthonormalize<4, Real>(4, vector, robust);
    }

    return Real{};
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR4_DETAIL_H
