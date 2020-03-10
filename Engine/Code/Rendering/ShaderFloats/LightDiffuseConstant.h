// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:57)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_DIFFUSE_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_LIGHT_DIFFUSE_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "LightConstant.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE LightDiffuseConstant : public LightConstant
	{
	public:
		using ClassType = LightDiffuseConstant;
		using ParentType = LightConstant;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		explicit LightDiffuseConstant(const LightSmartPointer& light);
		virtual ~LightDiffuseConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(LightDiffuseConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual ShaderFloatSmartPointer Clone() const override;
	};

	CORE_TOOLS_STREAM_REGISTER(LightDiffuseConstant);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, LightDiffuseConstant);
}

#endif // RENDERING_SHADER_FLOATS_LIGHT_DIFFUSE_CONSTANT_CONSTANT_H


 
 