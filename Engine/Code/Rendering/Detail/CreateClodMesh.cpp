///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/11 11:04)

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
