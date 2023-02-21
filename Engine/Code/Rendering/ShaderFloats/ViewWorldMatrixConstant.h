///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/08 16:29)

#ifndef RENDERING_SHADER_FLOATS_VIEW_WORLD_MATRIX_CONSTANT_H
#define RENDERING_SHADER_FLOATS_VIEW_WORLD_MATRIX_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ViewWorldMatrixConstant : public ShaderFloat
    {
    public:
        using ClassType = ViewWorldMatrixConstant;
        using ParentType = ShaderFloat;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        explicit ViewWorldMatrixConstant(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ViewWorldMatrixConstant);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void Update(const Visual* visual, const Camera* camera) override;

        void SetNumRegisters(int aNumRegisters) override;

        NODISCARD ShaderFloatSharedPtr Clone() const override;

    private:
        constexpr static auto numRegisters = 4;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ViewWorldMatrixConstant);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ViewWorldMatrixConstant);
}

#endif  // RENDERING_SHADER_FLOATS_VIEW_WORLD_MATRIX_CONSTANT_H
