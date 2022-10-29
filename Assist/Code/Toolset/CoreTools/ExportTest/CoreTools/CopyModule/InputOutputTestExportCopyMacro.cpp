///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 16:26)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/InputOutputTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(InputOutput, InputOutputTestExportCopyMacro)

InputOutput::InputOutputTestExportCopyMacro::InputOutputTestExportCopyMacro(int count)
    : impl{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputTestExportCopyMacro)

int InputOutput::InputOutputTestExportCopyMacro::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void InputOutput::InputOutputTestExportCopyMacro::SetCount(int count) noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

