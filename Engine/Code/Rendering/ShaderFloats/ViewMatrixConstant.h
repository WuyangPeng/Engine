// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 17:20)

#ifndef RENDERING_SHADER_FLOATS_VIEW_MATRIX_CONSTANT_H
#define RENDERING_SHADER_FLOATS_VIEW_MATRIX_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ViewMatrixConstant : public ShaderFloat
	{
	public:
		using ClassType = ViewMatrixConstant;
		using ParentType = ShaderFloat;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		ViewMatrixConstant();
		virtual ~ViewMatrixConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(ViewMatrixConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual void SetNumRegisters(int numRegisters) override;

		virtual ShaderFloatSmartPointer Clone() const override;

	private:
		constexpr static auto sm_NumRegisters = 4;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(ViewMatrixConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, ViewMatrixConstant);
}

#endif // RENDERING_SHADER_FLOATS_VIEW_MATRIX_CONSTANT_H

  