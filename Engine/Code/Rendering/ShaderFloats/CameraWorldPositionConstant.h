// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:55)

#ifndef RENDERING_SHADER_FLOATS_CAMERA_WORLD_POSITION_CONSTANT_H
#define RENDERING_SHADER_FLOATS_CAMERA_WORLD_POSITION_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE CameraWorldPositionConstant : public ShaderFloat
	{
	public:
		using ClassType = CameraWorldPositionConstant;
		using ParentType = ShaderFloat;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		CameraWorldPositionConstant();
		virtual ~CameraWorldPositionConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(CameraWorldPositionConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual void SetNumRegisters(int numRegisters) override;

		virtual ShaderFloatSmartPointer Clone() const override;

	private:
		const static int sm_NumRegisters = 1;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(CameraWorldPositionConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, CameraWorldPositionConstant);
}

#endif // RENDERING_SHADER_FLOATS_CAMERA_WORLD_POSITION_CONSTANT_H
 