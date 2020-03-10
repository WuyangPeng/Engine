// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 09:54)

#include "Mathematics/MathematicsExport.h"

#include "QuerySortToolsImpl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

using std::swap;

Mathematics::QuerySortToolsImpl
	::QuerySortToolsImpl(int firstValue, int secondValue)
	:m_SortValue{ firstValue,secondValue }, m_Symbol{ NumericalValueSymbol::Zero }
{
	SortTwoValue();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::QuerySortToolsImpl
	::QuerySortToolsImpl(int firstValue, int secondValue,int thirdValue)
	:m_SortValue{ firstValue,secondValue,thirdValue }, m_Symbol{ NumericalValueSymbol::Zero }
{
	 SortThreeValue();

	 MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::QuerySortToolsImpl
	::QuerySortToolsImpl(int firstValue, int secondValue, int thirdValue, int fourthValue)
	:m_SortValue{ firstValue,secondValue,thirdValue,fourthValue }, m_Symbol{ NumericalValueSymbol::Zero }
{
	 SortFourValue();

	 MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics,QuerySortToolsImpl)

Mathematics::NumericalValueSymbol Mathematics::QuerySortToolsImpl
	::GetSymbol() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Symbol;
}

int Mathematics::QuerySortToolsImpl
	::GetValue(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_SortValue.size()), "索引错误！");

	return m_SortValue[index];
}

void Mathematics::QuerySortToolsImpl
	::SortTwoValue()
{
	if (m_SortValue[1] < m_SortValue[0])
	{
		swap(m_SortValue[0], m_SortValue[1]);
		m_Symbol = NumericalValueSymbol::Negative;
	}
	else
	{
		m_Symbol = NumericalValueSymbol::Positive;
	}		 
}

void Mathematics::QuerySortToolsImpl
	::SortThreeValue()
{
	if (m_SortValue[0] <= m_SortValue[1])
	{
		if (m_SortValue[2] < m_SortValue[0])
		{
			// 0 1 2 -> 2 0 1
			swap(m_SortValue[0], m_SortValue[2]);
			swap(m_SortValue[1], m_SortValue[2]);
			m_Symbol = NumericalValueSymbol::Positive;
		}
		else if (m_SortValue[2] < m_SortValue[1])
		{
			// 0 1 2 -> 0 2 1
			swap(m_SortValue[1], m_SortValue[2]);
			m_Symbol = NumericalValueSymbol::Negative;
		}
		else
		{
			// 数值不变
			m_Symbol = NumericalValueSymbol::Positive;
		}
	}
	else
	{
		if (m_SortValue[2] < m_SortValue[1])
		{
			// 0 1 2 -> 2 1 0
			swap(m_SortValue[0], m_SortValue[2]);
			m_Symbol = NumericalValueSymbol::Negative;
		}
		else if (m_SortValue[2] < m_SortValue[0])
		{
			// 0 1 2 -> 1 2 0
			swap(m_SortValue[0], m_SortValue[2]);
			swap(m_SortValue[0], m_SortValue[1]);
			m_Symbol = NumericalValueSymbol::Positive;
		}
		else
		{
			// 0 1 2 -> 1 0 2
			swap(m_SortValue[0], m_SortValue[1]);
			m_Symbol = NumericalValueSymbol::Negative;
		}
	}	
}

void Mathematics::QuerySortToolsImpl
	::SortFourValue()
{
	if (m_SortValue[0] <= m_SortValue[1])
	{
		if (m_SortValue[2] <= m_SortValue[3])
		{
			if (m_SortValue[1] <= m_SortValue[2])
			{
				// 数值不变
				m_Symbol = NumericalValueSymbol::Positive;
			}
			else if (m_SortValue[3] < m_SortValue[0])
			{
				// 0 1 2 3 -> 2 3 0 1
				swap(m_SortValue[0], m_SortValue[2]);
				swap(m_SortValue[1], m_SortValue[3]);
				m_Symbol = NumericalValueSymbol::Positive;
			}
			else if (m_SortValue[2] < m_SortValue[0])
			{
				if (m_SortValue[3] < m_SortValue[1])
				{
					// 0 1 2 3 -> 2 0 3 1 
					swap(m_SortValue[0], m_SortValue[1]);
					swap(m_SortValue[0], m_SortValue[3]);
					swap(m_SortValue[0], m_SortValue[2]);
					m_Symbol = NumericalValueSymbol::Negative;
				}
				else
				{
					// 0 1 2 3 -> 2 0 1 3 
					swap(m_SortValue[0], m_SortValue[1]);
					swap(m_SortValue[0], m_SortValue[2]);
					m_Symbol = NumericalValueSymbol::Positive;
				}
			}
			else
			{
				if (m_SortValue[3] < m_SortValue[1])
				{
					// 0 1 2 3 -> 0 2 3 1
					swap(m_SortValue[1], m_SortValue[2]);
					swap(m_SortValue[2], m_SortValue[3]);
					m_Symbol = NumericalValueSymbol::Positive;
				}
				else
				{
					// 0 1 2 3 -> 0 2 1 3 
					swap(m_SortValue[1], m_SortValue[2]);
					m_Symbol = NumericalValueSymbol::Negative;
				}
			}
		}
		else
		{
			if (m_SortValue[1] <= m_SortValue[3])
			{
				// 0 1 2 3 -> 0 1 3 2 
				swap(m_SortValue[2], m_SortValue[3]);
				m_Symbol = NumericalValueSymbol::Negative;
			}
			else if (m_SortValue[2] < m_SortValue[0])
			{
				// 0 1 2 3 -> 3 2 0 1 			
				swap(m_SortValue[0], m_SortValue[2]);
				swap(m_SortValue[0], m_SortValue[1]);
				swap(m_SortValue[0], m_SortValue[3]);
				m_Symbol = NumericalValueSymbol::Negative;
			}
			else if (m_SortValue[3] < m_SortValue[0])
			{
				if (m_SortValue[2] < m_SortValue[1])
				{
					// 0 1 2 3 -> 3 0 2 1 				
					swap(m_SortValue[0], m_SortValue[1]);
					swap(m_SortValue[0], m_SortValue[3]);
					m_Symbol = NumericalValueSymbol::Positive;
				}
				else
				{
					// 0 1 2 3 -> 3 0 1 2 
					swap(m_SortValue[0], m_SortValue[1]);
					swap(m_SortValue[0], m_SortValue[2]);
					swap(m_SortValue[0], m_SortValue[3]);
					m_Symbol = NumericalValueSymbol::Negative;
				}
			}
			else
			{
				if (m_SortValue[2] < m_SortValue[1])
				{
					// 0 1 2 3 -> 0 3 2 1 
					swap(m_SortValue[1], m_SortValue[3]);					 
					m_Symbol = NumericalValueSymbol::Negative;
				}
				else
				{
					// 0 1 2 3 -> 0 3 1 2 
					swap(m_SortValue[1], m_SortValue[2]);
					swap(m_SortValue[1], m_SortValue[3]);
					m_Symbol = NumericalValueSymbol::Positive;
				}
			}
		}
	}
	else
	{
		if (m_SortValue[2] <= m_SortValue[3])
		{
			if (m_SortValue[0] <= m_SortValue[2])
			{
				// 0 1 2 3 -> 1 0 2 3 			
				swap(m_SortValue[0], m_SortValue[1]);
				m_Symbol = NumericalValueSymbol::Negative;
			}
			else if (m_SortValue[3] < m_SortValue[1])
			{
				// 0 1 2 3 -> 2 3 1 0 			
				swap(m_SortValue[0], m_SortValue[3]);
				swap(m_SortValue[0], m_SortValue[1]);
				swap(m_SortValue[0], m_SortValue[2]);
				m_Symbol = NumericalValueSymbol::Negative;
			}
			else if (m_SortValue[2] < m_SortValue[1])
			{
				if (m_SortValue[3] < m_SortValue[0])
				{
					// 0 1 2 3 -> 2 1 3 0 
					swap(m_SortValue[0], m_SortValue[3]);
					swap(m_SortValue[0], m_SortValue[2]);
					m_Symbol = NumericalValueSymbol::Positive;
				}
				else
				{
					// 0 1 2 3 -> 2 1 0 3 
					swap(m_SortValue[0], m_SortValue[2]);
					m_Symbol = NumericalValueSymbol::Negative;
				}
			}
			else
			{
				if (m_SortValue[3] < m_SortValue[0])
				{
					// 0 1 2 3 -> 1 2 3 0 
					swap(m_SortValue[0], m_SortValue[3]);
					swap(m_SortValue[0], m_SortValue[2]);
					swap(m_SortValue[0], m_SortValue[1]);
					m_Symbol = NumericalValueSymbol::Negative;
				}
				else
				{
					// 0 1 2 3 -> 1 2 0 3
					swap(m_SortValue[0], m_SortValue[2]);
					swap(m_SortValue[0], m_SortValue[1]);
					m_Symbol = NumericalValueSymbol::Positive;
				}
			}
		}
		else
		{
			if (m_SortValue[0] <= m_SortValue[3])
			{
				// 0 1 2 3 -> 1 0 3 2
				swap(m_SortValue[0], m_SortValue[1]);
				swap(m_SortValue[2], m_SortValue[3]);
				m_Symbol = NumericalValueSymbol::Positive;
			}
			else if (m_SortValue[2] < m_SortValue[1])
			{
				// 0 1 2 3 -> 3 2 1 0
				swap(m_SortValue[0], m_SortValue[3]);
				swap(m_SortValue[1], m_SortValue[2]);
				m_Symbol = NumericalValueSymbol::Positive;
			}
			else if (m_SortValue[3] < m_SortValue[1])
			{
				if (m_SortValue[2] < m_SortValue[0])
				{
					// 0 1 2 3 -> 3 1 2 0
					swap(m_SortValue[0], m_SortValue[3]);
					m_Symbol = NumericalValueSymbol::Negative;
				}
				else
				{
					// 0 1 2 3 -> 3 1 0 2
					swap(m_SortValue[0], m_SortValue[2]);
					swap(m_SortValue[0], m_SortValue[3]);
					m_Symbol = NumericalValueSymbol::Positive;
				}
			}
			else
			{
				if (m_SortValue[2] < m_SortValue[0])
				{
					// 0 1 2 3 -> 1 3 2 0
					swap(m_SortValue[0], m_SortValue[3]);
					swap(m_SortValue[0], m_SortValue[1]);
					m_Symbol = NumericalValueSymbol::Positive;
				}
				else
				{
					// 0 1 2 3 -> 1 3 0 2
					swap(m_SortValue[0], m_SortValue[2]);
					swap(m_SortValue[0], m_SortValue[3]);
					swap(m_SortValue[0], m_SortValue[1]);
					m_Symbol = NumericalValueSymbol::Negative;
				}
			}
		}
	}
}
 