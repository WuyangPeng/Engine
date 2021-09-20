// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 17:17)

#ifndef RENDERING_SHADER_FLOATS_PROJECTOR_WORLD_POSITION_CONSTANT_H
#define RENDERING_SHADER_FLOATS_PROJECTOR_WORLD_POSITION_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"
#include "Rendering/SceneGraph/Projector.h"

EXPORT_SHARED_PTR(Rendering, ProjectorConstantImpl, RENDERING_DEFAULT_DECLARE);
 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
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
		explicit ProjectorWorldPositionConstant(const ProjectorSharedPtr& projector);
		 

 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ProjectorWorldPositionConstant);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

		  void Update(const Visual* visual, const Camera* camera) override;

		  void SetNumRegisters(int numRegisters) override;

		const ConstProjectorSharedPtr GetProjector() const;

		  ShaderFloatSharedPtr Clone() const override;

	private:
		constexpr static auto sm_NumRegisters = 1;

	private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(ProjectorWorldPositionConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( ProjectorWorldPositionConstant);
}
#include STSTEM_WARNING_POP

#endif // RENDERING_SHADER_FLOATS_PROJECTOR_WORLD_POSITION_CONSTANT_H


 