///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 11:36)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning/IteratorFacade.h"

namespace Mathematics
{
    template <typename ResultConstIter>
    class EquationResultConstIterator final : public boost::iterator_facade<EquationResultConstIterator<ResultConstIter>, ResultConstIter, boost::forward_traversal_tag>
    {
    public:
        using ClassType = EquationResultConstIterator<ResultConstIter>;

        using ResultValueType = typename ResultConstIter::value_type;

    public:
        EquationResultConstIterator();
        explicit EquationResultConstIterator(const ResultConstIter& iter) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ResultValueType operator*() const noexcept;

    private:
        friend class boost::iterator_core_access;
        void increment() noexcept;
        NODISCARD bool equal(const EquationResultConstIterator& other) const noexcept;
        NODISCARD const ResultConstIter& dereference() const;

    private:
        ResultConstIter iter;
    };

    template <typename ResultConstIter>
    std::ostream& operator<<(std::ostream& os, const EquationResultConstIterator<ResultConstIter>& iter);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_H