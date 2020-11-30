///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/24 18:00)

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

        [[nodiscard]] const ResultValueType operator*() const noexcept;

    private:
        friend class boost::iterator_core_access;
        void increment();
        [[nodiscard]] bool equal(const EquationResultConstIterator& other) const;
        [[nodiscard]] const ResultConstIter& dereference() const;

    private:
        ResultConstIter m_Iter;
    };

    template <typename ResultConstIter>
    std::ostream& operator<<(std::ostream& os, const EquationResultConstIterator<ResultConstIter>& iter);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_CONST_ITERATOR_H