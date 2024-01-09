/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:05)

#include "Rendering/RenderingExport.h"

#include "NullComputeProgram.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Shaders/Reflection.h"

Rendering::NullComputeProgram::NullComputeProgram() noexcept
    : ParentType{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, NullComputeProgram)

Rendering::ComputeProgramImpl::OpenGLUInt Rendering::NullComputeProgram::GetProgramHandle() const noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    return 0;
}

Rendering::Reflection Rendering::NullComputeProgram::GetReflector() const
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("GetReflector错误。"))
}

Rendering::ComputeProgramImpl::ComputeProgramSharedPtr Rendering::NullComputeProgram::Clone() const
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    return std::make_shared<NullComputeProgram>();
}
