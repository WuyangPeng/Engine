// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:49)

#ifndef RENDERING_SHADER_FLOATS_CAMERA_MODEL_DIRECTION_VECTOR_CONSTANT_H
#define RENDERING_SHADER_FLOATS_CAMERA_MODEL_DIRECTION_VECTOR_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE CameraModelDirectionVectorConstant : public ShaderFloat
	{
	public:
		using ClassType = CameraModelDirectionVectorConstant;
		using ParentType = ShaderFloat;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		CameraModelDirectionVectorConstant(); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(CameraModelDirectionVectorConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
 
		  void Update (const Visual* visual, const Camera* camera) override;

		  void SetNumRegisters(int numRegisters) override;

		  ShaderFloatSmartPointer Clone() const override;

	private:
		static constexpr auto sm_NumRegisters = 1;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(CameraModelDirectionVectorConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, CameraModelDirectionVectorConstant);
}

#endif // RENDERING_SHADER_FLOATS_CAMERA_MODEL_DIRECTION_VECTOR_CONSTANT_H
