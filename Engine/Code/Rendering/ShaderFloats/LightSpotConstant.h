///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:00)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_SPOT_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_LIGHT_SPOT_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "LightConstant.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE LightSpotConstant : public LightConstant
    {
    public:
        using ClassType = LightSpotConstant;
        using ParentType = LightConstant;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        explicit LightSpotConstant(const LightSharedPtr& light);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(LightSpotConstant);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void Update(MAYBE_UNUSED const Visual* visual, MAYBE_UNUSED const Camera* camera) override;

        NODISCARD ShaderFloatSharedPtr Clone() const override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(LightSpotConstant);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(LightSpotConstant);
}

#endif  // RENDERING_SHADER_FLOATS_LIGHT_SPOT_CONSTANT_CONSTANT_H
