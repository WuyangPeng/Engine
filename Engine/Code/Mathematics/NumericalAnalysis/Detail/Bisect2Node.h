///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 15:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_H

#include "Mathematics/MathematicsDll.h"

#include <boost/noncopyable.hpp>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Bisect2Node final : private boost::noncopyable
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect2Node<Real>;
        using Bisect2NodeSharedPtr = std::shared_ptr<Bisect2Node>;
        using ConstBisect2NodeSharedPtr = std::shared_ptr<const Bisect2Node>;

    public:
        Bisect2Node(Real x, Real y, Real functionResult0, Real functionResult1) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetX() const noexcept;
        [[nodiscard]] Real GetY() const noexcept;
        [[nodiscard]] Real GetFunctionResult0() const noexcept;
        [[nodiscard]] Real GetFunctionResult1() const noexcept;

        [[nodiscard]] Bisect2NodeSharedPtr GetXNext() noexcept;
        [[nodiscard]] Bisect2NodeSharedPtr GetYNext() noexcept;
        [[nodiscard]] ConstBisect2NodeSharedPtr GetXNext() const;
        [[nodiscard]] ConstBisect2NodeSharedPtr GetYNext() const;

        void AddXNextNode(Real x, Real y, Real functionResult0, Real functionResult1);
        void AddYNextNode(Real x, Real y, Real functionResult0, Real functionResult1);
        void AddXNextNode(const Bisect2NodeSharedPtr& node) noexcept;
        void AddYNextNode(const Bisect2NodeSharedPtr& node) noexcept;

        [[nodiscard]] bool IsFunctionResult0SameSign() const noexcept;
        [[nodiscard]] bool IsFunctionResult1SameSign() const noexcept;

    private:
        Real m_X;
        Real m_Y;
        Real m_FunctionResult0;
        Real m_FunctionResult1;
        Bisect2NodeSharedPtr m_XNext;
        Bisect2NodeSharedPtr m_YNext; 
    };

    using FloatBisect2Node = Bisect2Node<float>;
    using DoubleBisect2Node = Bisect2Node<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_H
