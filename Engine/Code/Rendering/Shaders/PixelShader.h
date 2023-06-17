///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:43)

#ifndef RENDERING_SHADERS_PIXEL_SHADER_H
#define RENDERING_SHADERS_PIXEL_SHADER_H

#include "Rendering/RenderingDll.h"

#include "ShaderBase.h"

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

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(PixelShader);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(PixelShader);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(PixelShader);
}

#endif  // RENDERING_SHADERS_PIXEL_SHADER_H
