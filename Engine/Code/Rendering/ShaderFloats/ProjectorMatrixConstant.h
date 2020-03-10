// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 17:16)

#ifndef RENDERING_SHADER_FLOATS_PROJECTOR_MATRIX_CONSTANT_H
#define RENDERING_SHADER_FLOATS_PROJECTOR_MATRIX_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/SceneGraph/Projector.h"

RENDERING_EXPORT_SHARED_PTR(ProjectorMatrixConstantImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ProjectorMatrixConstant : public ShaderFloat
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(ProjectorMatrixConstant);
		using ParentType = ShaderFloat;

	public:
		// …Ë÷√biasScaleMatrixIndexŒ™0æÿ’Û”≥…‰ y' = (1 - y) / 2°£
		// …Ë÷√biasScaleMatrixIndexŒ™1æÿ’Û”≥…‰ y' = (1 + y) / 2°£
		ProjectorMatrixConstant(const ProjectorSmartPointer& projector,bool biased, int biasScaleMatrixIndex);
		virtual ~ProjectorMatrixConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ProjectorMatrixConstant);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual void SetNumRegisters(int numRegisters) override;

		const ConstProjectorSmartPointer GetProjector() const;

		virtual ShaderFloatSmartPointer Clone() const override;

	private:
		constexpr static auto sm_NumRegisters = 4;

	private:
		IMPL_TYPE_DECLARE(ProjectorMatrixConstant);
	};

	CORE_TOOLS_STREAM_REGISTER(ProjectorMatrixConstant);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, ProjectorMatrixConstant);
}

#endif // RENDERING_SHADER_FLOATS_PROJECTOR_MATRIX_CONSTANT_H


 
