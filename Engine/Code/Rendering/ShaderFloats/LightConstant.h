///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:59)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/LocalEffects/Light.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(LightConstant, LightConstantImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE LightConstant : public ShaderFloat
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(LightConstant);
        using ParentType = ShaderFloat;

    public:
        explicit LightConstant(const LightSharedPtr& light);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(LightConstant);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        void Update(const Visual* visual, const Camera* camera) = 0;

        void SetNumRegisters(int aNmRegisters) override;

        NODISCARD ConstLightSharedPtr GetLight() const noexcept;

    private:
        constexpr static auto numRegisters = 1;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(LightConstant);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(LightConstant);
}

#endif  // RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_H
