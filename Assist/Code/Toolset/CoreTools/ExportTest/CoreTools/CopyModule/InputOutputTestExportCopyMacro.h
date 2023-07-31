///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:54)

#ifndef EXPORT_TEST_INPUT_OUTPUT_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_INPUT_OUTPUT_TEST_EXPORT_COPY_MACRO_H

#include "InputOutput/InputOutputDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(InputOutput, InputOutputTestExportCopyMacroImpl, INPUT_OUTPUT_DEFAULT_DECLARE);
INPUT_OUTPUT_COPY_EXPORT(InputOutputTestExportCopyMacro, InputOutputTestExportCopyMacroImpl, COPY_UNSHARED);

namespace InputOutput
{
    class INPUT_OUTPUT_DEFAULT_DECLARE InputOutputTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(InputOutputTestExportCopyMacro);

    public:
        explicit InputOutputTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_INPUT_OUTPUT_TEST_EXPORT_COPY_MACRO_H