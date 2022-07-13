///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:39)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"

InputOutput::InputOutputCopyUnsharedMacroImpl::InputOutputCopyUnsharedMacroImpl(int count) noexcept
    : mCount{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputCopyUnsharedMacroImpl)

int InputOutput::InputOutputCopyUnsharedMacroImpl::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void InputOutput::InputOutputCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_9;

    mCount = count;
}