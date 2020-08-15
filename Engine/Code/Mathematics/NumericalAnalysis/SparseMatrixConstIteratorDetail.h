// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 17:28)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_DETAIL_H

#include "SparseMatrixConstIterator.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
template <typename Real>
Mathematics::SparseMatrixConstIterator<Real>
	::SparseMatrixConstIterator() noexcept
	:m_Iter{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::SparseMatrixConstIterator<Real>
	::SparseMatrixConstIterator(const SparseMatrixConstIter& iter) noexcept
	:m_Iter{ iter }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::SparseMatrixConstIterator<Real>
	::IsValid() const  noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::SparseMatrixConstIterator<Real>
	::increment()
{
	MATHEMATICS_CLASS_IS_VALID_9;

	++m_Iter;
}

template <typename Real>
bool Mathematics::SparseMatrixConstIterator<Real>
	::equal(const ClassType& other) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Iter == other.m_Iter;
}

template <typename Real>
typename const Mathematics::SparseMatrixConstIterator<Real>::SparseMatrixConstIter&
Mathematics::SparseMatrixConstIterator<Real>
	::dereference() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Iter;
}

template <typename Real>
const typename  Mathematics::SparseMatrixConstIterator<Real>::SparseMatrixIndexMap::key_type Mathematics::SparseMatrixConstIterator<Real>
	::GetKey() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Iter->first;
}

template <typename Real>
const typename  Mathematics::SparseMatrixConstIterator<Real>::SparseMatrixIndexMap::mapped_type Mathematics::SparseMatrixConstIterator<Real>
	::GetMapped() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Iter->second;
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_DETAIL_H