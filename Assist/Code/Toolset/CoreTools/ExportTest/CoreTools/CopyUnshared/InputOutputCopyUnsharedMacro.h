///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 15:31)

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

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_INPUT_OUTPUT_COPY_UNSHARED_MACRO_H