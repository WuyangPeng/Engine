// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:17)

#include "Framework/FrameworkExport.h"

#include "PixelScreenDrawLine.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::PixelScreenDrawLine
	::PixelScreenDrawLine(int beginX, int beginY,  int endX, int endY)
   :m_BeginX(beginX),
    m_BeginY(beginY),
    m_EndX(endX),
    m_EndY(endY),
    m_DistanceX(m_EndX - m_BeginX),
    m_DistanceY(m_EndY - m_BeginY),
    m_StepX(0 < m_DistanceX ? 1 : (m_DistanceX < 0 ? -1 : 0)),
    m_StepY(0 < m_DistanceY ? 1 : (m_DistanceY < 0 ? -1 : 0)),
    m_Line()
{
	Calculate();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

void Framework::PixelScreenDrawLine
	::Calculate()
{
    // ���ؾ���������ѡ��
    if (m_DistanceX < 0)
    {
        m_DistanceX = -m_DistanceX;
    }
    if (m_DistanceY < 0)
    {
        m_DistanceY = -m_DistanceY;
    }

    // ʹ���йصı���ȷ������������������
    // ʹ��Bresenham�㷨�����߶Ρ�
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
    int twiceDistanceX = 2 * m_DistanceX;
    int twiceDistanceY = 2 * m_DistanceY;
    int x = m_BeginX;
    int y = m_BeginY;	 
	m_Line.push_back(WindowPoint(x, y));

	int decy = twiceDistanceY - m_DistanceX;
	while (x != m_EndX)
	{
		if (0 <= decy)
		{
			decy -= twiceDistanceX;
			y += m_StepY;
		}

		x += m_StepX;
		decy += twiceDistanceY;

		// �������ء�
		m_Line.push_back(WindowPoint(x, y));
	}
}

void Framework::PixelScreenDrawLine
	::DrawLineOnY()
{
    int twiceDistanceX = 2 * m_DistanceX;
    int twiceDistanceY = 2 * m_DistanceY;
    int x = m_BeginX;
    int y = m_BeginY;	
	m_Line.push_back(WindowPoint(x, y));

	int decx = twiceDistanceX - m_DistanceY;
	while (y != m_EndY)
	{
		if (0 <= decx)
		{
			decx -= twiceDistanceY;
			x += m_StepX;
		}

		y += m_StepY;
		decx += twiceDistanceX;

		// �������ء�
		m_Line.push_back(WindowPoint(x, y));
	}    
}

CLASS_INVARIANT_STUB_DEFINE(Framework,PixelScreenDrawLine)

int Framework::PixelScreenDrawLine
	::GetSize() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return static_cast<int>(m_Line.size());
}

const Framework::WindowPoint& Framework::PixelScreenDrawLine
	::operator[](int index) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;
	FRAMEWORK_ASSERTION_0(0 <= index && index < static_cast<int>(m_Line.size()),"��������Խ�磡");

	return m_Line[index];
}