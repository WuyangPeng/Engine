///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/02 14:09)

#ifndef EXPORT_TEST_ASSIST_TOOLS_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_ASSIST_TOOLS_COPY_UNSHARED_MACRO_H

#include "AssistTools/AssistToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

ASSIST_TOOLS_COPY_UNSHARED_EXPORT_IMPL(AssistToolsCopyUnsharedMacro, AssistToolsCopyUnsharedMacroImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE AssistToolsCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(AssistToolsCopyUnsharedMacro);

    public:
        explicit AssistToolsCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ASSIST_TOOLS_COPY_UNSHARED_MACRO_H