///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:07)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM1_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM1_DETAIL_H

#include "IntpBSplineUniform1.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpBSplineUniform1<Real>::IntpBSplineUniform1(int degree, int dim, const std::vector<Real>& data)
    : ParentType{ 1, degree, std::vector<int>{ dim }, data }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpBSplineUniform1<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::IntpBSplineUniform1<Real>::operator()(const std::vector<Real>& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return (*this)(x.at(0));
}

template <typename Real>
Real Mathematics::IntpBSplineUniform1<Real>::operator()(const std::vector<int>& dx, const std::vector<Real>& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!dx.empty() && !x.empty())
    {
        return (*this)(dx.at(0), x.at(0));
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("指针为空。"s));
    }
}

template <typename Real>
Real Mathematics::IntpBSplineUniform1<Real>::operator()(Real x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    this->SetBase(0, boost::numeric_cast<int>(Math<Real>::Floor(x)));
    if (this->IsBaseChange(0))
    {
        this->SwitchToNewLocalGrid(0);

        if (this->HasEvaluateCallback())
        {
            EvaluateUnknownData();
        }

        ComputeIntermediate();
    }

    auto& polynomial = this->GetPolynomial(0);

    this->SetPolynomial(0, x - this->GetBase(0), polynomial);

    auto result = Math<Real>::GetValue(0);
    for (auto k = 0; k <= this->GetDegree(); ++k)
    {
        result += polynomial[k] * this->GetInter(k);
    }
    return result;
}

template <typename Real>
Real Mathematics::IntpBSplineUniform1<Real>::operator()(int dx, Real x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    this->SetBase(0, boost::numeric_cast<int>(Math<Real>::Floor(x)));
    if (this->IsBaseChange(0))
    {
        this->SwitchToNewLocalGrid(0);

        if (this->HasEvaluateCallback())
        {
            EvaluateUnknownData();
        }

        ComputeIntermediate();
    }

    auto& polynomial = this->GetPolynomial(0);

    this->SetPolynomial(dx, x - this->GetBase(0), polynomial);

    auto result = Math<Real>::GetValue(0);
    for (auto k = dx; k <= this->GetDegree(); ++k)
    {
        result += polynomial[k] * this->GetInter(k);
    }
    return result;
}

template <typename Real>
void Mathematics::IntpBSplineUniform1<Real>::EvaluateUnknownData()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto k = this->GetGridMin(0); k <= this->GetGridMax(0); ++k)
    {
        if (Math<Real>::Approximate(this->GetData(k), Math<Real>::maxReal))
        {
            this->SetData(k);
        }
    }
}

template <typename Real>
void Mathematics::IntpBSplineUniform1<Real>::ComputeIntermediate()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto k = 0; k <= this->GetDegree(); ++k)
    {
        auto inter = Math<Real>::GetValue(0);
        for (int i = 0, j = this->GetBase(0) - 1; i <= this->GetDegree(); ++i, ++j)
        {
            inter += this->GetData(j) * this->GetMatrix(i, j);
        }

        this->SetInter(k, inter);
    }
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM1_DETAIL_H