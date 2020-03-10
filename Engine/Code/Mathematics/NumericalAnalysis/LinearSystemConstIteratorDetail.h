// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/09 17:01)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_CONST_ITERATOR_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_CONST_ITERATOR_DETAIL_H

#include "LinearSystemConstIterator.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::LinearSystemConstIterator<Real>
	::LinearSystemConstIterator() 
	:m_Iter{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::LinearSystemConstIterator<Real>
	::LinearSystemConstIterator(const OutputConstIter& iter)
	:m_Iter{ iter }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::LinearSystemConstIterator<Real>
	::IsValid() const  noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::LinearSystemConstIterator<Real>
	::increment()
{
	MATHEMATICS_CLASS_IS_VALID_9;

	++m_Iter;
}

template <typename Real>
bool Mathematics::LinearSystemConstIterator<Real>
	::equal( const ClassType& other ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Iter == other.m_Iter;
}

template <typename Real>
typename const Mathematics::LinearSystemConstIterator<Real>::OutputConstIter& Mathematics::LinearSystemConstIterator<Real>
	::dereference() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Iter;
}

template <typename Real>
typename const Mathematics::LinearSystemConstIterator<Real>::OutputConstIter::value_type Mathematics::LinearSystemConstIterator<Real>
	::operator*() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return *m_Iter;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_CONST_ITERATOR_DETAIL_H