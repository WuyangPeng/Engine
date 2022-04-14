///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/20 19:33)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM3_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM3_DETAIL_H

#include "IntpBSplineUniform3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpBSplineUniform3<Real>::IntpBSplineUniform3(int degree, const std::vector<int>& dim, const std::vector<Real>& data)
    : ParentType{ 3, degree, dim, data }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpBSplineUniform3<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::IntpBSplineUniform3<Real>::Index(int ix, int iy, int iz) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return ix + this->GetDim(0) * (iy + this->GetDim(1) * iz);
}

template <typename Real>
Real Mathematics::IntpBSplineUniform3<Real>::operator()(const std::vector<Real>& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return (*this)(x.at(0), x.at(1), x.at(2));
}

template <typename Real>
Real Mathematics::IntpBSplineUniform3<Real>::operator()(const std::vector<int>& dx, const std::vector<Real>& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return (*this)(dx.at(0), dx.at(1), dx.at(2), x.at(0), x.at(1), x.at(2));
}

template <typename Real>
Real Mathematics::IntpBSplineUniform3<Real>::operator()(Real x, Real y, Real z)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    this->SetBase(0, boost::numeric_cast<int>(Math<Real>::Floor(x)));
    this->SetBase(1, boost::numeric_cast<int>(Math<Real>::Floor(y)));
    this->SetBase(2, boost::numeric_cast<int>(Math<Real>::Floor(z)));

    for (auto dim = 0; dim < 3; ++dim)
    {
        if (this->IsBaseChange(dim))
        {
            for (auto k = 0; k < 3; ++k)
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

    auto& polynomial0 = this->GetPolynomial(0);
    this->SetPolynomial(0, x - this->GetBase(0), polynomial0);

    auto& polynomial1 = this->GetPolynomial(1);
    this->SetPolynomial(0, y - this->GetBase(1), polynomial1);

    auto& polynomial2 = this->GetPolynomial(2);
    this->SetPolynomial(0, z - this->GetBase(2), polynomial2);

    std::array<int, 3> index{ 0, 0, 0 };
    auto result = Math<Real>::GetValue(0);
    for (auto k = 0; k < this->GetDP1ToN(); ++k)
    {
        result += polynomial0[index.at(0)] * polynomial1[index.at(1)] * polynomial2[index.at(2)] * this->GetInter(k);

        if (++index.at(0) <= this->GetDegree())
        {
            continue;
        }
        index.at(0) = 0;

        if (++index.at(1) <= this->GetDegree())
        {
            continue;
        }
        index.at(1) = 0;

        ++index.at(2);
    }
    return result;
}

template <typename Real>
Real Mathematics::IntpBSplineUniform3<Real>::operator()(int dx, int dy, int dz, Real x, Real y, Real z)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    this->SetBase(0, boost::numeric_cast<int>(Math<Real>::Floor(x)));
    this->SetBase(1, boost::numeric_cast<int>(Math<Real>::Floor(y)));
    this->SetBase(2, boost::numeric_cast<int>(Math<Real>::Floor(z)));

    for (auto dim = 0; dim < 3; ++dim)
    {
        if (this->IsBaseChange(dim))
        {
            for (auto k = 0; k < 3; ++k)
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

    auto& polynomial0 = this->GetPolynomial(0);
    this->SetPolynomial(dx, x - this->GetBase(0), polynomial0);

    auto& polynomial1 = this->GetPolynomial(1);
    this->SetPolynomial(dy, y - this->GetBase(1), polynomial1);

    auto& polynomial2 = this->GetPolynomial(2);
    this->SetPolynomial(dz, z - this->GetBase(2), polynomial2);

    std::array<int, 3> index{ dx, dy, dz };
    std::array<int, 2> delta{ dx, this->GetDP1() * dy };
    Real result{};
    for (auto k = index.at(0) + this->GetDP1() * (index.at(1) + this->GetDP1() * index.at(2)); k < this->GetDP1ToN(); ++k)
    {
        result += polynomial0[index.at(0)] * polynomial1[index.at(1)] * polynomial2[index.at(2)] * this->GetInter(k);

        if (++index.at(0) <= this->GetDegree())
        {
            continue;
        }
        index.at(0) = dx;
        k += delta.at(0);

        if (++index.at(1) <= this->GetDegree())
        {
            continue;
        }
        index.at(1) = dy;
        k += delta.at(1);

        ++index.at(2);
    }
    return result;
}

template <typename Real>
void Mathematics::IntpBSplineUniform3<Real>::EvaluateUnknownData()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto k2 = this->GetGridMin(2); k2 <= this->GetGridMax(2); ++k2)
    {
        for (auto k1 = this->GetGridMin(1); k1 <= this->GetGridMax(1); ++k1)
        {
            for (auto k0 = this->GetGridMin(0); k0 <= this->GetGridMax(0); ++k0)
            {
                const auto index = Index(k0, k1, k2);
                if (Math<Real>::Approximate(this->GetData(index), Math<Real>::maxReal))
                {
                    this->SetData(index);
                }
            }
        }
    }
}

template <typename Real>
void Mathematics::IntpBSplineUniform3<Real>::ComputeIntermediate()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::array<int, 2> delta{ this->GetDim(0) - this->GetDP1(), this->GetDim(0) * (this->GetDim(1) - this->GetDP1()) };
    std::array<int, 3> loop{};
    for (auto dim = 0; dim < 3; ++dim)
    {
        loop.at(dim) = this->GetGridMin(dim);
    }
    auto index = Index(loop.at(0), loop.at(1), loop.at(2));

    for (auto k = 0; k < this->GetDP1ToN(); ++k, ++index)
    {
        this->SetCache(k, this->GetData(index));

        if (++loop.at(0) <= this->GetGridMax(0))
        {
            continue;
        }
        loop.at(0) = this->GetGridMin(0);
        index += delta.at(0);

        if (++loop.at(1) <= this->GetGridMax(1))
        {
            continue;
        }
        loop.at(1) = this->GetGridMin(1);
        index += delta.at(1);

        ++loop.at(2);
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

#endif  // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM3_DETAIL_H