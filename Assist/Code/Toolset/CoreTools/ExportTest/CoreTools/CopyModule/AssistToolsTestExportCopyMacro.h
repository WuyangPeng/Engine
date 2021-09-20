///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 14:32)

#ifndef EXPORT_TEST_ASSIST_TOOLS_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_ASSIST_TOOLS_TEST_EXPORT_COPY_MACRO_H

#include "AssistTools/AssistToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(AssistTools, AssistToolsTestExportCopyMacroImpl, ASSIST_TOOLS_DEFAULT_DECLARE);
ASSIST_TOOLS_COPY_EXPORT(AssistToolsTestExportCopyMacro, AssistToolsTestExportCopyMacroImpl, COPY_UNSHARED);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE AssistToolsTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(AssistToolsTestExportCopyMacro);

    public:
        explicit AssistToolsTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ASSIST_TOOLS_TEST_EXPORT_COPY_MACRO_H