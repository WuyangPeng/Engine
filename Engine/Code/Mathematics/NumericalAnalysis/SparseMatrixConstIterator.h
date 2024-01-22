/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_H

#include "Mathematics/MathematicsDll.h"

#include "SparseMatrixIndex.h"

#include "System/Helper/PragmaWarning/IteratorFacade.h"

#include <map>

namespace Mathematics
{
    template <typename Real>
    class SparseMatrixConstIterator final : public boost::iterator_facade<SparseMatrixConstIterator<Real>,
                                                                          typename std::map<SparseMatrixIndex, Real>::const_iterator,
                                                                          boost::forward_traversal_tag>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SparseMatrixConstIterator<Real>;

        using SparseMatrixIndexContainer = std::map<SparseMatrixIndex, Real>;
        using SparseMatrixConstIter = typename SparseMatrixIndexContainer::const_iterator;
        using SparseMatrixKey = typename SparseMatrixIndexContainer::key_type;
        using SparseMatrixMapped = typename SparseMatrixIndexContainer::mapped_type;

    public:
        SparseMatrixConstIterator() noexcept;
        explicit SparseMatrixConstIterator(const SparseMatrixConstIter& iter) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD SparseMatrixKey GetKey() const noexcept;
        NODISCARD SparseMatrixMapped GetMapped() const noexcept;

    private:
        friend class boost::iterator_core_access;
        void increment() noexcept;
        NODISCARD bool equal(const SparseMatrixConstIterator& rhs) const noexcept;
        NODISCARD const SparseMatrixConstIter& dereference() const noexcept;

    private:
        SparseMatrixConstIter iter;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_H