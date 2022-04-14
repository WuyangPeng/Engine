// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 18:09)

#include "Rendering/RenderingExport.h"

#include "MaterialSpecularConstant.h"

#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
CORE_TOOLS_RTTI_DEFINE(Rendering, MaterialSpecularConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, MaterialSpecularConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, MaterialSpecularConstant); 
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, MaterialSpecularConstant);

Rendering::MaterialSpecularConstant
	::MaterialSpecularConstant(const MaterialSharedPtr& material)
	:ParentType{ material }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,MaterialSpecularConstant)

void Rendering::MaterialSpecularConstant::Update([[maybe_unused]] const Visual* visual, [[maybe_unused]] const Camera* camera)
{
	RENDERING_CLASS_IS_VALID_1;

	const auto colour = GetMaterial()->GetSpecular();
	SetRegister(0, colour);
 
}

Rendering::ShaderFloatSharedPtr Rendering::MaterialSpecularConstant
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSharedPtr{ std::make_shared<ClassType>(*this) };
}
#include STSTEM_WARNING_POP