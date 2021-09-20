///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 22:20)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"

InputOutput::InputOutputTestExportCopyMacroImpl::InputOutputTestExportCopyMacroImpl(int count) noexcept
    : m_Count{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputTestExportCopyMacroImpl)

int InputOutput::InputOutputTestExportCopyMacroImpl::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void InputOutput::InputOutputTestExportCopyMacroImpl::SetCount(int count) noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_9;

    m_Count = count;
}