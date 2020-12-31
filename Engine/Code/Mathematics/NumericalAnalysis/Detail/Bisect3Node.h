///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 18:42)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_H

#include "Mathematics/MathematicsDll.h"

#include <boost/noncopyable.hpp>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Bisect3Node final : private boost::noncopyable
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect3Node<Real>;
        using Bisect3NodeSharedPtr = std::shared_ptr<Bisect3Node>;
        using ConstBisect3NodeSharedPtr = std::shared_ptr<const Bisect3Node>;

    public:
        Bisect3Node(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetX() const noexcept;
        [[nodiscard]] Real GetY() const noexcept;
        [[nodiscard]] Real GetZ() const noexcept;
        [[nodiscard]] Real GetFunctionResult0() const noexcept;
        [[nodiscard]] Real GetFunctionResult1() const noexcept;
        [[nodiscard]] Real GetFunctionResult2() const noexcept;

        [[nodiscard]] Bisect3NodeSharedPtr GetXNext() noexcept;
        [[nodiscard]] Bisect3NodeSharedPtr GetYNext() noexcept;
        [[nodiscard]] Bisect3NodeSharedPtr GetZNext() noexcept;
        [[nodiscard]] ConstBisect3NodeSharedPtr GetXNext() const noexcept;
        [[nodiscard]] ConstBisect3NodeSharedPtr GetYNext() const noexcept;
        [[nodiscard]] ConstBisect3NodeSharedPtr GetZNext() const noexcept;

        void AddXNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2);
        void AddYNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2);
        void AddZNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2);
        void AddXNextNode(const Bisect3NodeSharedPtr& node) noexcept;
        void AddYNextNode(const Bisect3NodeSharedPtr& node) noexcept;
        void AddZNextNode(const Bisect3NodeSharedPtr& node) noexcept;

        [[nodiscard]] bool IsFunctionResult0SameSign() const noexcept;
        [[nodiscard]] bool IsFunctionResult1SameSign() const noexcept;
        [[nodiscard]] bool IsFunctionResult2SameSign() const noexcept;

    private:
        Real m_X;
        Real m_Y;
        Real m_Z;
        Real m_FunctionResult0;
        Real m_FunctionResult1;
        Real m_FunctionResult2;
        Bisect3NodeSharedPtr m_XNext;
        Bisect3NodeSharedPtr m_YNext;
        Bisect3NodeSharedPtr m_ZNext;
    };

    using FloatBisect3Node = Bisect3Node<float>;
    using DoubleBisect3Node = Bisect3Node<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_H
