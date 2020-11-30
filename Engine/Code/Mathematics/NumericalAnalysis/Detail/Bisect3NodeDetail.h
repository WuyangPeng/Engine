///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 19:02)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_DETAIL_H

#include "Bisect3Node.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Bisect3Node<Real>::Bisect3Node(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2) noexcept
    : m_X{ x },
      m_Y{ y },
      m_Z{ z },
      m_FunctionResult0{ functionResult0 },
      m_FunctionResult1{ functionResult1 },
      m_FunctionResult2{ functionResult2 },
      m_XNext{},
      m_YNext{},
      m_ZNext{} 
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

    return m_X;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Y;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Z;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>::GetFunctionResult0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_FunctionResult0;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>::GetFunctionResult1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_FunctionResult1;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>::GetFunctionResult2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_FunctionResult2;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::Bisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetXNext() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return m_XNext;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::Bisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetYNext() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return m_YNext;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::Bisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetZNext() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return m_ZNext;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::ConstBisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetXNext() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_XNext;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::ConstBisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetYNext() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_YNext;
}

template <typename Real>
typename Mathematics::Bisect3Node<Real>::ConstBisect3NodeSharedPtr Mathematics::Bisect3Node<Real>::GetZNext() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_ZNext;
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddXNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_XNext = std::make_shared<Bisect3Node>(x, y, z, functionResult0, functionResult1, functionResult2);
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddYNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_YNext = std::make_shared<Bisect3Node>(x, y, z, functionResult0, functionResult1, functionResult2);
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddZNextNode(Real x, Real y, Real z, Real functionResult0, Real functionResult1, Real functionResult2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_ZNext = std::make_shared<Bisect3Node>(x, y, z, functionResult0, functionResult1, functionResult2);
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddXNextNode(const Bisect3NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_XNext = node;
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddYNextNode(const Bisect3NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_YNext = node;
}

template <typename Real>
void Mathematics::Bisect3Node<Real>::AddZNextNode(const Bisect3NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_ZNext = node;
}

template <typename Real>
bool Mathematics::Bisect3Node<Real>::IsFunctionResult0SameSign() const noexcept
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
            const auto xNextYNext = m_XNext->GetYNext();

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

    if (m_ZNext != nullptr)
    {
        if (Math<Real>::Sign(m_ZNext->GetFunctionResult0()) != symbol)
        {
            return false;
        }
        else
        {
            auto zNextXNext = m_ZNext->GetXNext();

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

            auto zNextYNext = m_ZNext->GetYNext();

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
            const auto xNextYNext = m_XNext->GetYNext();

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

    if (m_ZNext != nullptr)
    {
        if (Math<Real>::Sign(m_ZNext->GetFunctionResult1()) != symbol)
        {
            return false;
        }
        else
        {
            auto zNextXNext = m_ZNext->GetXNext();

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

            const auto zNextYNext = m_ZNext->GetYNext();

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

    const auto symbol = Math<Real>::Sign(m_FunctionResult2);

    if (symbol == NumericalValueSymbol::Zero)
    {
        return false;
    }

    if (m_XNext != nullptr)
    {
        if (Math<Real>::Sign(m_XNext->GetFunctionResult2()) != symbol)
        {
            return false;
        }
        else
        {
            const auto xNextYNext = m_XNext->GetYNext();

            if (xNextYNext != nullptr && Math<Real>::Sign(xNextYNext->GetFunctionResult2()) != symbol)
            {
                return false;
            }
        }
    }

    if (m_YNext != nullptr && Math<Real>::Sign(m_YNext->GetFunctionResult2()) != symbol)
    {
        return false;
    }

    if (m_ZNext != nullptr)
    {
        if (Math<Real>::Sign(m_ZNext->GetFunctionResult2()) != symbol)
        {
            return false;
        }
        else
        {
            auto zNextXNext = m_ZNext->GetXNext();

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

            const auto zNextYNext = m_ZNext->GetYNext();

            if (zNextYNext != nullptr && Math<Real>::Sign(zNextYNext->GetFunctionResult2()) != symbol)
            {
                return false;
            }
        }
    }

    return true;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_DETAIL_H
