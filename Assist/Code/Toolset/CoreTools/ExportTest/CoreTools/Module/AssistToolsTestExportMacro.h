///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 0:01)

#ifndef EXPORT_TEST_ASSIST_TOOLS_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_ASSIST_TOOLS_TEST_EXPORT_MACRO_H

#include "AssistTools/AssistToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(AssistTools, AssistToolsTestExportMacroImpl, ASSIST_TOOLS_DEFAULT_DECLARE);
ASSIST_TOOLS_EXPORT(AssistToolsTestExportMacroImpl, NON_COPY);
ASSIST_TOOLS_EXPORT_UNIQUE_PTR(AssistToolsTestExportMacro);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE AssistToolsTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(AssistToolsTestExportMacro);

    public:
        explicit AssistToolsTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ASSIST_TOOLS_TEST_EXPORT_MACRO_H