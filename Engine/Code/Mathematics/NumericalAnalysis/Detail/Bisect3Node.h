///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/14 13:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_H

#include "Mathematics/MathematicsDll.h"

#include <boost/noncopyable.hpp>
#include <memory>
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

        NODISCARD Real GetX() const noexcept;
        NODISCARD Real GetY() const noexcept;
        NODISCARD Real GetZ() const noexcept;
        NODISCARD Real GetFunctionResult0() const noexcept;
        NODISCARD Real GetFunctionResult1() const noexcept;
        NODISCARD Real GetFunctionResult2() const noexcept;

        NODISCARD Bisect3NodeSharedPtr GetXNext() noexcept;
        NODISCARD Bisect3NodeSharedPtr GetYNext() noexcept;
        NODISCARD Bisect3NodeSharedPtr GetZNext() noexcept;
        NODISCARD ConstBisect3NodeSharedPtr GetXNext() const noexcept;
        NODISCARD ConstBisect3NodeSharedPtr GetYNext() const noexcept;
        NODISCARD ConstBisect3NodeSharedPtr GetZNext() const noexcept;

        void AddXNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2);
        void AddYNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2);
        void AddZNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2);
        void AddXNextNode(const Bisect3NodeSharedPtr& node) noexcept;
        void AddYNextNode(const Bisect3NodeSharedPtr& node) noexcept;
        void AddZNextNode(const Bisect3NodeSharedPtr& node) noexcept;

        NODISCARD bool IsFunctionResult0SameSign() const noexcept;
        NODISCARD bool IsFunctionResult1SameSign() const noexcept;
        NODISCARD bool IsFunctionResult2SameSign() const noexcept;

    private:
        Real nodeX;
        Real nodeY;
        Real nodeZ;
        Real nodeFunctionResult0;
        Real nodeFunctionResult1;
        Real nodeFunctionResult2;
        Bisect3NodeSharedPtr xNext;
        Bisect3NodeSharedPtr yNext;
        Bisect3NodeSharedPtr zNext;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_H
