/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:59)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/InputOutputCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(InputOutput, InputOutputCopyUnsharedMacro)

InputOutput::InputOutputCopyUnsharedMacro::InputOutputCopyUnsharedMacro(int count)
    : impl{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputCopyUnsharedMacro)

int InputOutput::InputOutputCopyUnsharedMacro::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void InputOutput::InputOutputCopyUnsharedMacro::SetCount(int count) noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* InputOutput::InputOutputCopyUnsharedMacro::GetAddress() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}