/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:29)

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