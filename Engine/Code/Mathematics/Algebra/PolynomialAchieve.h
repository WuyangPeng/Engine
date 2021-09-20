///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/10 11:30)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_ACHIEVE_H

#include "Polynomial.h"
#include "PolynomialDivide.h"
#include "Detail/PolynomialImplDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(int degree)
    : impl{ std::make_shared<ImplType>(degree) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(const ContainerType& coeff)
    : impl{ std::make_shared<ImplType>(coeff) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(const Polynomial& rhs)
    : impl{ std::make_shared<ImplType>(*rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator=(const Polynomial& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    Polynomial temp{ rhs };

    Swap(temp);

    return *this;
}
#include STSTEM_WARNING_POP

template <typename Real>
void Mathematics::Polynomial<Real>::Swap(Polynomial& rhs) noexcept
{
    ;

    std::swap(impl, rhs.impl);
}

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(Polynomial&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator=(Polynomial&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    impl = std::move(rhs.impl);

    return *this;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Polynomial<Real>::IsValid() const noexcept
{
    if (impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Polynomial<Real>::ResetDegree(int degree)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(0 <= degree, "����Ķ���ʽdegreeΪ������");

    Polynomial<Real> rhs{ degree };

    Swap(rhs);
}

template <typename Real>
int Mathematics::Polynomial<Real>::GetDegree() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetDegree();
}

template <typename Real>
const Real& Mathematics::Polynomial<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (*impl)[index];
}

template <typename Real>
Real& Mathematics::Polynomial<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Real Mathematics::Polynomial<Real>::GetBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetBegin();
}

template <typename Real>
Real Mathematics::Polynomial<Real>::GetEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetEnd();
}

template <typename Real>
Real Mathematics::Polynomial<Real>::operator()(Real value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (*impl)(value);
}

template <typename Real>
typename Mathematics::Polynomial<Real>::ContainerType Mathematics::Polynomial<Real>::GetValue() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue();
}

template <typename Real>
void Mathematics::Polynomial<Real>::SetValue(const ContainerType& coeff)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->SetValue(coeff);
}

template <typename Real>
const Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Polynomial<Real> result{ *this };

    result.impl->Negative();

    return result;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator+=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (GetDegree() <= rhs.GetDegree())
    {
        Polynomial temp{ rhs };
        Swap(temp);
        impl->Plus(*temp.impl);
    }
    else
    {
        impl->Plus(*rhs.impl);
    }

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator-=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (GetDegree() <= rhs.GetDegree())
    {
        Polynomial temp{ rhs };
        Swap(temp);
        impl->Minus(*temp.impl);
    }
    else
    {
        impl->Plus(*rhs.impl);
    }

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator*=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = (*this) * rhs;

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator+=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    (*impl)[0] += scalar;

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator-=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    (*impl)[0] -= scalar;

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator*=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto& coeff : *impl)
    {
        coeff *= scalar;
    }

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::GetZeroTolerance() < Math::FAbs(scalar))
    {
        for (auto& coeff : *impl)
        {
            coeff /= scalar;
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������"s));
    }

    return *this;
}

template <typename Real>
const Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetDerivative() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto degree = GetDegree();

    if (0 < degree)
    {
        Polynomial result{ degree - 1 };

        for (auto index = 0; index < degree; ++index)
        {
            const auto nextIndex = index + 1;
            result[index] = nextIndex * (*impl)[nextIndex];
        }
        return result;
    }
    else
    {
        Polynomial result{ 0 };

        return result;
    }
}

template <typename Real>
const Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetInversion() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto degree = GetDegree();

    Polynomial result{ degree };
    for (auto i = 0; i <= degree; ++i)
    {
        result[i] = (*impl)[degree - i];
    }

    return result;
}

template <typename Real>
void Mathematics::Polynomial<Real>::Compress(Real epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    const auto degree = impl->GetCompressDegree(epsilon);

    if (0 <= degree)
    {
        Polynomial result{ degree };

        result[degree] = Math::GetValue(1);
        for (auto i = 0; i < degree; ++i)
        {
            result[i] = (*impl)[i] / (*impl)[degree];
        }

        Swap(result);
    }
}

template <typename Real>
typename const Mathematics::Polynomial<Real>::PolynomialDivide Mathematics::Polynomial<Real>::Divide(const Polynomial& divisor, Real epsilon) const
{
    const auto degree = GetDegree();
    const auto divisorDegree = divisor.GetDegree();

    const auto quotientDegree = degree - divisorDegree;
    if (0 <= quotientDegree)
    {
        Polynomial quotient{ quotientDegree };

        // ��ʱ�洢��������
        Polynomial remainder{ *this };

        // ��������ŷ������㷨����
        auto inv = Math::GetValue(1) / divisor[divisorDegree];
        for (auto quotientIndex = quotientDegree; 0 <= quotientIndex; --quotientIndex)
        {
            auto divisorIndex = divisorDegree + quotientIndex;
            quotient[quotientIndex] = inv * remainder[divisorIndex];
            --divisorIndex;
            for (; quotientIndex <= divisorIndex; --divisorIndex)
            {
                remainder[divisorIndex] -= quotient[quotientIndex] * divisor[divisorIndex - quotientIndex];
            }
        }

        // ����remainder��ȷ��degree��
        auto remainderDegree = divisorDegree - 1;
        while (0 < remainderDegree && Math::FAbs(remainder[remainderDegree]) < epsilon)
        {
            --remainderDegree;
        }

        if (remainderDegree == 0 && Math::FAbs(remainder[0]) < epsilon)
        {
            remainder[0] = Math::GetValue(0);
        }

        Polynomial correctRemainder{ remainderDegree };

        for (auto i = 0; i < remainderDegree; ++i)
        {
            correctRemainder[i] = remainder[i];
        }

        return PolynomialDivide{ quotient, correctRemainder };
    }
    else
    {
        Polynomial quotient{ 0 };
        Polynomial remainder{ *this };

        return PolynomialDivide{ quotient, *this };
    }
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_ACHIEVE_H
