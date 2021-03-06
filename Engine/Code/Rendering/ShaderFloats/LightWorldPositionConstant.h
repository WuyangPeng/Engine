// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 17:01)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_WORLD_POSITION_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_LIGHT_WORLD_POSITION_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "LightConstant.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE LightWorldPositionConstant : public LightConstant
	{
	public:
		using ClassType = LightWorldPositionConstant;
		using ParentType = LightConstant;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		explicit LightWorldPositionConstant(const LightSharedPtr& light);
		 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(LightWorldPositionConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

		  void Update(const Visual* visual, const Camera* camera) override;

		  ShaderFloatSharedPtr Clone() const override;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(LightWorldPositionConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( LightWorldPositionConstant);
}

#endif // RENDERING_SHADER_FLOATS_LIGHT_WORLD_POSITION_CONSTANT_CONSTANT_H

 