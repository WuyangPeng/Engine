// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 18:20)

#include "Rendering/RenderingExport.h"

#include "ProjectorWorldPositionConstant.h"
#include "Detail/ProjectorConstantImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, ProjectorWorldPositionConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ProjectorWorldPositionConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ProjectorWorldPositionConstant); 
Rendering::ProjectorWorldPositionConstant::ProjectorWorldPositionConstant(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ProjectorWorldPositionConstant);

 

Rendering::ProjectorWorldPositionConstant
	::ProjectorWorldPositionConstant(const ProjectorSharedPtr& projector)
	:ParentType{ sm_NumRegisters }, impl{ make_shared<ImplType>(projector) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ProjectorWorldPositionConstant)

void Rendering::ProjectorWorldPositionConstant
	::SetNumRegisters(int numRegisters)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(numRegisters == sm_NumRegisters, "ProjectorWorldPositionConstant寄存器的数量必须为1");

	ParentType::SetNumRegisters(numRegisters);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ProjectorWorldPositionConstant,GetProjector, const Rendering::ConstProjectorSharedPtr )

void Rendering::ProjectorWorldPositionConstant ::Update([[maybe_unused]] const Visual* visual, [[maybe_unused]] const Camera* camera)
{
	RENDERING_CLASS_IS_VALID_1;

	const auto& worldPosition = GetProjector()->GetPosition();

	SetRegister(0,worldPosition);	

 
}

Rendering::ShaderFloatSharedPtr Rendering::ProjectorWorldPositionConstant
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSharedPtr{ std::make_shared<ClassType>(*this) };
}

 #include STSTEM_WARNING_POP