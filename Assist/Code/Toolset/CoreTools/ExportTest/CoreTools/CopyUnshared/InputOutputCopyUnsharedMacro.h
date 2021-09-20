///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 15:05)

#ifndef EXPORT_TEST_INPUT_OUTPUT_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_INPUT_OUTPUT_COPY_UNSHARED_MACRO_H

#include "InputOutput/InputOutputDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

INPUT_OUTPUT_COPY_UNSHARED_EXPORT_IMPL(InputOutputCopyUnsharedMacro, InputOutputCopyUnsharedMacroImpl);

namespace InputOutput
{
    class INPUT_OUTPUT_DEFAULT_DECLARE InputOutputCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(InputOutputCopyUnsharedMacro);

    public:
        explicit InputOutputCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_INPUT_OUTPUT_COPY_UNSHARED_MACRO_H