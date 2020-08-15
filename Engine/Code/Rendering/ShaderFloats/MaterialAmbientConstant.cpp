// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 18:03)

#include "Rendering/RenderingExport.h"

#include "MaterialAmbientConstant.h"
#include "System/Helper/UnusedMacro.h"
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
CORE_TOOLS_RTTI_DEFINE(Rendering, MaterialAmbientConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, MaterialAmbientConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, MaterialAmbientConstant); 
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, MaterialAmbientConstant);

Rendering::MaterialAmbientConstant
	::MaterialAmbientConstant(const MaterialSmartPointer& material)
	:ParentType{ material }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}
 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,MaterialAmbientConstant)

void Rendering::MaterialAmbientConstant
	::Update(const Visual* visual, const Camera* camera)
{
	RENDERING_CLASS_IS_VALID_1;

	const auto colour = GetMaterial()->GetAmbient();
	SetRegister(0, colour);

	SYSTEM_UNUSED_ARG(visual);
	SYSTEM_UNUSED_ARG(camera);
}

Rendering::ShaderFloatSmartPointer Rendering::MaterialAmbientConstant
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSmartPointer{ std::make_shared<ClassType>(*this) };
}

 #include STSTEM_WARNING_POP