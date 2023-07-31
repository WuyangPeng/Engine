///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:55)

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