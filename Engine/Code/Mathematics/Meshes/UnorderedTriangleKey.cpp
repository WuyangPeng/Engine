// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 11:50)

#include "Mathematics/MathematicsExport.h"

#include "UnorderedTriangleKey.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <algorithm>
#include "CoreTools/Helper/ExceptionMacro.h"

Mathematics::UnorderedTriangleKey
::UnorderedTriangleKey (int first, int second,int third)
{
    if (first < second)
    {
        if (first < third)
        {
            // first����С
            m_Vertex[0] = first;
            m_Vertex[1] = std::min(second, third);
            m_Vertex[2] = std::max(second, third);
        }
        else
        {
            // third����С
            m_Vertex[0] = third;
            m_Vertex[1] = std::min(first, second);
            m_Vertex[2] = std::max(first, second);
        }
    }
    else
    {
        if (second < third)
        {
            // second����С
            m_Vertex[0] = second;
            m_Vertex[1] = std::min(third, first);
            m_Vertex[2] = std::max(third, first);
        }
        else
        {
            // third����С
            m_Vertex[0] = third;
            m_Vertex[1] = std::min(first, second);
            m_Vertex[2] = std::max(first, second);
        }
    }
   
    
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}


Mathematics::UnorderedTriangleKey
	::UnorderedTriangleKey(const UnorderedTriangleKey& rhs)
{
    m_Vertex[0] = rhs.m_Vertex[0];
    m_Vertex[1] = rhs.m_Vertex[1];
    m_Vertex[2] = rhs.m_Vertex[2];
    
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::UnorderedTriangleKey& Mathematics::UnorderedTriangleKey
	::operator = (const UnorderedTriangleKey& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;
    
    m_Vertex[0] = rhs.m_Vertex[0];
    m_Vertex[1] = rhs.m_Vertex[1];
    m_Vertex[2] = rhs.m_Vertex[2];

	return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, UnorderedTriangleKey)

int Mathematics::UnorderedTriangleKey
	::GetKey(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9; 
    
	if (0 <= index && index < 3)
	{
		return m_Vertex[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��������"));
	}
}

bool Mathematics
	::operator< (const UnorderedTriangleKey& lhs,  const UnorderedTriangleKey& rhs)
{
    if (lhs.GetKey(2) < rhs.GetKey(2))
    {
        return true;
    }

    if (rhs.GetKey(2) < lhs.GetKey(2))
    {
        return false;
    }

    if (lhs.GetKey(1) < rhs.GetKey(1))
    {
        return true;
    }

     if (rhs.GetKey(1) < lhs.GetKey(1))
    {
        return false;
    }

    return lhs.GetKey(0) < rhs.GetKey(0);
}

