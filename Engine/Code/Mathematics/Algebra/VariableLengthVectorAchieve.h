///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 14:09)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_ACHIEVE_H

#include "VariableLengthVector.h"
#include "Detail/VariableLengthVectorImplDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26455)
template <typename Real>
Mathematics::VariableLengthVector<Real>::VariableLengthVector(int size)
    : impl{ std::make_shared<ImplType>(size) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real>
Mathematics::VariableLengthVector<Real>::VariableLengthVector(const ContainerType& container)
    : impl{ std::make_shared<ImplType>(container) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real>
Mathematics::VariableLengthVector<Real>::VariableLengthVector(const VariableLengthVector& rhs)
    : impl{ std::make_shared<ImplType>(*rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>::operator=(const VariableLengthVector& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    VariableLengthVector result{ rhs };

    Swap(result);

    return *this;
}
#include STSTEM_WARNING_POP

template <typename Real>
void Mathematics::VariableLengthVector<Real>::Swap(VariableLengthVector& rhs) noexcept
{
    ;

    std::swap(impl, rhs.impl);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real>
Mathematics::VariableLengthVector<Real>::VariableLengthVector(VariableLengthVector&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>::operator=(VariableLengthVector&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    impl = std::move(rhs.impl);

    return *this;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::VariableLengthVector<Real>::IsValid() const noexcept
{
    if (impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::VariableLengthVector<Real>::GetSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetSize();
}

template <typename Real>
const Real& Mathematics::VariableLengthVector<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#ifdef MATHEMATICS_ASSERT_VARIABLE_VECTOR_OUT_OF_RANGE
    MATHEMATICS_ASSERTION_0(0 <= index && index < GetSize(), "索引错误！");
#endif  // MATHEMATICS_ASSERT_VARIABLE_VECTOR_OUT_OF_RANGE

    return (*impl)[index];
}

template <typename Real>
Real& Mathematics::VariableLengthVector<Real>::operator[](int index)
{
    ;

#ifdef MATHEMATICS_ASSERT_VARIABLE_VECTOR_OUT_OF_RANGE
    MATHEMATICS_ASSERTION_0(0 <= index && index < GetSize(), "索引错误！");
#endif  // MATHEMATICS_ASSERT_VARIABLE_VECTOR_OUT_OF_RANGE

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
void Mathematics::VariableLengthVector<Real>::ResetSize(int size)
{
    ;

    return impl->ResetSize(size);
}

template <typename Real>
const Mathematics::VariableLengthVector<Real> Mathematics::VariableLengthVector<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    VariableLengthVector<Real> result{ *this };

    result.impl->Negative();

    return result;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>::operator+=(const VariableLengthVector& rhs)
{
    ;

    impl->Plus(*rhs.impl);

    return *this;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>::operator-=(const VariableLengthVector& rhs)
{
    ;

    impl->Minus(*rhs.impl);

    return *this;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>::operator*=(Real scalar)
{
    ;

    for (auto& value : *impl)
    {
        value *= scalar;
    }

    return *this;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>::operator/=(Real scalar)
{
    ;

    if (Math::sm_Epsilon < Math::FAbs(scalar))
    {
        for (auto& value : *impl)
        {
            value /= scalar;
        }
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        for (auto& value : *impl)
        {
            value = Math::sm_MaxReal;
        }
    }

    return *this;
}

template <typename Real>
Real Mathematics::VariableLengthVector<Real>::Length() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Math::Sqrt(SquaredLength());
}

template <typename Real>
Real Mathematics::VariableLengthVector<Real>::SquaredLength() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto size = GetSize();

    auto squaredLength = Math::GetValue(0);

    for (auto value : *impl)
    {
        squaredLength += value * value;
    }

    MATHEMATICS_ASSERTION_2(0 <= squaredLength, "返回值不能为负数！");

    return squaredLength;
}

template <typename Real>
void Mathematics::VariableLengthVector<Real>::Normalize(Real epsilon)
{
    ;

    auto length = Length();

    if (epsilon < length)
    {
        for (auto& value : *impl)
        {
            value /= length;
        }
    }
    else
    {
        MATHEMATICS_ASSERTION_2(false, "零向量不能正则化！");

        for (auto& value : *impl)
        {
            value = Math::GetValue(0);
        }
    }
}

template <typename Real>
const typename Mathematics::VariableLengthVector<Real>::ContainerType Mathematics::VariableLengthVector<Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetContainer();
}

template <typename Real>
void Mathematics::VariableLengthVector<Real>::SetContainer(const ContainerType& container)
{
    ;

    return impl->SetContainer(container);
}

template <typename Real>
typename Mathematics::VariableLengthVector<Real>::ContainerTypeConstIter Mathematics::VariableLengthVector<Real>::begin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->begin();
}

template <typename Real>
typename Mathematics::VariableLengthVector<Real>::ContainerTypeConstIter Mathematics::VariableLengthVector<Real>::end() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->end();
}

template <typename Real>
typename Mathematics::VariableLengthVector<Real>::ContainerTypeIter Mathematics::VariableLengthVector<Real>::begin() noexcept
{
    ;

    return impl->begin();
}

template <typename Real>
typename Mathematics::VariableLengthVector<Real>::ContainerTypeIter Mathematics::VariableLengthVector<Real>::end() noexcept
{
    ;

    return impl->end();
}

#endif  //  MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_ACHIEVE_H
