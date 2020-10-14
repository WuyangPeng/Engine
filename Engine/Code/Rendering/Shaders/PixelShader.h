// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:19)

#ifndef RENDERING_SHADERS_PIXEL_SHADER_H
#define RENDERING_SHADERS_PIXEL_SHADER_H

#include "ShaderBase.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PixelShader : public ShaderBase
    {
    public:
        using ClassType = PixelShader;
        using ParentType = ShaderBase;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        PixelShader(const std::string& programName, int numInputs, int numOutputs, int numConstants, int numSamplers);
        ~PixelShader();
        PixelShader(const PixelShader&) = default;
        PixelShader& operator=(const PixelShader&) = default;
        PixelShader(PixelShader&&) noexcept = default;
        PixelShader& operator=(PixelShader&&) noexcept = default;
        CLASS_INVARIANT_OVERRIDE_DECLARE;
         ObjectInterfaceSharedPtr CloneObject() const override;
        CORE_TOOLS_OBJECT_FACTORY_DECLARE(PixelShader);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(PixelShader);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( PixelShader);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_SHADERS_PIXEL_SHADER_H
