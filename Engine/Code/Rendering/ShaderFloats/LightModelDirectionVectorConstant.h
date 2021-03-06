// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 16:58)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_MODEL_DIRECTION_VECTOR_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_LIGHT_MODEL_DIRECTION_VECTOR_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "LightConstant.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE LightModelDirectionVectorConstant : public LightConstant
	{
	public:
		using ClassType = LightModelDirectionVectorConstant;
		using ParentType = LightConstant;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		explicit LightModelDirectionVectorConstant(const LightSharedPtr& light);
		 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(LightModelDirectionVectorConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

		  void Update(const Visual* visual, const Camera* camera) override;

		  ShaderFloatSharedPtr Clone() const override;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(LightModelDirectionVectorConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( LightModelDirectionVectorConstant);
}

#endif // RENDERING_SHADER_FLOATS_LIGHT_MODEL_DIRECTION_VECTOR_CONSTANT_CONSTANT_H


 
