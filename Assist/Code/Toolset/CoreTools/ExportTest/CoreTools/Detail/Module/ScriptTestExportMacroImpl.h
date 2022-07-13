///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 22:20)

#ifndef EXPORT_TEST_SCRIPT_TEST_EXPORT_MACRO_IMPL_H
#define EXPORT_TEST_SCRIPT_TEST_EXPORT_MACRO_IMPL_H

#include "Script/ScriptDll.h"

namespace Script
{
    class SCRIPT_HIDDEN_DECLARE ScriptTestExportMacroImpl final
    {
    public:
        using ClassType = ScriptTestExportMacroImpl;

    public:
        explicit ScriptTestExportMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        int mCount;
    };
}

#endif  // EXPORT_TEST_SCRIPT_TEST_EXPORT_MACRO_IMPL_H