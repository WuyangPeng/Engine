// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/19 14:08)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DETAIL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DETAIL_H

#include "Polynomial.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_POLYNOMIAL_DETAIL)

    #include "AlgebraTraits.h"
    #include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
    #include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
    #include "CoreTools/Helper/MemberFunctionMacro.h"
    #include "CoreTools/Helper/MemoryMacro.h"
    #include "CoreTools/ObjectSystems/StreamSize.h"
    #include "Mathematics/Base/Math.h"

    #include "System/Helper/PragmaWarning/NumericCast.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26481)
template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(int degree)
    : m_Degree{ degree }, m_Coeff{ nullptr }
{
    if (0 <= m_Degree)
    {
        m_Coeff = NEW1<Real>(m_Degree + 1);
        const auto numBytes = (m_Degree + 1) * CoreTools::StreamSize<Real>::GetStreamSize();

        memset(m_Coeff, 0, numBytes);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "构造的多项式degree为负数！");
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(const Polynomial& rhs)
    : m_Degree{ rhs.GetDegree() }, m_Coeff{ nullptr }
{
    if (0 <= m_Degree)
    {
        m_Coeff = NEW1<Real>(m_Degree + 1);

        const auto numBytes = (m_Degree + 1) * CoreTools::StreamSize<Real>::GetStreamSize();
        memcpy(m_Coeff, rhs.m_Coeff, numBytes);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "构造的多项式degree为负数！");
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(const std::vector<Real>& tuple)
    : m_Degree{ boost::numeric_cast<int>(tuple.size() - 1) }, m_Coeff{ NEW1<Real>(m_Degree + 1) }
{
    if (0 < tuple.size())
    {
        const auto numBytes = (m_Degree + 1) * CoreTools::StreamSize<Real>::GetStreamSize();
        memcpy(m_Coeff, &tuple[0], numBytes);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "构造的多项式数组为空！");
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(int size, const Real* data)
    : m_Degree{ size - 1 }, m_Coeff{ NEW1<Real>(m_Degree + 1) }
{
    if (0 < size)
    {
        const auto numBytes = (m_Degree + 1) * CoreTools::StreamSize<Real>::GetStreamSize();
        memcpy(m_Coeff, data, numBytes);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "构造的多项式数组为空！");
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Polynomial<Real>::~Polynomial()
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)
    DELETE1(m_Coeff);
	#include STSTEM_WARNING_POP
	}
	EXCEPTION_STD_EXCEPTION_CATCH(Mathematics)
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    Polynomial<Real> temp{ rhs };

    Swap(temp);

    return *this;
}

// private
template <typename Real>
void Mathematics::Polynomial<Real>::Swap(Polynomial& rhs) noexcept
{
    std::swap(m_Degree, rhs.m_Degree);
    std::swap(m_Coeff, rhs.m_Coeff);
}

    #ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Polynomial<Real>::IsValid() const noexcept
{
    if (0 <= m_Degree && m_Coeff != nullptr)
        return true;
    else
        return false;
}
    #endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Polynomial<Real>::ResetDegree(int degree)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(0 <= degree, "构造的多项式degree为负数！");

    Polynomial<Real> temp{ degree };

    Swap(temp);
}

template <typename Real>
int Mathematics::Polynomial<Real>::GetDegree() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Degree;
}

template <typename Real>
const Real* Mathematics::Polynomial<Real>::GetElements() const noexcept 
{ 
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Coeff;
}

template <typename Real>
Real* Mathematics::Polynomial<Real>::GetElements() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return m_Coeff;
}

template <typename Real>
const Real& Mathematics::Polynomial<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= index && index <= m_Degree, "索引无效\n");

    return m_Coeff[index];
}

template <typename Real>
Real& Mathematics::Polynomial<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(0 <= index && index <= m_Degree, "索引无效\n");

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Real Mathematics::Polynomial<Real>::operator()(Real value) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto result = m_Coeff[m_Degree];
    for (auto i = m_Degree - 1; 0 <= i; --i)
    {
        result *= value;
        result += m_Coeff[i];
    }

    return result;
}

template <typename Real>
const Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Polynomial<Real> result{ m_Degree };

    for (auto i = 0; i <= m_Degree; ++i)
    {
        result.m_Coeff[i] = -m_Coeff[i];
    }

    return result;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator+=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (rhs.m_Degree <= m_Degree)
    {
        for (auto i = 0; i <= rhs.m_Degree; ++i)
        {
            m_Coeff[i] += rhs.m_Coeff[i];
        }
    }
    else
    {
        Polynomial<Real> temp{ rhs };

        Swap(temp);

        for (auto i = 0; i <= temp.m_Degree; ++i)
        {
            m_Coeff[i] += temp.m_Coeff[i];
        }
    }

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator-=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (rhs.m_Degree <= m_Degree)
    {
        for (auto i = 0; i <= rhs.m_Degree; ++i)
        {
            m_Coeff[i] -= rhs.m_Coeff[i];
        }
    }
    else
    {
        Polynomial<Real> temp{ -rhs };

        Swap(temp);

        for (auto i = 0; i <= temp.m_Degree; ++i)
        {
            m_Coeff[i] += temp.m_Coeff[i];
        }
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
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator+=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Coeff[0] += scalar;

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator-=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Coeff[0] -= scalar;

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i <= m_Degree; ++i)
    {
        m_Coeff[i] *= scalar;
    }

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator/=(Real scalar)  
{
    MATHEMATICS_CLASS_IS_VALID_1;
	
	CoreTools::DoNothing();

    if (Math::sm_ZeroTolerance < Math::FAbs(scalar))
    {
        for (auto i = 0; i <= m_Degree; ++i)
        {
            m_Coeff[i] /= scalar;
        }
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        for (auto i = 0; i <= m_Degree; ++i)
        {
            m_Coeff[i] = Math::sm_MaxReal;
        }
    }

    return *this;
}

template <typename Real>
const Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetDerivative() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (0 < m_Degree)
    {
        Polynomial result{ m_Degree - 1 };
        for (auto index = 0; index < m_Degree; ++index)
        {
            const auto nextIndex = index + 1;
            result.m_Coeff[index] = nextIndex * m_Coeff[nextIndex];
        }
        return result;
    }
    else
    {
        Polynomial result{ 0 };
        result.m_Coeff[0] = Math::sm_Zero;
        return result;
    }
}

template <typename Real>
Real Mathematics::Polynomial<Real>::GetEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Coeff[m_Degree];
}

template <typename Real>
const Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetInversion() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Polynomial result{ m_Degree };
    for (auto i = 0; i <= m_Degree; ++i)
    {
        result.m_Coeff[i] = m_Coeff[m_Degree - i];
    }
    return result;
}

template <typename Real>
void Mathematics::Polynomial<Real>::Compress(Real epsilon) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = m_Degree; 0 <= i; --i)
    {
        if (Math::FAbs(m_Coeff[i]) <= epsilon)
        {
            --m_Degree;
        }
        else
        {
            break;
        }
    }

    if (0 <= m_Degree)
    {
        auto invLeading = Math::sm_One / m_Coeff[m_Degree];
        m_Coeff[m_Degree] = Math::sm_One;
        for (auto i = 0; i < m_Degree; ++i)
        {
            m_Coeff[i] *= invLeading;
        }
    }
}

template <typename Real>
typename const Mathematics::Polynomial<Real>::PolynomialDivide Mathematics::Polynomial<Real>::Divide(const Polynomial& divisor, Real epsilon) const
{
    const auto quotientDegree = m_Degree - divisor.m_Degree;
    if (0 <= quotientDegree)
    {
        Polynomial quotient{ quotientDegree };

        // 临时存储的余数。
        Polynomial remainder{ *this };

        // 做除法（欧几里得算法）。
        auto inv = Math::sm_One / divisor[divisor.m_Degree];
        for (auto quotientIndex = quotientDegree; 0 <= quotientIndex; --quotientIndex)
        {
            auto divisorIndex = divisor.m_Degree + quotientIndex;
            quotient[quotientIndex] = inv * remainder[divisorIndex];
            --divisorIndex;
            for (; quotientIndex <= divisorIndex; --divisorIndex)
            {
                remainder[divisorIndex] -= quotient[quotientIndex] * divisor[divisorIndex - quotientIndex];
            }
        }

        // 计算remainder正确的degree。
        auto remainderDegree = divisor.m_Degree - 1;
        while (0 < remainderDegree && Math::FAbs(remainder[remainderDegree]) < epsilon)
        {
            --remainderDegree;
        }

        if (remainderDegree == 0 && Math::FAbs(remainder[0]) < epsilon)
        {
            remainder[0] = Math::sm_Zero;
        }

        Polynomial correctRemainder{ remainderDegree };
        const auto degree = remainderDegree + 1;
        const auto numBytes = degree * sizeof(Real);
        memcpy(correctRemainder.m_Coeff, remainder.m_Coeff, numBytes);

        return PolynomialDivide{ quotient, correctRemainder };
    }
    else
    {
        Polynomial quotient{ 0 };
        quotient[0] = Math::sm_Zero;
        Polynomial remainder{ *this };

        return PolynomialDivide{ quotient, *this };
    }
}

#include STSTEM_WARNING_POP

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_POLYNOMIAL_DETAIL)

template <typename T>
bool Mathematics ::Approximate(const Polynomial<T>& lhs, const Polynomial<T>& rhs, const T epsilon)
{
    if (lhs.GetDegree() != rhs.GetDegree())
    {
        return false;
    }
    else
    {
        for (auto i = 0; i <= rhs.GetDegree(); ++i)
        {
            if (!Math<T>::Approximate(lhs[i], rhs[i], epsilon))
            {
                return false;
            }
        }

        return true;
    }
}

template <typename T>
bool Mathematics ::Approximate(const Polynomial<T>& lhs, const Polynomial<T>& rhs)
{
    return Approximate(lhs, rhs, Math<T>::sm_ZeroTolerance);
}

template <typename Real>
const Mathematics::Polynomial<Real> Mathematics ::operator*(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs)
{
    Polynomial<Real> result{ lhs.GetDegree() + rhs.GetDegree() };

    for (auto lhsIndex = 0; lhsIndex <= lhs.GetDegree(); ++lhsIndex)
    {
        for (auto rhsIndex = 0; rhsIndex <= rhs.GetDegree(); ++rhsIndex)
        {
            const auto index = lhsIndex + rhsIndex;
            result[index] += lhs[lhsIndex] * rhs[rhsIndex];
        }
    }

    return result;
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_DETAIL_H
