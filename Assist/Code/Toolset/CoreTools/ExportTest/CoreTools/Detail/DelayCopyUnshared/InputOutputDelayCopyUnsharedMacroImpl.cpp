///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/16 20:25)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"

InputOutput::InputOutputDelayCopyUnsharedMacroImpl::InputOutputDelayCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputDelayCopyUnsharedMacroImpl)

int InputOutput::InputOutputDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return count;
}

void InputOutput::InputOutputDelayCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_9;

    count = aCount;
}