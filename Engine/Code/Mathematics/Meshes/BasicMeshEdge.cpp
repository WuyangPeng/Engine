// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.2 (2019/07/16 11:22)

#include "Mathematics/MathematicsExport.h"

#include "BasicMeshEdge.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::BasicMeshEdge
	::BasicMeshEdge()
{
    for(int i = 0;i < 2;++i)
    {
        m_Vertex[i] = -1;
        m_Triangle[i] = -1;
    }
    
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::BasicMeshEdge
	::BasicMeshEdge (const BasicMeshEdge& rhs)
{
    for(int i = 0;i < 2;++i)
    {
        m_Vertex[i] = rhs.m_Vertex[i];
         m_Triangle[i] = rhs.m_Triangle[i];
    }
    
	MATHEMATICS_SELF_CLASS_IS_VALID_9;

}

Mathematics::BasicMeshEdge& Mathematics::BasicMeshEdge
	::operator = (const BasicMeshEdge& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;
    
    for(int i = 0;i < 2;++i)
    {
        m_Vertex[i] = rhs.m_Vertex[i];
        m_Triangle[i] = rhs.m_Triangle[i];
    }
    
    return *this;
}


CLASS_INVARIANT_STUB_DEFINE(Mathematics, BasicMeshEdge)

int Mathematics::BasicMeshEdge
	::GetVertex(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 2,"Ë÷Òı´íÎó£¡");
    
    return m_Vertex[index];
    
}

int Mathematics::BasicMeshEdge
	::GetTriangle(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 2,"Ë÷Òı´íÎó£¡");
    
    return m_Triangle[index];
}

void Mathematics::BasicMeshEdge
	::SetVertex(int index,int vertex)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 2,"Ë÷Òı´íÎó£¡");
    
    m_Vertex[index] = vertex;
}

void Mathematics::BasicMeshEdge
	::SetTriangle(int index,int triangle)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 2,"Ë÷Òı´íÎó£¡");
    
    m_Triangle[index] = triangle;
}

