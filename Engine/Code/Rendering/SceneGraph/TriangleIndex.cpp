// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 18:27)

#include "Rendering/RenderingExport.h"

#include "TriangleIndex.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

Rendering::TriangleIndex::TriangleIndex(int firstIndex, int secondIndex, int thirdIndex) noexcept
    : m_FirstIndex{ firstIndex }, m_SecondIndex{ secondIndex }, m_ThirdIndex{ thirdIndex }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::TriangleIndex
	::IsValid() const  noexcept
{
	if (0 <= m_FirstIndex && 0 <= m_SecondIndex && 0 <= m_ThirdIndex)
		return true;
	else
		return false;		
}

#endif // OPEN_CLASS_INVARIANT

int Rendering::TriangleIndex::GetFirstIndex() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_FirstIndex;
}

int Rendering::TriangleIndex::GetSecondIndex() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SecondIndex;
}

int Rendering::TriangleIndex::GetThirdIndex() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_ThirdIndex;
}

int Rendering::TriangleIndex
	::operator[](int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < 3, "索引越界！");

	switch (index)
	{
	case 0:
		return m_FirstIndex;
	case 1:
		return m_SecondIndex;
	default:
		return m_ThirdIndex;	 
	}
}
