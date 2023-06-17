///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:53)

#include "Rendering/RenderingExport.h"

#include "CreateClodMesh.h"
#include "Detail/CreateClodMeshImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::CreateClodMesh::CreateClodMesh(TrianglesMesh& mesh)
    : impl{ mesh }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CreateClodMesh)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CreateClodMesh, GetCollapseRecordArray, Rendering::CollapseRecordArraySharedPtr)
