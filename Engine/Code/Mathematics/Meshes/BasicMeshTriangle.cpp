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
#include "CoreTools/Helper/ExceptionMacro.h"

Mathematics::BasicMeshTriangle
	::BasicMeshTriangle()
	:m_Vertex{}, m_Edge{}, m_Triangle{}
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
	:m_Vertex{}, m_Edge{}, m_Triangle{}
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
    
	if (0 <= index && index < 3)
	{
		return m_Vertex[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Ë÷Òı´íÎó£¡"));
	}    
}

int Mathematics::BasicMeshTriangle
	::GetEdge(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9; 
    
	if (0 <= index && index < 3)
	{
		return m_Edge[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Ë÷Òı´íÎó£¡"));
	} 
}

int Mathematics::BasicMeshTriangle
	::GetTriangle(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9; 
    
	if (0 <= index && index < 3)
	{
		return m_Triangle[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Ë÷Òı´íÎó£¡"));
	} 
}

void Mathematics::BasicMeshTriangle
	::SetVertex(int index,int vertex)
{
	MATHEMATICS_CLASS_IS_VALID_9; 
    
	if (0 <= index && index < 3)
	{
		m_Vertex[index] = vertex;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Ë÷Òı´íÎó£¡"));
	}
   
}

void Mathematics::BasicMeshTriangle
	::SetEdge(int index,int edge)
{
	MATHEMATICS_CLASS_IS_VALID_9; 
    
	if (0 <= index && index < 3)
	{
		m_Edge[index] = edge;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Ë÷Òı´íÎó£¡"));
	}    
}

void Mathematics::BasicMeshTriangle
	::SetTriangle(int index,int triangle)
{
	MATHEMATICS_CLASS_IS_VALID_9; 
    
	if (0 <= index && index < 3)
	{
		m_Triangle[index] = triangle;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Ë÷Òı´íÎó£¡"));
	}    
}

