// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 11:00)

#include "Rendering/RenderingExport.h"

#include "ClodMesh.h"
#include "Detail/ClodMeshImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, ClodMesh);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ClodMesh);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ClodMesh);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ClodMesh);

CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, ClodMesh);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, ClodMesh);

Rendering::ClodMesh
	::ClodMesh(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,
			   const IndexBufferSmartPointer& indexbuffer,const CollapseRecordArraySmartPointer& recordArray)
	:ParentType{ vertexformat, vertexbuffer,indexbuffer->Clone() }, m_Impl{ make_shared<ImplType>(recordArray) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ClodMesh
	::~ClodMesh()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, ClodMesh)

Rendering::ControllerInterfaceSmartPointer Rendering::ClodMesh
	::Clone() const 
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ControllerInterfaceSmartPointer{ NEW0 ClassType(*this) };
}

void Rendering::ClodMesh
	::GetVisibleSet(Culler& culler, bool noCull)
{
	SelectLevelOfDetail();
    ParentType::GetVisibleSet(culler, noCull);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ClodMesh,GetNumRecords,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ClodMesh,GetTargetRecord,int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ClodMesh,SetTargetRecord,int,void)
										  
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

	int targetRecord = GetAutomatedTargetRecord();

	m_Impl->SelectLevelOfDetail(GetVertexBuffer(), GetIndexBuffer(), targetRecord);
}
 