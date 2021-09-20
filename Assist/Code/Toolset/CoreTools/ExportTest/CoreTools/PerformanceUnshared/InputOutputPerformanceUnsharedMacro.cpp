///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/14 16:14)

#include "InputOutput/InputOutputExport.h"

#include "InputOutputPerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/InputOutputPerformanceUnsharedMacroImpl.h"

InputOutput::InputOutputPerformanceUnsharedMacro::InputOutputPerformanceUnsharedMacro(int count)
    : impl{ count }
{
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(InputOutput, InputOutputPerformanceUnsharedMacro)

int InputOutput::InputOutputPerformanceUnsharedMacro::GetCount() const noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}