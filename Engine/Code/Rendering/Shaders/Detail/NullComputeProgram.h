/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 14:57)

#ifndef RENDERING_SHADERS_NULL_COMPUTE_PROGRAM_H
#define RENDERING_SHADERS_NULL_COMPUTE_PROGRAM_H

#include "Rendering/RenderingDll.h"

#include "ComputeProgramImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE NullComputeProgram final : public ComputeProgramImpl
    {
    public:
        using ClassType = NullComputeProgram;
        using ParentType = ComputeProgramImpl;

    public:
        NullComputeProgram() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD OpenGLUInt GetProgramHandle() const noexcept override;
        NODISCARD Reflection GetReflector() const override;
        NODISCARD ComputeProgramSharedPtr Clone() const override;
    };
}

#endif  // RENDERING_SHADERS_NULL_COMPUTE_PROGRAM_H
