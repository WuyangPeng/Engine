// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 18:12)

#include "Rendering/RenderingExport.h"

#include "ProjectionViewWorldMatrixConstant.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ProjectionViewWorldMatrixConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ProjectionViewWorldMatrixConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ProjectionViewWorldMatrixConstant); 
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ProjectionViewWorldMatrixConstant);

Rendering::ProjectionViewWorldMatrixConstant
	::ProjectionViewWorldMatrixConstant()
	:ParentType{ sm_NumRegisters }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ProjectionViewWorldMatrixConstant
	::~ProjectionViewWorldMatrixConstant()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,ProjectionViewWorldMatrixConstant)

void Rendering::ProjectionViewWorldMatrixConstant
	::Update(const Visual* visual, const Camera* camera)
{
	RENDERING_CLASS_IS_VALID_1;

	const auto projectionMatrix = camera->GetProjectionViewMatrix();	 
	const auto worldMatrix = visual->GetWorldTransform().GetMatrix();
	auto projectionViewWorldMatrix = projectionMatrix * worldMatrix;

	SetRegisters(projectionViewWorldMatrix);	
}

void Rendering::ProjectionViewWorldMatrixConstant
	::SetNumRegisters(int numRegisters)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(numRegisters == sm_NumRegisters, "ProjectionViewWorldMatrixConstant寄存器的数量必须为4");

	ParentType::SetNumRegisters(numRegisters);
}

Rendering::ShaderFloatSmartPointer Rendering::ProjectionViewWorldMatrixConstant
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSmartPointer{ NEW0 ClassType(*this) };
}


