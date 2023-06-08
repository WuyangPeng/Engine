///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:24)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/BaseFwd.h"

#include <boost/noncopyable.hpp>
#include <memory>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Bisect2Node final : private boost::noncopyable
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect2Node<Real>;
        using Math = Math<Real>;
        using Bisect2NodeSharedPtr = std::shared_ptr<Bisect2Node>;
        using ConstBisect2NodeSharedPtr = std::shared_ptr<const Bisect2Node>;

    public:
        Bisect2Node(Real x, Real y, Real functionResult0, Real functionResult1) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetX() const noexcept;
        NODISCARD Real GetY() const noexcept;
        NODISCARD Real GetFunctionResult0() const noexcept;
        NODISCARD Real GetFunctionResult1() const noexcept;

        NODISCARD Bisect2NodeSharedPtr GetXNext() noexcept;
        NODISCARD Bisect2NodeSharedPtr GetYNext() noexcept;
        NODISCARD ConstBisect2NodeSharedPtr GetXNext() const noexcept;
        NODISCARD ConstBisect2NodeSharedPtr GetYNext() const noexcept;

        void AddXNextNode(Real x, Real y, Real functionResult0, Real functionResult1);
        void AddYNextNode(Real x, Real y, Real functionResult0, Real functionResult1);
        void AddXNextNode(const Bisect2NodeSharedPtr& node) noexcept;
        void AddYNextNode(const Bisect2NodeSharedPtr& node) noexcept;

        NODISCARD bool IsFunctionResult0SameSign() const noexcept;
        NODISCARD bool IsFunctionResult1SameSign() const noexcept;

    private:
        Real nodeX;
        Real nodeY;
        Real nodeFunctionResult0;
        Real nodeFunctionResult1;
        Bisect2NodeSharedPtr xNext;
        Bisect2NodeSharedPtr yNext;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_H
