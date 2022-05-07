///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 11:04)

#include "Rendering/RenderingExport.h"

#include "CreateClodMesh.h"
#include "Detail/CreateClodMeshImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Rendering::CreateClodMesh::CreateClodMesh(TrianglesMesh& mesh)
    : impl{ mesh }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CreateClodMesh)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CreateClodMesh, GetCollapseRecordArray, Rendering::CollapseRecordArraySharedPtr)
