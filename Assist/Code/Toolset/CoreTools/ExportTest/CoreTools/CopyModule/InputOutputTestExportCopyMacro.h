/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:25)

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