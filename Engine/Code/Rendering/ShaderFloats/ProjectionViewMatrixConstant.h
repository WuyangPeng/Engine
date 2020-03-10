// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 17:14)

#ifndef RENDERING_SHADER_FLOATS_PROJECTION_VIEW_MATRIX_CONSTANT_H
#define RENDERING_SHADER_FLOATS_PROJECTION_VIEW_MATRIX_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ProjectionViewMatrixConstant : public ShaderFloat
	{
	public:
		using ClassType = ProjectionViewMatrixConstant;
		using ParentType = ShaderFloat;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		ProjectionViewMatrixConstant();
		virtual ~ProjectionViewMatrixConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(ProjectionViewMatrixConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual void SetNumRegisters(int numRegisters) override;

		virtual ShaderFloatSmartPointer Clone() const override;

	private:
		constexpr static auto sm_NumRegisters = 4;
	};

	CORE_TOOLS_STREAM_REGISTER(ProjectionViewMatrixConstant);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, ProjectionViewMatrixConstant);
}

#endif // RENDERING_SHADER_FLOATS_PROJECTION_VIEW_MATRIX_CONSTANT_H

  