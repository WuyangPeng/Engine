// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 17:48)

#include "Rendering/RenderingExport.h"

#include "CameraWorldDirectionVectorConstant.h"
#include "System/Helper/UnusedMacro.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)

CORE_TOOLS_RTTI_DEFINE(Rendering, CameraWorldDirectionVectorConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, CameraWorldDirectionVectorConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, CameraWorldDirectionVectorConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, CameraWorldDirectionVectorConstant);

Rendering::CameraWorldDirectionVectorConstant
	::CameraWorldDirectionVectorConstant()
	:ParentType{ sm_NumRegisters }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CameraWorldDirectionVectorConstant)

void Rendering::CameraWorldDirectionVectorConstant
	::Update(const Visual* visual, const Camera* camera)
{
	RENDERING_CLASS_IS_VALID_1;
 
	const auto worldDVector = camera->GetDirectionVector(); 

	SetRegister(0, worldDVector);

	SYSTEM_UNUSED_ARG(visual);
}

void Rendering::CameraWorldDirectionVectorConstant
	::SetNumRegisters(int numRegisters)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(numRegisters == sm_NumRegisters, "CameraModelDirectionVectorConstant寄存器的数量必须为1");

	ParentType::SetNumRegisters(numRegisters);
}

Rendering::ShaderFloatSmartPointer Rendering::CameraWorldDirectionVectorConstant
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSmartPointer{ std::make_shared<ClassType>(*this) };
}
 

 
#include STSTEM_WARNING_POP