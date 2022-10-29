///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 11:23)

#ifndef EXPORT_TEST_INPUT_OUTPUT_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_INPUT_OUTPUT_DELAY_COPY_UNSHARED_MACRO_H

#include "InputOutput/InputOutputDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

INPUT_OUTPUT_DELAY_COPY_UNSHARED_EXPORT_IMPL(InputOutputDelayCopyUnsharedMacro, InputOutputDelayCopyUnsharedMacroImpl);

namespace InputOutput
{
    class INPUT_OUTPUT_DEFAULT_DECLARE InputOutputDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(InputOutputDelayCopyUnsharedMacro);

    public:
        explicit InputOutputDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_INPUT_OUTPUT_DELAY_COPY_UNSHARED_MACRO_H