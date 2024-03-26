/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 10:16)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"

InputOutput::InputOutputMacroSharedImpl::InputOutputMacroSharedImpl(int count) noexcept
    : count{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputMacroSharedImpl)

int InputOutput::InputOutputMacroSharedImpl::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return count;
}

void InputOutput::InputOutputMacroSharedImpl::SetCount(int aCount) noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_9;

    count = aCount;
}