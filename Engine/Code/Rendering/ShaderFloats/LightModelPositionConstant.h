// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:59)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_MODEL_POSITION_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_LIGHT_MODEL_POSITION_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "LightConstant.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE LightModelPositionConstant : public LightConstant
	{
	public:
		using ClassType = LightModelPositionConstant;
		using ParentType = LightConstant;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		explicit LightModelPositionConstant(const LightSmartPointer& light);
		virtual ~LightModelPositionConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(LightModelPositionConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual ShaderFloatSmartPointer Clone() const override;
	};

	CORE_TOOLS_STREAM_REGISTER(LightModelPositionConstant);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, LightModelPositionConstant);
}

#endif // RENDERING_SHADER_FLOATS_LIGHT_MODEL_POSITION_CONSTANT_CONSTANT_H

 