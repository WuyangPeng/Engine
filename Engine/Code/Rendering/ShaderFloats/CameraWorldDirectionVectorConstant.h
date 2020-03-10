// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 16:51)

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
		virtual ~CameraWorldDirectionVectorConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(CameraWorldDirectionVectorConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual void SetNumRegisters(int numRegisters) override;

		virtual ShaderFloatSmartPointer Clone() const override;

	private:
		static constexpr auto sm_NumRegisters = 1;
	};

	CORE_TOOLS_STREAM_REGISTER(CameraWorldDirectionVectorConstant);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, CameraWorldDirectionVectorConstant);
} 

#endif // RENDERING_SHADER_FLOATS_CAMERA_WORLD_DIRECTION_VECTOR_CONSTANT_H
