/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:14)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputPerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"

InputOutput::InputOutputPerformanceUnsharedMacroImpl::InputOutputPerformanceUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputPerformanceUnsharedMacroImpl)

int InputOutput::InputOutputPerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return count;
}
