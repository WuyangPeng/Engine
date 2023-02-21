///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:34)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputNonCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/NonCopy/InputOutputNonCopyMacroImpl.h"

InputOutput::InputOutputNonCopyMacro::InputOutputNonCopyMacro(int count)
    : impl{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputNonCopyMacro)

int InputOutput::InputOutputNonCopyMacro::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void InputOutput::InputOutputNonCopyMacro::SetCount(int count) noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
