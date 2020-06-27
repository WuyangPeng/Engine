// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:55)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_AMBIENT_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_LIGHT_AMBIENT_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "LightConstant.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE LightAmbientConstant : public LightConstant
	{
	public:
		using ClassType = LightAmbientConstant;
		using ParentType = LightConstant;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		explicit LightAmbientConstant(const LightSmartPointer& light);
		virtual ~LightAmbientConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(LightAmbientConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual ShaderFloatSmartPointer Clone() const override;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(LightAmbientConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, LightAmbientConstant);
}

#endif // RENDERING_SHADER_FLOATS_LIGHT_AMBIENT_CONSTANT_CONSTANT_H

 