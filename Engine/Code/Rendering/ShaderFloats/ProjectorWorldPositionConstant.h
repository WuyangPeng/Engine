// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 17:17)

#ifndef RENDERING_SHADER_FLOATS_PROJECTOR_WORLD_POSITION_CONSTANT_H
#define RENDERING_SHADER_FLOATS_PROJECTOR_WORLD_POSITION_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"
#include "Rendering/SceneGraph/Projector.h"

#include <boost/shared_ptr.hpp>

RENDERING_EXPORT_SHARED_PTR(ProjectorConstantImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ProjectorWorldPositionConstant : public ShaderFloat
	{
	public:
		using ClassType = ProjectorWorldPositionConstant;
		using ImplType = ProjectorConstantImpl;
		using ParentType = ShaderFloat;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		explicit ProjectorWorldPositionConstant(const ProjectorSmartPointer& projector);
		virtual ~ProjectorWorldPositionConstant();

		ProjectorWorldPositionConstant(const ProjectorWorldPositionConstant& rhs);
		ProjectorWorldPositionConstant& operator=(const ProjectorWorldPositionConstant& rhs);

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ProjectorWorldPositionConstant);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual void SetNumRegisters(int numRegisters) override;

		const ConstProjectorSmartPointer GetProjector() const;

		virtual ShaderFloatSmartPointer Clone() const override;

	private:
		constexpr static auto sm_NumRegisters = 1;

	private:
		IMPL_TYPE_DECLARE(ProjectorWorldPositionConstant);
	};

	CORE_TOOLS_STREAM_REGISTER(ProjectorWorldPositionConstant);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, ProjectorWorldPositionConstant);
}

#endif // RENDERING_SHADER_FLOATS_PROJECTOR_WORLD_POSITION_CONSTANT_H


 