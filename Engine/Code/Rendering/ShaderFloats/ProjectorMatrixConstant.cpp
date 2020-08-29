// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 18:13)

#include "Rendering/RenderingExport.h"

#include "ProjectorMatrixConstant.h"
#include "Detail/ProjectorMatrixConstantImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "Rendering/SceneGraph/Visual.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26486)
CORE_TOOLS_RTTI_DEFINE(Rendering, ProjectorMatrixConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ProjectorMatrixConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ProjectorMatrixConstant); 
CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, ProjectorMatrixConstant);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ProjectorMatrixConstant);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, ProjectorMatrixConstant);

Rendering::ProjectorMatrixConstant
	::ProjectorMatrixConstant(const ProjectorSmartPointer& projector,bool biased, int biasScaleMatrixIndex)
	:ParentType(sm_NumRegisters),  m_Impl{ make_shared<ImplType>(projector,biased,biasScaleMatrixIndex) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, ProjectorMatrixConstant)

void Rendering::ProjectorMatrixConstant
	::SetNumRegisters(int numRegisters)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(numRegisters == sm_NumRegisters, "ProjectorMatrixConstant寄存器的数量必须为4");

	ParentType::SetNumRegisters(numRegisters);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ProjectorMatrixConstant,GetProjector, const Rendering::ConstProjectorSmartPointer )
									
void Rendering::ProjectorMatrixConstant
	::Update( const Visual* visual, const Camera* camera )
{
	RENDERING_CLASS_IS_VALID_1;

	const auto projectionViewMatrix = GetProjector()->GetProjectionViewMatrix();
	const auto worldMatrix = visual->GetWorldTransform().GetMatrix();
	auto projectionViewWorldMatrix = projectionViewMatrix * worldMatrix;
	projectionViewWorldMatrix = m_Impl->GetProjectionViewWorldMatrix(projectionViewWorldMatrix);

	SetRegisters(projectionViewWorldMatrix);

	SYSTEM_UNUSED_ARG(camera);
}

Rendering::ShaderFloatSmartPointer Rendering::ProjectorMatrixConstant
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSmartPointer{ std::make_shared<ClassType>(*this) };
}

 #include STSTEM_WARNING_POP