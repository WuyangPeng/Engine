///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/18 0:03)

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