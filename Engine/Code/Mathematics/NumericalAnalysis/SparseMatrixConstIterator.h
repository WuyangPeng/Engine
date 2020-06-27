// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_H

#include "Mathematics/MathematicsDll.h"

#include "SparseMatrixIndex.h"

#include "System/Helper/PragmaWarning/IteratorFacade.h"
#include <map>

namespace Mathematics
{
	template <typename Real>
	class SparseMatrixConstIterator : public boost::iterator_facade<SparseMatrixConstIterator<Real>,
																	typename std::map<SparseMatrixIndex, Real>::const_iterator,
																	boost::forward_traversal_tag>
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = SparseMatrixConstIterator<Real>;
		using SparseMatrixIndexMap = typename std::map<SparseMatrixIndex, Real>;
		using SparseMatrixConstIter = typename SparseMatrixIndexMap::const_iterator;

	public:
		SparseMatrixConstIterator();
		explicit SparseMatrixConstIterator(const SparseMatrixConstIter& iter);

		CLASS_INVARIANT_DECLARE;

		const typename  SparseMatrixIndexMap::key_type GetKey() const;
		const typename  SparseMatrixIndexMap::mapped_type GetMapped()const;

	private:
		friend class boost::iterator_core_access;
		void increment();
		bool equal(const ClassType& other) const;
		const SparseMatrixConstIter& dereference() const;

	private:
		SparseMatrixConstIter m_Iter;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_H