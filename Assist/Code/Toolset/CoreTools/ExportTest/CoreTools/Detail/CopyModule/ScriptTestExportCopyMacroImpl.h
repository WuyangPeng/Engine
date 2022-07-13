///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/02 22:01)

#ifndef EXPORT_TEST_SCRIPT_TEST_EXPORT_COPY_MACRO_IMPL_H
#define EXPORT_TEST_SCRIPT_TEST_EXPORT_COPY_MACRO_IMPL_H

#include "Script/ScriptDll.h"

namespace Script
{
    class SCRIPT_HIDDEN_DECLARE ScriptTestExportCopyMacroImpl final
    {
    public:
        using ClassType = ScriptTestExportCopyMacroImpl;

    public:
        explicit ScriptTestExportCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int mCount;
    };
}

#endif  // EXPORT_TEST_SCRIPT_TEST_EXPORT_COPY_MACRO_IMPL_H