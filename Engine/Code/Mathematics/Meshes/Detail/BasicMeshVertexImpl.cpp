// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/16 11:19)

#include "Mathematics/MathematicsExport.h"

#include "BasicMeshVertexImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

Mathematics::BasicMeshVertexImpl
	::BasicMeshVertexImpl ()
	:m_Vertex{}, m_Edge{}, m_Triangle{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics,BasicMeshVertexImpl)

int Mathematics::BasicMeshVertexImpl
	::GetVertex(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index &&index < boost::numeric_cast<int>(m_Vertex.size()),"索引错误！");
    
    return m_Vertex[index];
    
}

int Mathematics::BasicMeshVertexImpl
	::GetEdge(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Edge.size()),"索引错误！");
    
    return m_Edge[index];
}

int Mathematics::BasicMeshVertexImpl
	::GetTriangle(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index &&index < boost::numeric_cast<int>(m_Triangle.size()),"索引错误！");
    
    return m_Triangle[index];
}

void Mathematics::BasicMeshVertexImpl
	::InsertEdge (int vertex, int edge)
{
	MATHEMATICS_CLASS_IS_VALID_9;

    // 检查顶点/边是否在相邻数组（如果在则什么都不做）。
    for (uint32_t i = 0; i < m_Vertex.size(); ++i)
    {
        if (vertex == m_Vertex[i])
        {
            return;
        }
    }
    
    m_Vertex.push_back(vertex);
    m_Edge.push_back(edge);
}

void Mathematics::BasicMeshVertexImpl
	::InsertTriangle (int triangle)
{
	MATHEMATICS_CLASS_IS_VALID_9;
    
    // 检查三角形是否在相邻数组（如果在则什么都不做）。
    for (uint32_t i = 0; i < m_Triangle.size(); ++i)
    {
        if (triangle == m_Triangle[i])
        {
            return;
        }
    }
    
    m_Triangle.push_back(triangle);
}




