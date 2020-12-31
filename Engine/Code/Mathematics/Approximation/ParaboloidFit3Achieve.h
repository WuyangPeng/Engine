///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 16:55)

#ifndef MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_ACHIEVE_H

#include "ParaboloidFit3.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"

template <typename Real>
Mathematics::ParaboloidFit3<Real>::ParaboloidFit3(const Points& points)
    : m_Coeff{}, m_IsFitSuccess{ false }
{
    Calculate(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ParaboloidFit3<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::VariableLengthVector<Real> Mathematics::ParaboloidFit3<Real>::GetCoeff() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_IsFitSuccess)
    {
        return m_Coeff;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("抛物面拟合失败。"s));
    }
}

template <typename Real>
bool Mathematics::ParaboloidFit3<Real>::GetIsFitSuccess() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_IsFitSuccess;
}

template <typename Real>
void Mathematics::ParaboloidFit3<Real>::Calculate(const Points& points)
{
    // 分配线性系统（矩阵最初是零）。

    VariableMatrix<Real> matrix{ sm_VariableMatrixSize, sm_VariableMatrixSize };

    using RealContainer = typename LinearSystem<Real>::RealContainer;
    RealContainer rhs(sm_VariableMatrixSize);

    for (const auto& point : points)
    {
        auto x2 = point.GetX() * point.GetX();
        auto xy = point.GetX() * point.GetY();
        auto y2 = point.GetY() * point.GetY();
        auto zx = point.GetZ() * point.GetX();
        auto zy = point.GetZ() * point.GetY();
        auto x3 = point.GetX() * x2;
        auto x2y = x2 * point.GetY();
        auto xy2 = point.GetX() * y2;
        auto y3 = point.GetY() * y2;
        auto zx2 = point.GetZ() * x2;
        auto zxy = point.GetZ() * xy;
        auto zy2 = point.GetZ() * y2;
        auto x4 = x2 * x2;
        auto x3y = x3 * point.GetY();
        auto x2y2 = x2 * y2;
        auto xy3 = point.GetX() * y3;
        auto y4 = y2 * y2;

        matrix(0, 0) += x4;
        matrix(0, 1) += x3y;
        matrix(0, 2) += x2y2;
        matrix(0, 3) += x3;
        matrix(0, 4) += x2y;
        matrix(0, 5) += x2;
        matrix(1, 2) += xy3;
        matrix(1, 4) += xy2;
        matrix(1, 5) += xy;
        matrix(2, 2) += y4;
        matrix(2, 4) += y3;
        matrix(2, 5) += y2;
        matrix(3, 3) += x2;
        matrix(3, 5) += point.GetX();
        matrix(4, 5) += point.GetY();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        rhs[0] += zx2;
        rhs[1] += zxy;
        rhs[2] += zy2;
        rhs[3] += zx;
        rhs[4] += zy;
        rhs[5] += point.GetZ();

#include STSTEM_WARNING_POP
    }

    auto numPoints = static_cast<Real>(points.size());

    matrix(1, 0) = matrix(0, 1);
    matrix(1, 1) = matrix(0, 2);
    matrix(1, 3) = matrix(0, 4);
    matrix(2, 0) = matrix(0, 2);
    matrix(2, 1) = matrix(1, 2);
    matrix(2, 3) = matrix(1, 4);
    matrix(3, 0) = matrix(0, 3);
    matrix(3, 1) = matrix(1, 3);
    matrix(3, 2) = matrix(2, 3);
    matrix(3, 4) = matrix(1, 5);
    matrix(4, 0) = matrix(0, 4);
    matrix(4, 1) = matrix(1, 4);
    matrix(4, 2) = matrix(2, 4);
    matrix(4, 3) = matrix(3, 4);
    matrix(4, 4) = matrix(2, 5);
    matrix(5, 0) = matrix(0, 5);
    matrix(5, 1) = matrix(1, 5);
    matrix(5, 2) = matrix(2, 5);
    matrix(5, 3) = matrix(3, 5);
    matrix(5, 4) = matrix(4, 5);
    matrix(5, 5) = numPoints;

    try
    {
        const LinearSystem<Real> linearSystem{};

        auto coeff = linearSystem.Solve(matrix, rhs);

        m_Coeff = VariableLengthVector{ coeff };
        m_IsFitSuccess = true;
    }
    catch (CoreTools::Error&)
    {
        m_IsFitSuccess = false;
    }
}

#endif  // MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_ACHIEVE_H
