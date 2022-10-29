///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 0:01)

#ifndef EXPORT_TEST_INPUT_OUTPUT_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_INPUT_OUTPUT_TEST_EXPORT_MACRO_H

#include "InputOutput/InputOutputDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(InputOutput, InputOutputTestExportMacroImpl, INPUT_OUTPUT_DEFAULT_DECLARE);
INPUT_OUTPUT_EXPORT(InputOutputTestExportMacroImpl, NON_COPY);
INPUT_OUTPUT_EXPORT_UNIQUE_PTR(InputOutputTestExportMacro);

namespace InputOutput
{
    class INPUT_OUTPUT_DEFAULT_DECLARE InputOutputTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(InputOutputTestExportMacro);

    public:
        explicit InputOutputTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_INPUT_OUTPUT_TEST_EXPORT_MACRO_H