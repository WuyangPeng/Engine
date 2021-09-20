// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 11:03)

#include "Rendering/RenderingExport.h"

#include "CreateClodMesh.h"
#include "Detail/CreateClodMeshImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::CreateClodMesh
	::CreateClodMesh(TrianglesMeshSharedPtr mesh)
	:impl{ mesh }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CreateClodMesh)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CreateClodMesh, GetCollapseRecordArray, Rendering::CollapseRecordArraySharedPtr)
