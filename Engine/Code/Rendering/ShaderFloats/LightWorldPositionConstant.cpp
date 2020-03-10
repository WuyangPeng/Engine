// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 18:00)

#include "Rendering/RenderingExport.h"

#include "LightWorldPositionConstant.h"
#include "System/Helper/UnusedMacro.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, LightWorldPositionConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightWorldPositionConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightWorldPositionConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, LightWorldPositionConstant);

Rendering::LightWorldPositionConstant
	::LightWorldPositionConstant(const LightSmartPointer& light)
	:ParentType{ light }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::LightWorldPositionConstant
	::~LightWorldPositionConstant()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,LightWorldPositionConstant)

void Rendering::LightWorldPositionConstant
	::Update(const Visual* visual, const Camera* camera)
{
	RENDERING_CLASS_IS_VALID_1;

	auto light = GetLight();
	const auto& worldPosition = light->GetPosition();
	 
	SetRegister(0, worldPosition); 

	SYSTEM_UNUSED_ARG(camera);
	SYSTEM_UNUSED_ARG(visual);
}

Rendering::ShaderFloatSmartPointer Rendering::LightWorldPositionConstant
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSmartPointer{ NEW0 ClassType(*this) };
}

