///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:59)

#ifndef RENDERING_SHADER_FLOATS_CAMERA_MODEL_POSITION_CONSTANT_H
#define RENDERING_SHADER_FLOATS_CAMERA_MODEL_POSITION_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CameraModelPositionConstant : public ShaderFloat
    {
    public:
        using ClassType = CameraModelPositionConstant;
        using ParentType = ShaderFloat;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        explicit CameraModelPositionConstant(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(CameraModelPositionConstant);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void Update(const Visual* visual, const Camera* camera) override;

        void SetNumRegisters(int aNumRegisters) override;

        NODISCARD ShaderFloatSharedPtr Clone() const override;

    private:
        static constexpr auto numRegisters = 1;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(CameraModelPositionConstant);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(CameraModelPositionConstant);
}

#endif  // RENDERING_SHADER_FLOATS_CAMERA_MODEL_POSITION_CONSTANT_H
