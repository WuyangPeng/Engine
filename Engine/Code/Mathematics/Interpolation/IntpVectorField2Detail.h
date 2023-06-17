///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:10)

#ifndef MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_DETAIL_H

#include "IntpVectorField2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpVectorField2<Real>::IntpVectorField2(const std::vector<Vector2<Real>>& domain, const std::vector<Vector2<Real>>& range, QueryType queryType)
    : dt{}, xInterp{}, yInterp{}
{
    std::vector<Real> xOutput(domain.size());
    std::vector<Real> yOutput(domain.size());
    for (auto i = 0u; i < domain.size(); ++i)
    {
        xOutput.at(i) = range.at(i)[0];
        yOutput.at(i) = range.at(i)[1];
    }

    dt = std::make_shared<Delaunay2<Real>>(domain, static_cast<Real>(0.001), queryType);

    xInterp = std::make_shared<IntpQdrNonuniform2<Real>>(*dt, xOutput);

    yInterp = std::make_shared<IntpQdrNonuniform2<Real>>(*dt, yOutput);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpVectorField2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpVectorField2<Real>::Evaluate(const Vector2<Real>& input, Vector2<Real>& output)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Real xDeriv{};
    Real yDeriv{};

    return xInterp->Evaluate(input, output[0], xDeriv, yDeriv) && yInterp->Evaluate(input, output[1], xDeriv, yDeriv);
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_DETAIL_H