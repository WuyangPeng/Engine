// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:54)

#include "Framework/FrameworkExport.h"

#include "PixelScreenDrawLine.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::PixelScreenDrawLine
	::PixelScreenDrawLine(int xMin, int yMin, int xMax, int yMax)
	:m_XMin{ xMin }, m_YMin{ yMin }, m_XMax{ xMax }, m_YMax{ yMax }, m_DistanceX{ m_XMax - m_XMin }, m_DistanceY{ m_YMax - m_YMin },
	 m_StepX{ 0 < m_DistanceX ? 1 : (m_DistanceX < 0 ? -1 : 0) }, m_StepY{ 0 < m_DistanceY ? 1 : (m_DistanceY < 0 ? -1 : 0) }, m_Line{ }
{
	Calculate();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

void Framework::PixelScreenDrawLine
	::Calculate()
{
	// 像素决定参数的选择。
	if (m_DistanceX < 0)
	{
		m_DistanceX = -m_DistanceX;
	}
	if (m_DistanceY < 0)
	{
		m_DistanceY = -m_DistanceY;
	}

	// 使用有关的变量确定单步的最大方向分量。 使用Bresenham算法遍历线段。
	if (m_DistanceY < m_DistanceX)
	{
		DrawLineOnX();
	}
	else
	{
		DrawLineOnY();
	}
}

void Framework::PixelScreenDrawLine
	::DrawLineOnX()
{
	const auto twiceDistanceX = 2 * m_DistanceX;
	const auto twiceDistanceY = 2 * m_DistanceY;
	auto x = m_XMin;
	auto y = m_YMin;
	m_Line.emplace_back(x, y);

	auto decy = twiceDistanceY - m_DistanceX;
	while (x != m_XMax)
	{
		if (0 <= decy)
		{
			decy -= twiceDistanceX;
			y += m_StepY;
		}

		x += m_StepX;
		decy += twiceDistanceY;

		// 处理像素。
		m_Line.emplace_back(x, y);
	} 
}

void Framework::PixelScreenDrawLine
	::DrawLineOnY()
{
	const auto twiceDistanceX = 2 * m_DistanceX;
	const auto twiceDistanceY = 2 * m_DistanceY;
	auto x = m_XMin;
	auto y = m_YMin;
	m_Line.emplace_back(x, y);

	auto decx = twiceDistanceX - m_DistanceY;
	while (y != m_YMax)
	{
		if (0 <= decx)
		{
			decx -= twiceDistanceY;
			x += m_StepX;
		}

		y += m_StepY;
		decx += twiceDistanceX;

		// 处理像素。
		m_Line.emplace_back(x, y);
	}	
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::PixelScreenDrawLine
	::IsValid() const noexcept
{ 
	return CoreTools::Noexcept(*this, &ClassType::IsEndpointCorrect, false);
}

bool Framework::PixelScreenDrawLine
	::IsEndpointCorrect() const
{
	if (m_Line.empty())
	{
		return false;
	}
	else
	{
		const auto iter = m_Line.cbegin();
		if (iter->GetWindowX() != m_XMin || iter->GetWindowY() != m_YMin)
		{
			return false;
		}

		const auto reverseIter = m_Line.crbegin();
		if (reverseIter->GetWindowX() != m_XMax || reverseIter->GetWindowY() != m_YMax)
		{
			return false;
		}
	}

	return true;
}
#endif // OPEN_CLASS_INVARIANT

int Framework::PixelScreenDrawLine
	::GetSize() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Line.size());
}

const Framework::WindowPoint& Framework::PixelScreenDrawLine
	::operator[](int index) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Line.at(index);
}