///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 17:18)

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

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SCRIPT_MACRO_SHARED_H