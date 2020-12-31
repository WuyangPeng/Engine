///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 10:17)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_DETAIL_H

#include "SparseMatrixConstIterator.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::SparseMatrixConstIterator<Real>::SparseMatrixConstIterator() noexcept
    : m_Iter{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::SparseMatrixConstIterator<Real>::SparseMatrixConstIterator(const SparseMatrixConstIter& iter) noexcept
    : m_Iter{ iter }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::SparseMatrixConstIterator<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::SparseMatrixConstIterator<Real>::increment() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ++m_Iter;
}

template <typename Real>
bool Mathematics::SparseMatrixConstIterator<Real>::equal(const SparseMatrixConstIterator& other) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Iter == other.m_Iter;
}

template <typename Real>
typename const Mathematics::SparseMatrixConstIterator<Real>::SparseMatrixConstIter&
    Mathematics::SparseMatrixConstIterator<Real>::dereference() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Iter;
}

template <typename Real>
const typename Mathematics::SparseMatrixConstIterator<Real>::SparseMatrixKey Mathematics::SparseMatrixConstIterator<Real>::GetKey() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Iter->first;
}

template <typename Real>
const typename Mathematics::SparseMatrixConstIterator<Real>::SparseMatrixMapped Mathematics::SparseMatrixConstIterator<Real>::GetMapped() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Iter->second;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_DETAIL_H