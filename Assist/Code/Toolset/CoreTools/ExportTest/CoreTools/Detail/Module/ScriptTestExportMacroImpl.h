/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:39)

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
        int count;
    };
}

#endif  // EXPORT_TEST_SCRIPT_TEST_EXPORT_MACRO_IMPL_H