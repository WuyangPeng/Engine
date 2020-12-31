///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 15:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_DETAIL_H

#include "Bisect2Node.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Bisect2Node<Real>::Bisect2Node(Real x, Real y, Real functionResult0, Real functionResult1) noexcept
    : m_X{ x },
      m_Y{ y },
      m_FunctionResult0{ functionResult0 },
      m_FunctionResult1{ functionResult1 },
      m_XNext{},
      m_YNext{}
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

    return m_X;
}

template <typename Real>
Real Mathematics::Bisect2Node<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Y;
}

template <typename Real>
Real Mathematics::Bisect2Node<Real>::GetFunctionResult0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_FunctionResult0;
}

template <typename Real>
Real Mathematics::Bisect2Node<Real>::GetFunctionResult1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_FunctionResult1;
}

template <typename Real>
typename Mathematics::Bisect2Node<Real>::Bisect2NodeSharedPtr Mathematics::Bisect2Node<Real>::GetXNext() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return m_XNext;
}

template <typename Real>
typename Mathematics::Bisect2Node<Real>::Bisect2NodeSharedPtr Mathematics::Bisect2Node<Real>::GetYNext() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return m_YNext;
}

template <typename Real>
typename Mathematics::Bisect2Node<Real>::ConstBisect2NodeSharedPtr Mathematics::Bisect2Node<Real>::GetXNext() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_XNext;
}

template <typename Real>
typename Mathematics::Bisect2Node<Real>::ConstBisect2NodeSharedPtr Mathematics::Bisect2Node<Real>::GetYNext() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_YNext;
}

template <typename Real>
void Mathematics::Bisect2Node<Real>::AddXNextNode(Real x, Real y, Real functionResult0, Real functionResult1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_XNext = std::make_shared<Bisect2Node>(x, y, functionResult0, functionResult1);
}

template <typename Real>
void Mathematics::Bisect2Node<Real>::AddYNextNode(Real x, Real y, Real functionResult0, Real functionResult1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_YNext = std::make_shared<Bisect2Node>(x, y, functionResult0, functionResult1);
}

template <typename Real>
void Mathematics::Bisect2Node<Real>::AddXNextNode(const Bisect2NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_XNext = node;
}

template <typename Real>
void Mathematics::Bisect2Node<Real>::AddYNextNode(const Bisect2NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_YNext = node;
}

template <typename Real>
bool Mathematics::Bisect2Node<Real>::IsFunctionResult0SameSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto symbol = Math<Real>::Sign(m_FunctionResult0);

    if (symbol == NumericalValueSymbol::Zero)
    {
        return false;
    }

    if (m_XNext != nullptr)
    {
        if (Math<Real>::Sign(m_XNext->GetFunctionResult0()) != symbol)
        {
            return false;
        }
        else
        {
            auto xNextYNext = m_XNext->GetYNext();

            if (xNextYNext != nullptr && Math<Real>::Sign(xNextYNext->GetFunctionResult0()) != symbol)
            {
                return false;
            }
        }
    }

    if (m_YNext != nullptr && Math<Real>::Sign(m_YNext->GetFunctionResult0()) != symbol)
    {
        return false;
    }

    return true;
}

template <typename Real>
bool Mathematics::Bisect2Node<Real>::IsFunctionResult1SameSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto symbol = Math<Real>::Sign(m_FunctionResult1);

    if (symbol == NumericalValueSymbol::Zero)
    {
        return false;
    }

    if (m_XNext != nullptr)
    {
        if (Math<Real>::Sign(m_XNext->GetFunctionResult1()) != symbol)
        {
            return false;
        }
        else
        {
            auto xNextYNext = m_XNext->GetYNext();

            if (xNextYNext != nullptr && Math<Real>::Sign(xNextYNext->GetFunctionResult1()) != symbol)
            {
                return false;
            }
        }
    }

    if (m_YNext != nullptr && Math<Real>::Sign(m_YNext->GetFunctionResult1()) != symbol)
    {
        return false;
    }

    return true;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_DETAIL_H
