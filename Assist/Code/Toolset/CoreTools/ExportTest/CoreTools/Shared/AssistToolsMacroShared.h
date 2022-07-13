///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:57)

#ifndef EXPORT_TEST_ASSIST_TOOLS_MACRO_SHARED_H
#define EXPORT_TEST_ASSIST_TOOLS_MACRO_SHARED_H

#include "AssistTools/AssistToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

ASSIST_TOOLS_SHARED_EXPORT_IMPL(AssistToolsMacroSharedImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE AssistToolsMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(AssistToolsMacroShared);

    public:
        explicit AssistToolsMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ASSIST_TOOLS_MACRO_SHARED_H