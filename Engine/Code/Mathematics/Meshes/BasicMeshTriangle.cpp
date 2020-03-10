// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.2 (2019/07/16 11:23)

#include "Mathematics/MathematicsExport.h"

#include "BasicMeshTriangle.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::BasicMeshTriangle
	::BasicMeshTriangle()
{
    for(int i = 0;i < 3;++i)
    {
        m_Vertex[i] = -1;
        m_Edge[i] = -1;
        m_Triangle[i] = -1;
    }
    
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::BasicMeshTriangle
	::BasicMeshTriangle (const BasicMeshTriangle& rhs)
{
    for(int i = 0;i < 3;++i)
    {
        m_Vertex[i] = rhs.m_Vertex[i];
        m_Edge[i] = rhs.m_Edge[i];
        m_Triangle[i] = rhs.m_Triangle[i];
    }
    
	MATHEMATICS_SELF_CLASS_IS_VALID_9;

}

Mathematics::BasicMeshTriangle& Mathematics::BasicMeshTriangle
	::operator = (const BasicMeshTriangle& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;
    
    for(int i = 0;i < 3;++i)
    {
        m_Vertex[i] = rhs.m_Vertex[i];
        m_Edge[i] = rhs.m_Edge[i];
        m_Triangle[i] = rhs.m_Triangle[i];
    }

	return *this;
}
CLASS_INVARIANT_STUB_DEFINE(Mathematics, BasicMeshTriangle)

int Mathematics::BasicMeshTriangle
	::GetVertex(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 3,"Ë÷Òı´íÎó£¡");
    
    return m_Vertex[index];
    
}

int Mathematics::BasicMeshTriangle
	::GetEdge(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 3,"Ë÷Òı´íÎó£¡");
    
    return m_Edge[index];
}

int Mathematics::BasicMeshTriangle
	::GetTriangle(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 3,"Ë÷Òı´íÎó£¡");
    
    return m_Triangle[index];
}

void Mathematics::BasicMeshTriangle
	::SetVertex(int index,int vertex)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 3,"Ë÷Òı´íÎó£¡");
    
    m_Vertex[index] = vertex;
}

void Mathematics::BasicMeshTriangle
	::SetEdge(int index,int edge)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 3,"Ë÷Òı´íÎó£¡");
    
    m_Edge[index] = edge;
}

void Mathematics::BasicMeshTriangle
	::SetTriangle(int index,int triangle)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 3,"Ë÷Òı´íÎó£¡");
    
    m_Triangle[index] = triangle;
}

