///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:53)

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