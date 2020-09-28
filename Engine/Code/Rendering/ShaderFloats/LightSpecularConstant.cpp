// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 17:59)

#include "Rendering/RenderingExport.h"

#include "LightSpecularConstant.h"

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
CORE_TOOLS_RTTI_DEFINE(Rendering, LightSpecularConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightSpecularConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightSpecularConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, LightSpecularConstant);

Rendering::LightSpecularConstant
	::LightSpecularConstant(const LightSmartPointer& light)
	:ParentType{ light }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,LightSpecularConstant)

void Rendering::LightSpecularConstant ::Update([[maybe_unused]] const Visual* visual, [[maybe_unused]] const Camera* camera)
{
	RENDERING_CLASS_IS_VALID_1;

	auto light = GetLight();

	SetRegister(0, light->GetSpecular());

	 
}

Rendering::ShaderFloatSmartPointer Rendering::LightSpecularConstant
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSmartPointer{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP