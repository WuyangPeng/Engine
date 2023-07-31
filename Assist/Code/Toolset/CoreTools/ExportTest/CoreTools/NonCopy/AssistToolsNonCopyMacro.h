///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:58)

#ifndef EXPORT_TEST_ASSIST_TOOLS_NON_COPY_MACRO_H
#define EXPORT_TEST_ASSIST_TOOLS_NON_COPY_MACRO_H

#include "AssistTools/AssistToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

ASSIST_TOOLS_NON_COPY_EXPORT_IMPL(AssistToolsNonCopyMacroImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE AssistToolsNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(AssistToolsNonCopyMacro);

    public:
        explicit AssistToolsNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ASSIST_TOOLS_NON_COPY_MACRO_H