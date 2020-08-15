// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 17:52)

#include "Rendering/RenderingExport.h"

#include "LightAttenuationConstant.h"
#include "System/Helper/UnusedMacro.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
CORE_TOOLS_RTTI_DEFINE(Rendering, LightAttenuationConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightAttenuationConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightAttenuationConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, LightAttenuationConstant);

Rendering::LightAttenuationConstant
	::LightAttenuationConstant(const LightSmartPointer& light)
	:ParentType{ light }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,LightAttenuationConstant)

void Rendering::LightAttenuationConstant
	::Update(const Visual* visual, const Camera* camera)
{
	RENDERING_CLASS_IS_VALID_1;

	auto light = GetLight();

	vector<float> data{ light->GetConstant() ,light->GetLinear(),light->GetQuadratic(), light->GetIntensity() };
 	 
	SetRegister(0, data);

	SYSTEM_UNUSED_ARG(visual);
	SYSTEM_UNUSED_ARG(camera);
}

Rendering::ShaderFloatSmartPointer Rendering::LightAttenuationConstant
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSmartPointer{ std::make_shared<ClassType>(*this) };
}

 #include STSTEM_WARNING_POP