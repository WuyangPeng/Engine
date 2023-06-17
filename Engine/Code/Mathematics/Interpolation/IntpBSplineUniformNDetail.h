///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:08)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_DETAIL_H

#include "IntpBSplineUniformN.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpBSplineUniformN<Real>::IntpBSplineUniformN(int dims, int degree, const std::vector<int>& dim, const std::vector<Real>& data)
    : ParentType{ dims, degree, dim, data },
      evI(dims),
      ciLoop(dims),
      ciDelta(boost::numeric_cast<size_t>(dims) - 1),
      opI(dims),
      opJ(dims),
      opDelta(boost::numeric_cast<size_t>(dims) - 1)
{
    auto temp = 1;
    for (auto i = 0; i < dims - 1; ++i)
    {
        ciDelta.at(i) = temp * (dim.at(i) - this->GetDP1());
        temp *= dim.at(i);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpBSplineUniformN<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::IntpBSplineUniformN<Real>::Index(const std::vector<int>& i) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto index = i.at(boost::numeric_cast<size_t>(this->GetDimension()) - 1);
    for (auto dim = this->GetDimension() - 2; dim >= 0; --dim)
    {
        index *= this->GetDim(dim);
        index += i.at(dim);
    }
    return index;
}

template <typename Real>
Real Mathematics::IntpBSplineUniformN<Real>::operator()(const std::vector<Real>& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto dim = 0; dim < this->GetDimension(); ++dim)
    {
        this->SetBase(dim, boost::numeric_cast<int>(Math<Real>::Floor(x.at(dim))));
    }

    for (auto dim = 0; dim < this->GetDimension(); ++dim)
    {
        if (this->IsBaseChange(dim))
        {
            for (auto k = 0; k < this->GetDimension(); ++k)
            {
                this->SwitchToNewLocalGrid(k);
            }

            if (this->HasEvaluateCallback())
            {
                EvaluateUnknownData();
            }

            ComputeIntermediate();
            break;
        }
    }

    for (auto dim = 0; dim < this->GetDimension(); ++dim)
    {
        auto& polynomial = this->GetPolynomial(dim);
        this->SetPolynomial(0, x.at(dim) - this->GetBase(dim), polynomial);
    }

    for (auto dim = 0; dim < this->GetDimension(); ++dim)
    {
        opI.at(dim) = 0;
    }

    auto result = Math<Real>::GetValue(0);
    for (auto k = 0; k < this->GetDP1ToN(); ++k)
    {
        auto temp = this->GetInter(k);
        for (auto dim = 0; dim < this->GetDimension(); ++dim)
        {
            auto& polynomial = this->GetPolynomial(dim);
            temp *= polynomial[opI.at(dim)];
        }
        result += temp;

        for (auto dim = 0; dim < this->GetDimension(); ++dim)
        {
            if (++opI.at(dim) <= this->GetDegree())
            {
                break;
            }
            opI.at(dim) = 0;
        }
    }
    return result;
}

template <typename Real>
Real Mathematics::IntpBSplineUniformN<Real>::operator()(const std::vector<int>& dx, const std::vector<Real>& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto dim = 0; dim < this->GetDimension(); ++dim)
    {
        this->SetBase(dim, boost::numeric_cast<int>(Math<Real>::Floor(x.at(dim))));
    }

    for (auto dim = 0; dim < this->GetDimension(); ++dim)
    {
        if (this->IsBaseChange(dim))
        {
            for (auto k = 0; k < this->GetDimension(); ++k)
            {
                this->SwitchToNewLocalGrid(k);
            }

            if (this->HasEvaluateCallback())
            {
                EvaluateUnknownData();
            }

            ComputeIntermediate();
            break;
        }
    }

    for (auto dim = 0; dim < this->GetDimension(); ++dim)
    {
        auto& polynomial = this->GetPolynomial(dim);
        this->SetPolynomial(dx.at(dim), x.at(dim) - this->GetBase(dim), polynomial);
    }

    for (auto dim = 0; dim < this->GetDimension(); ++dim)
    {
        opJ.at(dim) = dx.at(dim);
    }

    auto temp = 1;
    for (auto dim = 0; dim < this->GetDimension() - 1; ++dim)
    {
        opDelta.at(dim) = temp * dx.at(dim);
        temp *= this->GetDP1();
    }

    auto result = Math<Real>::GetValue(0);
    auto k = opJ.at(boost::numeric_cast<size_t>(this->GetDimension()) - 1);
    for (auto dim = this->GetDimension() - 2; dim >= 0; --dim)
    {
        k *= this->GetDP1();
        k += opJ.at(dim);
    }
    for (; k < this->GetDP1ToN(); ++k)
    {
        auto inter = this->GetInter(k);
        for (auto dim = 0; dim < this->GetDimension(); ++dim)
        {
            auto& polynomial = this->GetPolynomial(dim);
            inter *= polynomial[opJ.at(dim)];
        }
        result += inter;

        for (auto dim = 0; dim < this->GetDimension(); ++dim)
        {
            if (++opJ.at(dim) <= this->GetDegree())
            {
                continue;
            }
            opJ.at(dim) = dx.at(dim);
            k += opDelta.at(dim);
        }
    }
    return result;
}

template <typename Real>
void Mathematics::IntpBSplineUniformN<Real>::EvaluateUnknownData()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto dim = 0; dim < this->GetDimension(); ++dim)
    {
        evI.at(dim) = this->GetGridMin(dim);
    }

    for (auto j = 0; j < this->GetDP1ToN(); ++j)
    {
        const auto index = Index(evI);
        if (Math<Real>::Approximate(this->GetData(index), Math<Real>::maxReal))
        {
            this->SetData(index);
        }

        for (auto dim = 0; dim < this->GetDimension(); ++dim)
        {
            if (++evI.at(dim) <= this->GetGridMax(dim))
            {
                break;
            }
            evI.at(dim) = this->GetGridMin(dim);
        }
    }
}

template <typename Real>
void Mathematics::IntpBSplineUniformN<Real>::ComputeIntermediate()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto dim = 0; dim < this->GetDimension(); ++dim)
    {
        ciLoop.at(dim) = this->GetGridMin(dim);
    }
    auto index = Index(ciLoop);

    for (auto k = 0; k < this->GetDP1ToN(); ++k, ++index)
    {
        this->SetCache(k, this->GetData(index));

        for (auto dim = 0; dim < this->GetDimension(); ++dim)
        {
            if (++ciLoop.at(dim) <= this->GetGridMax(dim))
            {
                break;
            }
            ciLoop.at(dim) = this->GetGridMin(dim);
            index += ciDelta.at(dim);
        }
    }

    for (auto i = 0, j = 0; i < this->GetDP1ToN(); ++i)
    {
        auto sum = Math<Real>::GetValue(0);
        for (auto k = 0; k < this->GetDP1ToN(); k += this->GetSkip(j), j += this->GetSkip(j))
        {
            sum += this->GetProduct(j) * this->GetCache(k);
        }
        this->SetInter(i, sum);
    }
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_DETAIL_H