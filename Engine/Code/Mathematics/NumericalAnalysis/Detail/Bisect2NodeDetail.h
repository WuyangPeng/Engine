///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:33)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_DETAIL_H

#include "Bisect2Node.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Bisect2Node<Real>::Bisect2Node(Real x, Real y, Real functionResult0, Real functionResult1) noexcept
    : nodeX{ x },
      nodeY{ y },
      nodeFunctionResult0{ functionResult0 },
      nodeFunctionResult1{ functionResult1 },
      xNext{},
      yNext{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect2Node<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Bisect2Node<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return nodeX;
}

template <typename Real>
Real Mathematics::Bisect2Node<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return nodeY;
}

template <typename Real>
Real Mathematics::Bisect2Node<Real>::GetFunctionResult0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return nodeFunctionResult0;
}

template <typename Real>
Real Mathematics::Bisect2Node<Real>::GetFunctionResult1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return nodeFunctionResult1;
}

template <typename Real>
typename Mathematics::Bisect2Node<Real>::Bisect2NodeSharedPtr Mathematics::Bisect2Node<Real>::GetXNext() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return xNext;
}

template <typename Real>
typename Mathematics::Bisect2Node<Real>::Bisect2NodeSharedPtr Mathematics::Bisect2Node<Real>::GetYNext() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return yNext;
}

template <typename Real>
typename Mathematics::Bisect2Node<Real>::ConstBisect2NodeSharedPtr Mathematics::Bisect2Node<Real>::GetXNext() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xNext;
}

template <typename Real>
typename Mathematics::Bisect2Node<Real>::ConstBisect2NodeSharedPtr Mathematics::Bisect2Node<Real>::GetYNext() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yNext;
}

template <typename Real>
void Mathematics::Bisect2Node<Real>::AddXNextNode(Real x, Real y, Real functionResult0, Real functionResult1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    xNext = std::make_shared<Bisect2Node>(x, y, functionResult0, functionResult1);
}

template <typename Real>
void Mathematics::Bisect2Node<Real>::AddYNextNode(Real x, Real y, Real functionResult0, Real functionResult1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    yNext = std::make_shared<Bisect2Node>(x, y, functionResult0, functionResult1);
}

template <typename Real>
void Mathematics::Bisect2Node<Real>::AddXNextNode(const Bisect2NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    xNext = node;
}

template <typename Real>
void Mathematics::Bisect2Node<Real>::AddYNextNode(const Bisect2NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    yNext = node;
}

template <typename Real>
bool Mathematics::Bisect2Node<Real>::IsFunctionResult0SameSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto symbol = Math::Sign(nodeFunctionResult0);

    if (symbol == NumericalValueSymbol::Zero)
    {
        return false;
    }

    if (xNext != nullptr)
    {
        if (Math::Sign(xNext->GetFunctionResult0()) != symbol)
        {
            return false;
        }
        else
        {
            auto xNextYNext = xNext->GetYNext();

            if (xNextYNext != nullptr && Math::Sign(xNextYNext->GetFunctionResult0()) != symbol)
            {
                return false;
            }
        }
    }

    if (yNext != nullptr && Math::Sign(yNext->GetFunctionResult0()) != symbol)
    {
        return false;
    }

    return true;
}

template <typename Real>
bool Mathematics::Bisect2Node<Real>::IsFunctionResult1SameSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto symbol = Math::Sign(nodeFunctionResult1);

    if (symbol == NumericalValueSymbol::Zero)
    {
        return false;
    }

    if (xNext != nullptr)
    {
        if (Math::Sign(xNext->GetFunctionResult1()) != symbol)
        {
            return false;
        }
        else
        {
            auto xNextYNext = xNext->GetYNext();

            if (xNextYNext != nullptr && Math::Sign(xNextYNext->GetFunctionResult1()) != symbol)
            {
                return false;
            }
        }
    }

    if (yNext != nullptr && Math::Sign(yNext->GetFunctionResult1()) != symbol)
    {
        return false;
    }

    return true;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_DETAIL_H
