///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:53)

#include "Rendering/RenderingExport.h"

#include "ClodMesh.h"
#include "Detail/ClodMeshImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ClodMesh)

CORE_TOOLS_RTTI_DEFINE(Rendering, ClodMesh);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ClodMesh);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ClodMesh);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ClodMesh);

Rendering::ClodMesh::ClodMesh(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ClodMesh)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ClodMesh)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ClodMesh)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ClodMesh)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ClodMesh)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ClodMesh)

Rendering::ClodMesh::ClodMesh(const VertexFormatSharedPtr& vertexformat,
                              const VertexBufferSharedPtr& vertexbuffer,
                              const IndexBuffer& indexbuffer,
                              const CollapseRecordArraySharedPtr& recordArray)
    : ParentType{ vertexformat, vertexbuffer, indexbuffer.Clone() }, impl{ recordArray }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ClodMesh)

Rendering::ControllerInterfaceSharedPtr Rendering::ClodMesh::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::ClodMesh::GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull)
{
    SelectLevelOfDetail();

    ParentType::GetVisibleSet(culler, camera, noCull);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ClodMesh, GetNumRecords, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ClodMesh, GetTargetRecord, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, ClodMesh, SetTargetRecord, int, void)

int Rendering::ClodMesh::GetAutomatedTargetRecord() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return GetNumRecords();
}

void Rendering::ClodMesh::SelectLevelOfDetail()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto targetRecord = GetAutomatedTargetRecord();

    impl->SelectLevelOfDetail(*GetVertexBuffer(), GetIndexBuffer(), targetRecord);
}
