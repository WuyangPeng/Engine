///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/26 10:14)

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
        using SparseMatrixIndexContainer = typename std::map<SparseMatrixIndex, Real>;
        using SparseMatrixConstIter = typename SparseMatrixIndexContainer::const_iterator;
        using SparseMatrixKey = typename SparseMatrixIndexContainer::key_type;
        using SparseMatrixMapped = typename SparseMatrixIndexContainer::mapped_type;

    public:
        SparseMatrixConstIterator() noexcept;
        explicit SparseMatrixConstIterator(const SparseMatrixConstIter& iter) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const SparseMatrixKey GetKey() const noexcept;
        [[nodiscard]] const SparseMatrixMapped GetMapped() const noexcept;

    private:
        friend class boost::iterator_core_access;
        void increment() noexcept;
        [[nodiscard]] bool equal(const SparseMatrixConstIterator& other) const noexcept;
        [[nodiscard]] const SparseMatrixConstIter& dereference() const noexcept;

    private:
        SparseMatrixConstIter m_Iter;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_CONST_ITERATOR_H