// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 11:00)

#include "Rendering/RenderingExport.h"

#include "ClodMesh.h"
#include "Detail/ClodMeshImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26415)
using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, ClodMesh);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ClodMesh);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ClodMesh);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ClodMesh);

CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, ClodMesh);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, ClodMesh);

Rendering::ClodMesh
	::ClodMesh(const VertexFormatSharedPtr& vertexformat,const VertexBufferSharedPtr& vertexbuffer,
			   const IndexBufferSharedPtr& indexbuffer,const CollapseRecordArraySharedPtr& recordArray)
	:ParentType{ vertexformat, vertexbuffer,indexbuffer->Clone() }, m_Impl{ make_shared<ImplType>(recordArray) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, ClodMesh)

Rendering::ControllerInterfaceSharedPtr Rendering::ClodMesh
	::Clone() const 
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

void Rendering::ClodMesh
	::GetVisibleSet(Culler& culler, bool noCull)
{
	SelectLevelOfDetail();
    ParentType::GetVisibleSet(culler, noCull);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ClodMesh,GetNumRecords,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ClodMesh,GetTargetRecord,int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, ClodMesh,SetTargetRecord,int,void)
										  
int Rendering::ClodMesh
	::GetAutomatedTargetRecord() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return GetNumRecords();
}

void Rendering::ClodMesh
	::SelectLevelOfDetail()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	const int targetRecord = GetAutomatedTargetRecord();

	m_Impl->SelectLevelOfDetail(GetVertexBuffer(), GetIndexBuffer(), targetRecord);
}
 #include STSTEM_WARNING_POP