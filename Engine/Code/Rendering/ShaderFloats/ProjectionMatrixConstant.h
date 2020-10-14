// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 17:14)

#ifndef RENDERING_SHADER_FLOATS_PROJECTION_MATRIX_CONSTANT_H
#define RENDERING_SHADER_FLOATS_PROJECTION_MATRIX_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ProjectionMatrixConstant : public ShaderFloat
	{
	public:
		using ClassType = ProjectionMatrixConstant;
		using ParentType = ShaderFloat;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		ProjectionMatrixConstant();
		 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(ProjectionMatrixConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 

		  void Update(const Visual* visual, const Camera* camera) override;

		  void SetNumRegisters(int numRegisters) override;

		  ShaderFloatSharedPtr Clone() const override;

	private:
		constexpr static auto sm_NumRegisters = 4;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(ProjectionMatrixConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( ProjectionMatrixConstant);
}

#endif // RENDERING_SHADER_FLOATS_PROJECTION_MATRIX_CONSTANT_H

 