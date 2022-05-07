///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 18:29)

#ifndef RENDERING_SHADERS_VERTEX_SHADER_H
#define RENDERING_SHADERS_VERTEX_SHADER_H

#include "ShaderBase.h"

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

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(VertexShader);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(VertexShader);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VertexShader);
}

#endif  // RENDERING_SHADERS_VERTEX_SHADER_H
