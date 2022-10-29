///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:35)

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

 