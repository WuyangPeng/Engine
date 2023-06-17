///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:53)

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
