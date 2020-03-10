// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.2 (2019/07/16 11:40)

#include "Mathematics/MathematicsExport.h"

#include "BasicMeshVertex.h"
#include "Detail/BasicMeshVertexImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::make_shared;

Mathematics::BasicMeshVertex
	::BasicMeshVertex ()
	:m_Impl{ make_shared<ImplType>() }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Mathematics, BasicMeshVertex)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics,BasicMeshVertex,GetVertex,int,int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, BasicMeshVertex,GetEdge,int,int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics,BasicMeshVertex,GetTriangle,int,int);

void Mathematics::BasicMeshVertex
	::InsertEdge (int vertex, int edge)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_Impl->InsertEdge(vertex,edge);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics,BasicMeshVertex,InsertTriangle,int, void);
