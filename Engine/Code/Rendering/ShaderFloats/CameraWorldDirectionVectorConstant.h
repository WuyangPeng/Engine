///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:59)

#ifndef RENDERING_SHADER_FLOATS_CAMERA_WORLD_DIRECTION_VECTOR_CONSTANT_H
#define RENDERING_SHADER_FLOATS_CAMERA_WORLD_DIRECTION_VECTOR_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CameraWorldDirectionVectorConstant : public ShaderFloat
    {
    public:
        using ClassType = CameraWorldDirectionVectorConstant;
        using ParentType = ShaderFloat;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        explicit CameraWorldDirectionVectorConstant(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(CameraWorldDirectionVectorConstant);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void Update(MAYBE_UNUSED const Visual* visual, const Camera* camera) override;

        void SetNumRegisters(int aNumRegisters) override;

        NODISCARD ShaderFloatSharedPtr Clone() const override;

    private:
        static constexpr auto numRegisters = 1;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(CameraWorldDirectionVectorConstant);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(CameraWorldDirectionVectorConstant);
}

#endif  // RENDERING_SHADER_FLOATS_CAMERA_WORLD_DIRECTION_VECTOR_CONSTANT_H
