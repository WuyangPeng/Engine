// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 14:32)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_DETAIL_H

#include "EquationResultConstIterator.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26487) 
template <typename ResultConstIter>
Mathematics::EquationResultConstIterator<ResultConstIter>
	::EquationResultConstIterator()
	:m_Iter{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename ResultConstIter>
Mathematics::EquationResultConstIterator<ResultConstIter>
	::EquationResultConstIterator(const ResultConstIter& iter) noexcept
	:m_Iter{ iter }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ResultConstIter>
bool Mathematics::EquationResultConstIterator<ResultConstIter>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename ResultConstIter>
void Mathematics::EquationResultConstIterator<ResultConstIter>
	::increment()
{
	MATHEMATICS_CLASS_IS_VALID_9;

	++m_Iter;
}

template <typename ResultConstIter>
bool Mathematics::EquationResultConstIterator<ResultConstIter>
	::equal(const ClassType& other) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Iter == other.m_Iter;
}

template <typename ResultConstIter>
const ResultConstIter& Mathematics::EquationResultConstIterator<ResultConstIter>
	::dereference() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Iter;
}

template <typename ResultConstIter>
const typename ResultConstIter::value_type Mathematics::EquationResultConstIterator<ResultConstIter>
	::operator*() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return *m_Iter;
}

template <typename ResultConstIter>
std::ostream& Mathematics
	::operator<<(std::ostream& os, const EquationResultConstIterator<ResultConstIter>& iter)
{
	os << *iter;

	return os;
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_DETAIL_H