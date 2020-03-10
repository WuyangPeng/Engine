// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/09 14:08)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_DETAIL_H

#include "Bisect2Node.h"
#include "Mathematics/Base/Math.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect2Node<Real>
	::Bisect2Node(Real x, Real y,Real firstFunctionResult,Real secondFunctionResult)
	:m_X{ x }, m_Y{ y }, m_FirstFunctionResult{ firstFunctionResult },
	 m_SecondFunctionResult{ secondFunctionResult }, m_XNext{ nullptr }, m_YNext{ nullptr },
	 m_ReleaseXNext{ false }, m_ReleaseYNext{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Bisect2Node<Real>
	::~Bisect2Node ()
{
    if(m_ReleaseXNext)
	{
        DELETE0(m_XNext);
	}
    
	if (m_ReleaseYNext)
	{
		DELETE0(m_YNext);
	}
    
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect2Node<Real>
	::IsValid() const noexcept
{
    return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Bisect2Node<Real>
	::GetX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_X;
}

template <typename Real>
Real Mathematics::Bisect2Node<Real>
	::GetY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_Y;
}

template <typename Real>
Real Mathematics::Bisect2Node<Real>
	::GetFirstFunctionResult() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_FirstFunctionResult;
}

template <typename Real>
Real Mathematics::Bisect2Node<Real>
	::GetSecondFunctionResult() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_SecondFunctionResult;
}

template <typename Real>
Mathematics::Bisect2Node<Real>* Mathematics::Bisect2Node<Real>
	::GetXNext()
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    return m_XNext;
}

template <typename Real>
Mathematics::Bisect2Node<Real>* Mathematics::Bisect2Node<Real>
	::GetYNext()
{
	MATHEMATICS_CLASS_IS_VALID_9;
    
    return m_YNext;
}

template <typename Real>
const Mathematics::Bisect2Node<Real>* Mathematics::Bisect2Node<Real>
	::GetXNext() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_XNext;
}

template <typename Real>
const Mathematics::Bisect2Node<Real>* Mathematics::Bisect2Node<Real>
	::GetYNext() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_YNext;
}

template <typename Real>
void Mathematics::Bisect2Node<Real>
	::AddXNextNode (Real x, Real y,Real firstFunctionResult,Real secondFunctionResult)
{
	MATHEMATICS_CLASS_IS_VALID_9;
    
	if (m_ReleaseXNext)
	{
		DELETE0(m_XNext);
	}
    
	m_XNext = NEW0 Bisect2Node{ x,y,firstFunctionResult,secondFunctionResult };
    m_ReleaseXNext = true;
}

template <typename Real>
void Mathematics::Bisect2Node<Real>
	::AddYNextNode (Real x, Real y,Real firstFunctionResult,Real secondFunctionResult)
{
	MATHEMATICS_CLASS_IS_VALID_9;
    
	if (m_ReleaseYNext)
	{
		DELETE0(m_YNext);
	}
    
	m_YNext = NEW0 Bisect2Node{ x,y,firstFunctionResult, secondFunctionResult };
    m_ReleaseYNext = true;
}

template <typename Real>
void Mathematics::Bisect2Node<Real>
	::AddXNextNode (Bisect2Node* node)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if(node != m_XNext)
	{		
		if (m_ReleaseXNext)
		{
			DELETE0(m_XNext);
		}
    
		m_XNext = node;
		m_ReleaseXNext = false;
	}
}

template <typename Real>
void Mathematics::Bisect2Node<Real>
	::AddYNextNode (Bisect2Node* node)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	
	if(node != m_YNext)
	{    
		if (m_ReleaseYNext)
		{
			DELETE0(m_YNext);
		}
    
		m_YNext = node;
		m_ReleaseYNext = false;
	}
}

template <typename Real>
bool Mathematics::Bisect2Node<Real>
	::IsFirstFunctionResultSameSign() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto symbol = Math<Real>::Sign(m_FirstFunctionResult);
    
    if(symbol == NumericalValueSymbol::Zero)
	{
        return false;
	}
    
    if(m_XNext != nullptr)
    {
        if(Math<Real>::Sign(m_XNext->GetFirstFunctionResult()) != symbol)
        {
            return false;
        }
		else
		{
			auto xNextYNext = m_XNext->GetYNext();

			if (xNextYNext != nullptr && Math<Real>::Sign(xNextYNext->GetFirstFunctionResult()) != symbol)
			{
				return false;
			}
		}		
    }
    
	if (m_YNext != nullptr && Math<Real>::Sign(m_YNext->GetFirstFunctionResult()) != symbol)
	{
		return false;
	}
    
    return true;
}

template <typename Real>
bool Mathematics::Bisect2Node<Real>
	::IsSecondFunctionResultSameSign() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
	auto symbol = Math<Real>::Sign(m_SecondFunctionResult);
    
    if(symbol == NumericalValueSymbol::Zero)
	{
        return false;
	}
    
    if(m_XNext != nullptr)
    {
        if(Math<Real>::Sign(m_XNext->GetSecondFunctionResult()) != symbol)
        {
            return false;
        }
		else
		{
			auto xNextYNext = m_XNext->GetYNext();

			if (xNextYNext != nullptr && Math<Real>::Sign(xNextYNext->GetSecondFunctionResult()) != symbol)
			{
				return false;
			}
		}
    }
    
	if (m_YNext != nullptr && Math<Real>::Sign(m_YNext->GetSecondFunctionResult()) != symbol)
	{
		return false;
	}
    
    return true;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_DETAIL_H

