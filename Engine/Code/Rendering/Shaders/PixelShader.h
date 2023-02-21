///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/13 14:41)

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
