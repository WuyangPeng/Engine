// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:51)

#ifndef RENDERING_SHADER_FLOATS_CAMERA_WORLD_DIRECTION_VECTOR_CONSTANT_H
#define RENDERING_SHADER_FLOATS_CAMERA_WORLD_DIRECTION_VECTOR_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE CameraWorldDirectionVectorConstant : public ShaderFloat
	{
	public:
		using ClassType = CameraWorldDirectionVectorConstant;
		using ParentType = ShaderFloat;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		CameraWorldDirectionVectorConstant(); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(CameraWorldDirectionVectorConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

		  void Update(const Visual* visual, const Camera* camera) override;

		  void SetNumRegisters(int numRegisters) override;

		  ShaderFloatSharedPtr Clone() const override;

	private:
		static constexpr auto sm_NumRegisters = 1;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(CameraWorldDirectionVectorConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( CameraWorldDirectionVectorConstant);
} 

#endif // RENDERING_SHADER_FLOATS_CAMERA_WORLD_DIRECTION_VECTOR_CONSTANT_H
