// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 15:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_CONST_ITERATOR_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_CONST_ITERATOR_H

#include "Mathematics/MathematicsDll.h"

#include <boost/iterator/iterator_facade.hpp>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class LinearSystemConstIterator :
		public boost::iterator_facade<LinearSystemConstIterator<Real>,typename std::vector<Real>::const_iterator,boost::forward_traversal_tag>
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