///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:59)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_ATTENUATION_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_LIGHT_ATTENUATION_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "LightConstant.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE LightAttenuationConstant : public LightConstant
    {
    public:
        using ClassType = LightAttenuationConstant;
        using ParentType = LightConstant;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        explicit LightAttenuationConstant(const LightSharedPtr& light);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(LightAttenuationConstant);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void Update(MAYBE_UNUSED const Visual* visual, MAYBE_UNUSED const Camera* camera) override;

        NODISCARD ShaderFloatSharedPtr Clone() const override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(LightAttenuationConstant);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(LightAttenuationConstant);
}

#endif  // RENDERING_SHADER_FLOATS_LIGHT_ATTENUATION_CONSTANT_CONSTANT_H
