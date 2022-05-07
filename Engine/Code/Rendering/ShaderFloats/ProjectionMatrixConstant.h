///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 14:53)

#ifndef RENDERING_SHADER_FLOATS_PROJECTION_MATRIX_CONSTANT_H
#define RENDERING_SHADER_FLOATS_PROJECTION_MATRIX_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ProjectionMatrixConstant : public ShaderFloat
    {
    public:
        using ClassType = ProjectionMatrixConstant;
        using ParentType = ShaderFloat;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        explicit ProjectionMatrixConstant(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ProjectionMatrixConstant);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void Update(const Visual* visual, const Camera* camera) override;

        void SetNumRegisters(int aNumRegisters) override;

        NODISCARD ShaderFloatSharedPtr Clone() const override;

    private:
        constexpr static auto numRegisters = 4;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(ProjectionMatrixConstant);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ProjectionMatrixConstant);
}

#endif  // RENDERING_SHADER_FLOATS_PROJECTION_MATRIX_CONSTANT_H
