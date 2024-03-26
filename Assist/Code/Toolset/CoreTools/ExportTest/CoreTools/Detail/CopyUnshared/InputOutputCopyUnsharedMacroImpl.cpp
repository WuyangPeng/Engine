/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:06)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"

InputOutput::InputOutputCopyUnsharedMacroImpl::InputOutputCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputCopyUnsharedMacroImpl)

int InputOutput::InputOutputCopyUnsharedMacroImpl::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return count;
}

void InputOutput::InputOutputCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_9;

    count = aCount;
}