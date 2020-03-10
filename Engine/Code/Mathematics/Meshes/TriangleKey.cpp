// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/16 11:48)

#include "Mathematics/MathematicsExport.h"

#include "TriangleKey.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::TriangleKey
	::TriangleKey (int first, int second, int third)
{
    if (first < second)
    {
        if (first < third)
        {
            // first是最小
            m_Vertex[0] = first;
            m_Vertex[1] = second;
            m_Vertex[2] = third;
        }
        else
        {
            // third是最小
            m_Vertex[0] = third;
            m_Vertex[1] = first;
            m_Vertex[2] = second;
        }
    }
    else
    {
        if (second < third)
        {
            // second是最小
            m_Vertex[0] = second;
            m_Vertex[1] = third;
            m_Vertex[2] = first;
        }
        else
        {
            // third是最小
            m_Vertex[0] = third;
            m_Vertex[1] = first;
            m_Vertex[2] = second;
        }
    }
    
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}


Mathematics::TriangleKey
	::TriangleKey(const TriangleKey& rhs)
{
    m_Vertex[0] = rhs.m_Vertex[0];
    m_Vertex[1] = rhs.m_Vertex[1];
    m_Vertex[2] = rhs.m_Vertex[2];
    
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::TriangleKey
	::TriangleKey()
{
	m_Vertex[0] = 0;
	m_Vertex[1] = 0;
	m_Vertex[2] = 0;

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::TriangleKey& Mathematics::TriangleKey
	::operator = (const TriangleKey& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    m_Vertex[0] = rhs.m_Vertex[0];
    m_Vertex[1] = rhs.m_Vertex[1];
    m_Vertex[2] = rhs.m_Vertex[2];

	return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics,TriangleKey)

int Mathematics::TriangleKey
	::GetKey(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < 3,"索引错误！");
    
    return m_Vertex[index];
}

int Mathematics::TriangleKey
	::GetKeyIndex( int key ) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

	for (int index = 0; index < sm_VertexSize;++index)
	{
		if(m_Vertex[index] == key)
			return index;
	}

	THROW_EXCEPTION(SYSTEM_TEXT("未找到指定的值。"));
}

void Mathematics::TriangleKey
	::SetKey(int index, int value)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 3, "索引错误！");

	m_Vertex[index] = value;
}

void Mathematics::TriangleKey
	::Swap(int lhsIndex,int rhsIndex)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= lhsIndex && lhsIndex < 3, "索引错误！");
	MATHEMATICS_ASSERTION_0(0 <= rhsIndex && rhsIndex < 3, "索引错误！");

	std::swap(m_Vertex[lhsIndex],m_Vertex[rhsIndex]);
}

bool Mathematics
	::operator< (const TriangleKey& lhs, const TriangleKey& rhs)
{
    if (lhs.GetKey(2) < rhs.GetKey(2))    
        return true;        
    else if (rhs.GetKey(2) < lhs.GetKey(2))    
        return false;    
	else if (lhs.GetKey(1) < rhs.GetKey(1))    
        return true;    
	else if (rhs.GetKey(1) < lhs.GetKey(1))    
        return false;    
	else
		return lhs.GetKey(0) < rhs.GetKey(0);
}
