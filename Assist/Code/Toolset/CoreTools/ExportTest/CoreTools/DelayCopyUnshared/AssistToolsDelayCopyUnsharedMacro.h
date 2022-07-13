///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:07)

#ifndef EXPORT_TEST_ASSIST_TOOLS_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_ASSIST_TOOLS_DELAY_COPY_UNSHARED_MACRO_H

#include "AssistTools/AssistToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

ASSIST_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(AssistToolsDelayCopyUnsharedMacro, AssistToolsDelayCopyUnsharedMacroImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE AssistToolsDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(AssistToolsDelayCopyUnsharedMacro);

    public:
        explicit AssistToolsDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ASSIST_TOOLS_DELAY_COPY_UNSHARED_MACRO_H