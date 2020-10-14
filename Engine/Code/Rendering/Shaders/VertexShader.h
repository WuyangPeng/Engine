// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:31)

#ifndef RENDERING_SHADERS_VERTEX_SHADER_H
#define RENDERING_SHADERS_VERTEX_SHADER_H

#include "ShaderBase.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexShader : public ShaderBase
    {
    public:
        using ClassType = VertexShader;
        using ParentType = ShaderBase;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        VertexShader(const std::string& programName, int numInputs, int numOutputs, int numConstants, int numSamplers);
        ~VertexShader();
        VertexShader(const VertexShader&) = default;
        VertexShader& operator=(const VertexShader&) = default;
        VertexShader(VertexShader&&) noexcept = default;
        VertexShader& operator=(VertexShader&&) noexcept = default;
        ObjectInterfaceSharedPtr CloneObject() const override;
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(VertexShader);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(VertexShader);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( VertexShader);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_SHADERS_VERTEX_SHADER_H
