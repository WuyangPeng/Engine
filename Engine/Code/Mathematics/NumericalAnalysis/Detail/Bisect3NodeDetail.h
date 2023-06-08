///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:34)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_DETAIL_H

#include "Bisect3Node.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Bisect3Node<Real>::Bisect3Node(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2) noexcept
    : nodeX{ x },
      nodeY{ y },
      nodeZ{ z },
      nodeFunctionResult0{ functionResult0 },
      nodeFunctionResult1{ functionResult1 },
      nodeFunctionResult2{ functionResult2 },
      xNext{},
      yNext{},
      zNext{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect3Node<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Bisect3Node<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return nodeX;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return nodeY;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return nodeZ;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>::GetFunctionResult0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return nodeFunctionResult0;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>::GetFunctionResult1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return nodeFunctionResult1;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>::GetFunctionResult2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return nodeFunctionResult2;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::Bisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetXNext() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return xNext;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::Bisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetYNext() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return yNext;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::Bisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetZNext() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return zNext;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::ConstBisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetXNext() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xNext;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::ConstBisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetYNext() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yNext;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::ConstBisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetZNext() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zNext;
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddXNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    xNext = std::make_shared<Bisect3Node>(x, y, z, functionResult0, functionResult1, functionResult2);
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddYNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    yNext = std::make_shared<Bisect3Node>(x, y, z, functionResult0, functionResult1, functionResult2);
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddZNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    zNext = std::make_shared<Bisect3Node>(x, y, z, functionResult0, functionResult1, functionResult2);
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddXNextNode(const Bisect3NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    xNext = node;
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddYNextNode(const Bisect3NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    yNext = node;
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddZNextNode(const Bisect3NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    zNext = node;
}

template <typename Real>
bool Mathematics::Bisect3Node<Real>::IsFunctionResult0SameSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto symbol = Math<Real>::Sign(nodeFunctionResult0);

    if (symbol == NumericalValueSymbol::Zero)
    {
        return false;
    }

    if (xNext != nullptr)
    {
        if (Math<Real>::Sign(xNext->GetFunctionResult0()) != symbol)
        {
            return false;
        }
        else
        {
            const auto xNextYNext = xNext->GetYNext();

            if (xNextYNext != nullptr && Math<Real>::Sign(xNextYNext->GetFunctionResult0()) != symbol)
            {
                return false;
            }
        }
    }

    if (yNext != nullptr && Math<Real>::Sign(yNext->GetFunctionResult0()) != symbol)
    {
        return false;
    }

    if (zNext != nullptr)
    {
        if (Math<Real>::Sign(zNext->GetFunctionResult0()) != symbol)
        {
            return false;
        }
        else
        {
            auto zNextXNext = zNext->GetXNext();

            if (zNextXNext != nullptr)
            {
                if (Math<Real>::Sign(zNextXNext->GetFunctionResult0()) != symbol)
                {
                    return false;
                }
                else
                {
                    auto zNextXNextYNext = zNextXNext->GetYNext();

                    if (zNextXNextYNext != nullptr && Math<Real>::Sign(zNextXNextYNext->GetFunctionResult0()) != symbol)
                    {
                        return false;
                    }
                }
            }

            auto zNextYNext = zNext->GetYNext();

            if (zNextYNext != nullptr && Math<Real>::Sign(zNextYNext->GetFunctionResult0()) != symbol)
            {
                return false;
            }
        }
    }

    return true;
}

template <typename Real>
bool Mathematics::Bisect3Node<Real>::IsFunctionResult1SameSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto symbol = Math<Real>::Sign(nodeFunctionResult1);

    if (symbol == NumericalValueSymbol::Zero)
    {
        return false;
    }

    if (xNext != nullptr)
    {
        if (Math<Real>::Sign(xNext->GetFunctionResult1()) != symbol)
        {
            return false;
        }
        else
        {
            const auto xNextYNext = xNext->GetYNext();

            if (xNextYNext != nullptr && Math<Real>::Sign(xNextYNext->GetFunctionResult1()) != symbol)
            {
                return false;
            }
        }
    }

    if (yNext != nullptr && Math<Real>::Sign(yNext->GetFunctionResult1()) != symbol)
    {
        return false;
    }

    if (zNext != nullptr)
    {
        if (Math<Real>::Sign(zNext->GetFunctionResult1()) != symbol)
        {
            return false;
        }
        else
        {
            auto zNextXNext = zNext->GetXNext();

            if (zNextXNext != nullptr)
            {
                if (Math<Real>::Sign(zNextXNext->GetFunctionResult1()) != symbol)
                {
                    return false;
                }
                else
                {
                    const auto zNextXNextYNext = zNextXNext->GetYNext();

                    if (zNextXNextYNext != nullptr && Math<Real>::Sign(zNextXNextYNext->GetFunctionResult1()) != symbol)
                    {
                        return false;
                    }
                }
            }

            const auto zNextYNext = zNext->GetYNext();

            if (zNextYNext != nullptr && Math<Real>::Sign(zNextYNext->GetFunctionResult1()) != symbol)
            {
                return false;
            }
        }
    }

    return true;
}

template <typename Real>
bool Mathematics::Bisect3Node<Real>::IsFunctionResult2SameSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto symbol = Math<Real>::Sign(nodeFunctionResult2);

    if (symbol == NumericalValueSymbol::Zero)
    {
        return false;
    }

    if (xNext != nullptr)
    {
        if (Math<Real>::Sign(xNext->GetFunctionResult2()) != symbol)
        {
            return false;
        }
        else
        {
            const auto xNextYNext = xNext->GetYNext();

            if (xNextYNext != nullptr && Math<Real>::Sign(xNextYNext->GetFunctionResult2()) != symbol)
            {
                return false;
            }
        }
    }

    if (yNext != nullptr && Math<Real>::Sign(yNext->GetFunctionResult2()) != symbol)
    {
        return false;
    }

    if (zNext != nullptr)
    {
        if (Math<Real>::Sign(zNext->GetFunctionResult2()) != symbol)
        {
            return false;
        }
        else
        {
            auto zNextXNext = zNext->GetXNext();

            if (zNextXNext != nullptr)
            {
                if (Math<Real>::Sign(zNextXNext->GetFunctionResult2()) != symbol)
                {
                    return false;
                }
                else
                {
                    const auto zNextXNextYNext = zNextXNext->GetYNext();

                    if (zNextXNextYNext != nullptr && Math<Real>::Sign(zNextXNextYNext->GetFunctionResult2()) != symbol)
                    {
                        return false;
                    }
                }
            }

            const auto zNextYNext = zNext->GetYNext();

            if (zNextYNext != nullptr && Math<Real>::Sign(zNextYNext->GetFunctionResult2()) != symbol)
            {
                return false;
            }
        }
    }

    return true;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_DETAIL_H
