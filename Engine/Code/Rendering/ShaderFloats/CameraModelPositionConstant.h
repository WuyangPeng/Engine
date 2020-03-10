// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:50)

#ifndef RENDERING_SHADER_FLOATS_CAMERA_MODEL_POSITION_CONSTANT_H
#define RENDERING_SHADER_FLOATS_CAMERA_MODEL_POSITION_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
 	class RENDERING_DEFAULT_DECLARE CameraModelPositionConstant : public ShaderFloat
	{
	public:
		using ClassType = CameraModelPositionConstant;
		using ParentType = ShaderFloat;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		CameraModelPositionConstant();
		virtual ~CameraModelPositionConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(CameraModelPositionConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual void SetNumRegisters(int numRegisters) override;

		virtual ShaderFloatSmartPointer Clone() const override;

	private:
		static constexpr auto sm_NumRegisters = 1;
	};

	CORE_TOOLS_STREAM_REGISTER(CameraModelPositionConstant);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, CameraModelPositionConstant);
}

#endif // RENDERING_SHADER_FLOATS_CAMERA_MODEL_POSITION_CONSTANT_H
