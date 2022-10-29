///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 0:07)

#ifndef EXPORT_TEST_SCRIPT_MACRO_SHARED_H
#define EXPORT_TEST_SCRIPT_MACRO_SHARED_H

#include "Script/ScriptDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

SCRIPT_SHARED_EXPORT_IMPL(ScriptMacroSharedImpl);

namespace Script
{
    class SCRIPT_DEFAULT_DECLARE ScriptMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(ScriptMacroShared);

    public:
        explicit ScriptMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SCRIPT_MACRO_SHARED_H