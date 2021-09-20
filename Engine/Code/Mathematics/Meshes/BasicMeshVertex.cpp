// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.2 (2019/07/16 11:40)

#include "Mathematics/MathematicsExport.h"

#include "BasicMeshVertex.h"
#include "Detail/BasicMeshVertexImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Mathematics::BasicMeshVertex
	::BasicMeshVertex ()
	:impl{ 0  }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
CLASS_INVARIANT_STUB_DEFINE(Mathematics, BasicMeshVertex)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, BasicMeshVertex, GetVertex, int, int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, BasicMeshVertex, GetEdge, int, int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, BasicMeshVertex, GetTriangle, int, int);

void Mathematics::BasicMeshVertex
	::InsertEdge (int vertex, int edge)
{
	;
    
    return impl->InsertEdge(vertex, edge);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, BasicMeshVertex, InsertTriangle, int, void);
