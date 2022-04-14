// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 17:55)

#include "Rendering/RenderingExport.h"

#include "LightModelDirectionVectorConstant.h"

#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26486)
CORE_TOOLS_RTTI_DEFINE(Rendering, LightModelDirectionVectorConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightModelDirectionVectorConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightModelDirectionVectorConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, LightModelDirectionVectorConstant);

Rendering::LightModelDirectionVectorConstant
	::LightModelDirectionVectorConstant(const LightSharedPtr& light)
	:ParentType{ light }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}
 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,LightModelDirectionVectorConstant)

void Rendering::LightModelDirectionVectorConstant::Update(const Visual* visual, [[maybe_unused]] const Camera* camera)
{
	RENDERING_CLASS_IS_VALID_1;

	auto light = GetLight();
	const auto worldInverseMatrix = visual->GetWorldTransform().GetInverseMatrix();
        const auto modelDirectionVector = worldInverseMatrix * light->GetDirectionVector();

	SetRegister(0, modelDirectionVector);
 
}

Rendering::ShaderFloatSharedPtr Rendering::LightModelDirectionVectorConstant
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP