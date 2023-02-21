///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:20)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputNonCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"

InputOutput::InputOutputNonCopyMacroImpl::InputOutputNonCopyMacroImpl(int count) noexcept
    : count{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputNonCopyMacroImpl)

int InputOutput::InputOutputNonCopyMacroImpl::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return count;
}

void InputOutput::InputOutputNonCopyMacroImpl::SetCount(int aCount) noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_9;

    count = aCount;
}