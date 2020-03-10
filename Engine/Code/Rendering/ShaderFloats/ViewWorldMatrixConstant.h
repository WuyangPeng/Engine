// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 17:21)

#ifndef RENDERING_SHADER_FLOATS_VIEW_WORLD_MATRIX_CONSTANT_H
#define RENDERING_SHADER_FLOATS_VIEW_WORLD_MATRIX_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ViewWorldMatrixConstant : public ShaderFloat
	{
	public:
		using ClassType = ViewWorldMatrixConstant;
		using ParentType = ShaderFloat;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		ViewWorldMatrixConstant();
		virtual ~ViewWorldMatrixConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(ViewWorldMatrixConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual void SetNumRegisters(int numRegisters) override;

		virtual ShaderFloatSmartPointer Clone() const override;

	private:
		constexpr static auto sm_NumRegisters = 4;
	};

	CORE_TOOLS_STREAM_REGISTER(ViewWorldMatrixConstant);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, ViewWorldMatrixConstant);
}

#endif // RENDERING_SHADER_FLOATS_VIEW_WORLD_MATRIX_CONSTANT_H

