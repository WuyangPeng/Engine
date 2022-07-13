///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:58)

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