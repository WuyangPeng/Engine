// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 15:49)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_H

#include "Mathematics/MathematicsDll.h"

#include <boost/iterator/iterator_facade.hpp>

namespace Mathematics
{
	template <typename ResultConstIter>
	class EquationResultConstIterator : public boost::iterator_facade<EquationResultConstIterator<ResultConstIter>, ResultConstIter, boost::forward_traversal_tag>
    {
    public:
		using ClassType = EquationResultConstIterator<ResultConstIter>;
		using ResultValueType = typename ResultConstIter::value_type;
        
    public:
		EquationResultConstIterator();
		explicit EquationResultConstIterator(const ResultConstIter& iter);
        
        CLASS_INVARIANT_DECLARE;

		const ResultValueType operator*() const;
		 
	private:
		friend class boost::iterator_core_access; 
		void increment();
		bool equal(const ClassType& other) const;
		const ResultConstIter& dereference() const;

	private:	
		ResultConstIter m_Iter;
	};

	template <typename ResultConstIter>
	std::ostream& operator<< (std::ostream& os,const EquationResultConstIterator<ResultConstIter>& iter);
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_H