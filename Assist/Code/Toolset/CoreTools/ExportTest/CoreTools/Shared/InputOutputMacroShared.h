///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.4 (2023/03/17 14:18)

#ifndef EXPORT_TEST_INPUT_OUTPUT_MACRO_SHARED_H
#define EXPORT_TEST_INPUT_OUTPUT_MACRO_SHARED_H

#include "InputOutput/InputOutputDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

INPUT_OUTPUT_SHARED_EXPORT_IMPL(InputOutputMacroSharedImpl);

namespace InputOutput
{
    class INPUT_OUTPUT_DEFAULT_DECLARE InputOutputMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(InputOutputMacroShared);

    public:
        explicit InputOutputMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_INPUT_OUTPUT_MACRO_SHARED_H