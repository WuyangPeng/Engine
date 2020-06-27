// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:49)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_CONST_ITERATOR_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_CONST_ITERATOR_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning/IteratorFacade.h"
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class LinearSystemConstIterator :
		public boost::iterator_facade<LinearSystemConstIterator<Real>, typename std::vector<Real>::const_iterator, boost::forward_traversal_tag>
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = LinearSystemConstIterator<Real>;
		using OutputConstIter = typename std::vector<Real>::const_iterator;

	public:
		LinearSystemConstIterator();
		explicit LinearSystemConstIterator(const OutputConstIter& iter);

		CLASS_INVARIANT_DECLARE;

		typename const OutputConstIter::value_type operator*() const;

	private:
		friend class boost::iterator_core_access;
		void increment();
		bool equal(const ClassType& other) const;
		const OutputConstIter& dereference() const;

	private:
		OutputConstIter m_Iter;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_CONST_ITERATOR_H