///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:24)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Shared/InputOutputMacroSharedImpl.h"

InputOutput::InputOutputMacroShared::InputOutputMacroShared(int count)
    : impl{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputMacroShared)

int InputOutput::InputOutputMacroShared::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void InputOutput::InputOutputMacroShared::SetCount(int count) noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* InputOutput::InputOutputMacroShared::GetAddress() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}