// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 17:13)

#ifndef RENDERING_SHADER_FLOATS_MATERIAL_SPECULAR_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_MATERIAL_SPECULAR_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "MaterialConstant.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE MaterialSpecularConstant : public MaterialConstant
	{
	public:
		using ClassType = MaterialSpecularConstant;
		using ParentType = MaterialConstant;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		explicit MaterialSpecularConstant(const MaterialSharedPtr& material);
		 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(MaterialSpecularConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 

		  void Update(const Visual* visual, const Camera* camera) override;

		  ShaderFloatSharedPtr Clone() const override;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(MaterialSpecularConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( MaterialSpecularConstant);
}

#endif // RENDERING_SHADER_FLOATS_MATERIAL_SPECULAR_CONSTANT_CONSTANT_H
 