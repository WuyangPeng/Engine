///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 17:02)

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

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_INPUT_OUTPUT_MACRO_SHARED_H