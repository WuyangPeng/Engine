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
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ProjectorMatrixConstant : public ShaderFloat
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(ProjectorMatrixConstant,DESTRUCTOR_DEFAULT);
        using ParentType = ShaderFloat;

    public:
        // …Ë÷√biasScaleMatrixIndexŒ™0æÿ’Û”≥…‰ y' = (1 - y) / 2°£
        // …Ë÷√biasScaleMatrixIndexŒ™1æÿ’Û”≥…‰ y' = (1 + y) / 2°£
        ProjectorMatrixConstant(const ProjectorSharedPtr& projector, bool biased, int biasScaleMatrixIndex);
        

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ProjectorMatrixConstant);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        void Update(const Visual* visual, const Camera* camera) override;

        void SetNumRegisters(int numRegisters) override;

        const ConstProjectorSharedPtr GetProjector() const;

        ShaderFloatSharedPtr Clone() const override;

    private:
        constexpr static auto sm_NumRegisters = 4;

    private:
        IMPL_TYPE_DECLARE(ProjectorMatrixConstant);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(ProjectorMatrixConstant);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( ProjectorMatrixConstant);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_SHADER_FLOATS_PROJECTOR_MATRIX_CONSTANT_H
