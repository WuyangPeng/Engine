// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:59)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_SPECULAR_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_LIGHT_SPECULAR_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "LightConstant.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE LightSpecularConstant : public LightConstant
	{
	public:
		using ClassType = LightSpecularConstant;
		using ParentType = LightConstant;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		explicit LightSpecularConstant(const LightSmartPointer& light);
		virtual ~LightSpecularConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(LightSpecularConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual ShaderFloatSmartPointer Clone() const override;
	};

	CORE_TOOLS_STREAM_REGISTER(LightSpecularConstant);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, LightSpecularConstant);
}

#endif // RENDERING_SHADER_FLOATS_LIGHT_SPECULAR_CONSTANT_CONSTANT_H

  