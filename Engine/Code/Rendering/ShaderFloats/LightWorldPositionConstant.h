///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 14:38)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_WORLD_POSITION_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_LIGHT_WORLD_POSITION_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "LightConstant.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE LightWorldPositionConstant : public LightConstant
    {
    public:
        using ClassType = LightWorldPositionConstant;
        using ParentType = LightConstant;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        explicit LightWorldPositionConstant(const LightSharedPtr& light);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(LightWorldPositionConstant);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void Update(const Visual* visual, const Camera* camera) override;

        NODISCARD ShaderFloatSharedPtr Clone() const override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(LightWorldPositionConstant);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(LightWorldPositionConstant);
}

#endif  // RENDERING_SHADER_FLOATS_LIGHT_WORLD_POSITION_CONSTANT_CONSTANT_H
