// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/16 11:42)

#include "Mathematics/MathematicsExport.h"

#include "EdgeKey.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <ostream>

Mathematics::EdgeKey
	::EdgeKey (int first, int second)
{
    if (first < second)
    {
        // first是最小
        m_Vertex[0] = first;
        m_Vertex[1] = second;
    }
    else
    {
        // second是最小
        m_Vertex[0] = second;
        m_Vertex[1] = first;
    }
    
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}


Mathematics::EdgeKey
	::EdgeKey(const EdgeKey& rhs)
{
    m_Vertex[0] = rhs.m_Vertex[0];
    m_Vertex[1] = rhs.m_Vertex[1];
    
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::EdgeKey
	::EdgeKey()
{
    m_Vertex[0] = -1;
	m_Vertex[1] = -1;
    
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::EdgeKey& Mathematics::EdgeKey
	::operator = (const EdgeKey& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    m_Vertex[0] = rhs.m_Vertex[0];
    m_Vertex[1] = rhs.m_Vertex[1];

	return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, EdgeKey)

int Mathematics::EdgeKey
	::GetKey(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < 2,"索引错误！");
    
    return m_Vertex[index];
}

void Mathematics::EdgeKey
	::SetKey(int index,int value)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 2,"索引错误！");

	m_Vertex[index] = value;
}

bool Mathematics
	::operator< (const EdgeKey& lhs, const EdgeKey& rhs)
{    
    if (lhs.GetKey(1) < rhs.GetKey(1))    
        return true;    
    else if (rhs.GetKey(1) < lhs.GetKey(1))
		return false;    
	else
		return lhs.GetKey(0) < rhs.GetKey(0);
}

System::OStream& Mathematics
	::operator<<(System::OStream& os, const EdgeKey& edgeKey)
{
	os << edgeKey.GetKey(0) << "-" << edgeKey.GetKey(1);

	return os;
}

