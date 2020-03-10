// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/09 15:25)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_DETAIL_H

#include "Bisect3Node.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect3Node<Real>
	::Bisect3Node(Real x, Real y,Real z,Real firstFunctionResult,Real secondFunctionResult,Real thirdFunctionResult)
	:m_X{ x }, m_Y{ y }, m_Z{ z }, m_FirstFunctionResult{ firstFunctionResult },
	 m_SecondFunctionResult{ secondFunctionResult }, m_ThirdFunctionResult{ thirdFunctionResult },
	 m_XNext{ nullptr }, m_YNext{ nullptr }, m_ZNext{ nullptr },
	 m_ReleaseXNext{ false },m_ReleaseYNext{ false },m_ReleaseZNext{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Bisect3Node<Real>
	::~Bisect3Node ()
{
    if(m_ReleaseXNext)
	{
        DELETE0(m_XNext);
	}
    
    if(m_ReleaseYNext)
	{
        DELETE0(m_YNext);
	}
    
    if(m_ReleaseZNext)
	{
        DELETE0(m_ZNext);
	}
    
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect3Node<Real>
	::IsValid() const noexcept
{
    return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Bisect3Node<Real>
	::GetX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_X;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>
	::GetY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_Y;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>
	::GetZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_Z;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>
	::GetFirstFunctionResult() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_FirstFunctionResult;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>
	::GetSecondFunctionResult() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_SecondFunctionResult;
}

template <typename Real>
Real Mathematics::Bisect3Node<Real>
	::GetThirdFunctionResult() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_ThirdFunctionResult;
}

template <typename Real>
Mathematics::Bisect3Node<Real>* Mathematics::Bisect3Node<Real>
	::GetXNext()
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    return m_XNext;
}

template <typename Real>
Mathematics::Bisect3Node<Real>* Mathematics::Bisect3Node<Real>
	::GetYNext()
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    return m_YNext;
}

template <typename Real>
Mathematics::Bisect3Node<Real>* Mathematics::Bisect3Node<Real>
	::GetZNext()
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    return m_ZNext;
}

template <typename Real>
const Mathematics::Bisect3Node<Real>* Mathematics::Bisect3Node<Real>
	::GetXNext() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_XNext;
}

template <typename Real>
const Mathematics::Bisect3Node<Real>* Mathematics::Bisect3Node<Real>
	::GetYNext() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_YNext;
}

template <typename Real>
const Mathematics::Bisect3Node<Real>* Mathematics::Bisect3Node<Real>
	::GetZNext() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_ZNext;
}

template <typename Real>
void Mathematics::Bisect3Node<Real>
	::AddXNextNode (Real x, Real y,Real z,Real firstFunctionResult,Real secondFunctionResult,Real thirdFunctionResult)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    if(m_ReleaseXNext)
	{
         DELETE0(m_XNext);
	}
    
	m_XNext = NEW0 Bisect3Node{ x,y,z,firstFunctionResult,secondFunctionResult,thirdFunctionResult };
    m_ReleaseXNext = true;
}

template <typename Real>
void Mathematics::Bisect3Node<Real>
	::AddYNextNode (Real x, Real y,Real z, Real firstFunctionResult, Real secondFunctionResult, Real thirdFunctionResult)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    if(m_ReleaseYNext)
	{
        DELETE0(m_YNext);
	}
    
	m_YNext = NEW0 Bisect3Node{ x,y,z,firstFunctionResult,secondFunctionResult,thirdFunctionResult };
    m_ReleaseYNext = true;
}

template <typename Real>
void Mathematics::Bisect3Node<Real>
	::AddZNextNode (Real x, Real y,Real z,Real firstFunctionResult,Real secondFunctionResult,Real thirdFunctionResult)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    if(m_ReleaseZNext)
	{
        DELETE0(m_ZNext);
	}
    
	m_ZNext = NEW0 Bisect3Node{ x,y,z,firstFunctionResult,secondFunctionResult,thirdFunctionResult };
    m_ReleaseZNext = true;
}

template <typename Real>
void Mathematics::Bisect3Node<Real>
	::AddXNextNode (Bisect3Node* node)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
	if(m_XNext != node)
	{
		if(m_ReleaseXNext)
		{
			DELETE0(m_XNext);
		}
    
		m_XNext = node;
		m_ReleaseXNext = false;
	}
}

template <typename Real>
void Mathematics::Bisect3Node<Real>
	::AddYNextNode (Bisect3Node* node)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
	if(m_YNext != node)
	{
		if(m_ReleaseYNext)
		{
			DELETE0(m_YNext);
		}
    
		m_YNext = node;
		m_ReleaseYNext = false;
	}
}

template <typename Real>
void Mathematics::Bisect3Node<Real>
	::AddZNextNode (Bisect3Node* node)
{
    MATHEMATICS_CLASS_IS_VALID_9;

	if(m_ZNext != node)
	{    
		if(m_ReleaseZNext)
		{
			DELETE0(m_ZNext);
		}
    
		m_ZNext = node; 
		m_ReleaseZNext = false;
	}
}

template <typename Real>
bool Mathematics::Bisect3Node<Real>
	::IsFirstFunctionResultSameSign()  const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto symbol = Math<Real>::Sign(m_FirstFunctionResult);
    
	if (symbol == NumericalValueSymbol::Zero)
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
				
			if(xNextYNext != nullptr &&  Math<Real>::Sign(xNextYNext->GetFirstFunctionResult()) != symbol)
			{
				return false;
			}
		}
    }
    
    if(m_YNext != nullptr &&  Math<Real>::Sign(m_YNext->GetFirstFunctionResult()) != symbol)
	{
        return false;
	}
    
    if(m_ZNext != nullptr)
    {
        if(Math<Real>::Sign(m_ZNext->GetFirstFunctionResult()) != symbol)
        {
            return false;
        }
        else
        {
			auto zNextXNext = m_ZNext->GetXNext();

            if(zNextXNext != nullptr)
            {
                if(Math<Real>::Sign(zNextXNext->GetFirstFunctionResult()) != symbol)
                {
                    return false;
                }
                else 
				{
					auto zNextXNextYNext = zNextXNext->GetYNext();

					if(zNextXNextYNext != nullptr && Math<Real>::Sign(zNextXNextYNext->GetFirstFunctionResult()) != symbol)
					{
						return false;
					}
				}					
            }

			auto zNextYNext = m_ZNext->GetYNext();
            
            if(zNextYNext != nullptr && Math<Real>::Sign(zNextYNext->GetFirstFunctionResult()) != symbol)
            {
                return false;
            }
        }
    }
    
    return true;
}

template <typename Real>
bool Mathematics::Bisect3Node<Real>
	::IsSecondFunctionResultSameSign() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
	auto symbol = Math<Real>::Sign(m_SecondFunctionResult);
    
    if(symbol == NumericalValueSymbol::Zero)
        return false;
    
    if(m_XNext != nullptr)
    {
        if(Math<Real>::Sign(m_XNext->GetSecondFunctionResult()) != symbol)
        {
            return false;
        }
        else 
		{
			auto xNextYNext = m_XNext->GetYNext();

			if(xNextYNext != nullptr && Math<Real>::Sign(xNextYNext->GetSecondFunctionResult()) != symbol)
			{
				return false;
			}	
		}
    }
    
    if(m_YNext != nullptr && Math<Real>::Sign(m_YNext->GetSecondFunctionResult()) != symbol)
	{
        return false;
	}
    
    if(m_ZNext != nullptr)
    {
        if(Math<Real>::Sign(m_ZNext->GetSecondFunctionResult()) != symbol)
        {
            return false;
        }
        else
        {
			auto zNextXNext = m_ZNext->GetXNext();

            if(zNextXNext != nullptr)
            {
                if(Math<Real>::Sign(zNextXNext->GetSecondFunctionResult()) != symbol)
                {
                    return false;
                }
                else 
				{
					auto zNextXNextYNext = zNextXNext->GetYNext();

					if(zNextXNextYNext != nullptr && Math<Real>::Sign(zNextXNextYNext->GetSecondFunctionResult()) != symbol)
					{
						return false;
					}
				}
            }

			auto zNextYNext = m_ZNext->GetYNext();
            
            if(zNextYNext != nullptr && Math<Real>::Sign(zNextYNext->GetSecondFunctionResult()) != symbol)
            {
                return false;
            }
        }
    }
    
    return true;
}

template <typename Real>
bool Mathematics::Bisect3Node<Real>
	::IsThirdFunctionResultSameSign() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
	auto symbol = Math<Real>::Sign(m_ThirdFunctionResult);
    
    if(symbol == NumericalValueSymbol::Zero)
	{
        return false;
	}
    
    if(m_XNext != nullptr)
    {
        if(Math<Real>::Sign(m_XNext->GetThirdFunctionResult()) != symbol)
        {
            return false;
        }
        else
		{
			auto xNextYNext = m_XNext->GetYNext();

			if(xNextYNext != nullptr && Math<Real>::Sign(xNextYNext->GetThirdFunctionResult()) != symbol)
			{
				return false;
			}
		}
    }
    
    if(m_YNext != nullptr && Math<Real>::Sign(m_YNext->GetThirdFunctionResult()) != symbol)
	{
        return false;
	}
    
    if(m_ZNext != nullptr)
    {
        if(Math<Real>::Sign(m_ZNext->GetThirdFunctionResult()) != symbol)
        {
            return false;
        }
        else
        {
			auto zNextXNext = m_ZNext->GetXNext();

            if(zNextXNext != nullptr)
            {
                if(Math<Real>::Sign(zNextXNext->GetThirdFunctionResult()) != symbol)
                {
                    return false;
                }
                else 
				{
					auto zNextXNextYNext = zNextXNext->GetYNext();

					if(zNextXNextYNext != nullptr && Math<Real>::Sign(zNextXNextYNext->GetThirdFunctionResult()) != symbol)
					{
						return false;
					}
				}
            }

			auto zNextYNext = m_ZNext->GetYNext();
            
            if(zNextYNext != nullptr && Math<Real>::Sign(zNextYNext->GetThirdFunctionResult()) != symbol)
            {
                return false;
            }
        }
    }
    
    return true;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_DETAIL_H

