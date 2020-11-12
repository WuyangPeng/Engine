///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 11:12)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_IMPL_DETAIL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_IMPL_DETAIL_H

#include "VariableLengthVectorImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::VariableLengthVectorImpl<Real>::VariableLengthVectorImpl() noexcept
    : m_Container{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::VariableLengthVectorImpl<Real>::VariableLengthVectorImpl(int size)
    : m_Container(size)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::VariableLengthVectorImpl<Real>::VariableLengthVectorImpl(const ContainerType& variableLengthVector)
    : m_Container{ variableLengthVector }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::VariableLengthVectorImpl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::VariableLengthVectorImpl<Real>::GetSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Container.size());
}

template <typename Real>
Real& Mathematics::VariableLengthVectorImpl<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
const Real& Mathematics::VariableLengthVectorImpl<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Container.at(index);
}

template <typename Real>
void Mathematics::VariableLengthVectorImpl<Real>::ResetSize(int size)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (size < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("size为负数！"s));
    }

    m_Container.clear();
    m_Container.resize(size);
    m_Container.shrink_to_fit();
}

template <typename Real>
const typename Mathematics::VariableLengthVectorImpl<Real>::ContainerType Mathematics::VariableLengthVectorImpl<Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Container;
}

template <typename Real>
void Mathematics::VariableLengthVectorImpl<Real>::SetContainer(const ContainerType& variableLengthVector)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Container = variableLengthVector;
}

template <typename Real>
typename Mathematics::VariableLengthVectorImpl<Real>::ContainerTypeConstIter Mathematics::VariableLengthVectorImpl<Real>::begin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Container.cbegin();
}

template <typename Real>
typename Mathematics::VariableLengthVectorImpl<Real>::ContainerTypeConstIter Mathematics::VariableLengthVectorImpl<Real>::end() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Container.cend();
}

template <typename Real>
typename Mathematics::VariableLengthVectorImpl<Real>::ContainerTypeIter Mathematics::VariableLengthVectorImpl<Real>::begin() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Container.begin();
}

template <typename Real>
typename Mathematics::VariableLengthVectorImpl<Real>::ContainerTypeIter Mathematics::VariableLengthVectorImpl<Real>::end() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Container.end();
}

template <typename Real>
void Mathematics::VariableLengthVectorImpl<Real>::Negative() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto& value : m_Container)
    {
        value = -value;
    }
}

template <typename Real>
void Mathematics::VariableLengthVectorImpl<Real>::Plus(const VariableLengthVectorImpl& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (m_Container.size() != rhs.m_Container.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小不同！"s));
    }

    for (auto i = 0u; i < m_Container.size(); ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Container[i] += rhs.m_Container[i];
#include STSTEM_WARNING_POP
    }
}

template <typename Real>
void Mathematics::VariableLengthVectorImpl<Real>::Minus(const VariableLengthVectorImpl& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (m_Container.size() != rhs.m_Container.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小不同！"s));
    }

    for (auto i = 0u; i < m_Container.size(); ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Container[i] -= rhs.m_Container[i];
#include STSTEM_WARNING_POP
    }
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_IMPL_DETAIL_H
