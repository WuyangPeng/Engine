///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 09:59)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_DETAIL_H

#include "EquationResultConstIterator.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename ResultConstIter>
Mathematics::EquationResultConstIterator<ResultConstIter>::EquationResultConstIterator()
    : iter{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename ResultConstIter>
Mathematics::EquationResultConstIterator<ResultConstIter>::EquationResultConstIterator(const ResultConstIter& iter) noexcept
    : iter{ iter }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename ResultConstIter>
bool Mathematics::EquationResultConstIterator<ResultConstIter>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ResultConstIter>
void Mathematics::EquationResultConstIterator<ResultConstIter>::increment() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ++iter;
}

template <typename ResultConstIter>
bool Mathematics::EquationResultConstIterator<ResultConstIter>::equal(const EquationResultConstIterator& other) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return iter == other.iter;
}

template <typename ResultConstIter>
const ResultConstIter& Mathematics::EquationResultConstIterator<ResultConstIter>::dereference() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return iter;
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename ResultConstIter>
typename ResultConstIter::value_type Mathematics::EquationResultConstIterator<ResultConstIter>::operator*() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *iter;
}

#include SYSTEM_WARNING_POP

template <typename ResultConstIter>
std::ostream& Mathematics::operator<<(std::ostream& os, const EquationResultConstIterator<ResultConstIter>& iter)
{
    os << *iter;

    return os;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_DETAIL_H