///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:17)

#include "Mathematics/MathematicsExport.h"

#include "BasicMeshVertex.h"
#include "Detail/BasicMeshVertexImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Mathematics::BasicMeshVertex Mathematics::BasicMeshVertex::Create()
{
    return BasicMeshVertex{ CoreTools::DisableNotThrow::Disable };
}

Mathematics::BasicMeshVertex::BasicMeshVertex(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, BasicMeshVertex)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, BasicMeshVertex, GetVertex, int, int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, BasicMeshVertex, GetEdge, int, int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, BasicMeshVertex, GetTriangle, int, int);

void Mathematics::BasicMeshVertex::InsertEdge(int vertex, int edge)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return impl->InsertEdge(vertex, edge);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, BasicMeshVertex, InsertTriangle, int, void);
