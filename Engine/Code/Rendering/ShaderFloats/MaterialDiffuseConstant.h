// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 17:03)

#ifndef RENDERING_SHADER_FLOATS_MATERIAL_DIFFUSE_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_MATERIAL_DIFFUSE_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "MaterialConstant.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE MaterialDiffuseConstant : public MaterialConstant
	{
	public:
		using ClassType = MaterialDiffuseConstant;
		using ParentType = MaterialConstant;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		explicit MaterialDiffuseConstant(const MaterialSharedPtr& material);
		 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(MaterialDiffuseConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 

		  void Update(const Visual* visual, const Camera* camera) override;

		  ShaderFloatSharedPtr Clone() const override;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(MaterialDiffuseConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( MaterialDiffuseConstant);
}

#endif // RENDERING_SHADER_FLOATS_MATERIAL_DIFFUSE_CONSTANT_CONSTANT_H
 