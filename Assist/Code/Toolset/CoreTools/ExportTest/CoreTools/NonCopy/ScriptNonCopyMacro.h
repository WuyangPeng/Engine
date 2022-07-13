///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/02 14:02)

#ifndef EXPORT_TEST_SCRIPT_NON_COPY_MACRO_H
#define EXPORT_TEST_SCRIPT_NON_COPY_MACRO_H

#include "Script/ScriptDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

SCRIPT_NON_COPY_EXPORT_IMPL(ScriptNonCopyMacroImpl);

namespace Script
{
    class SCRIPT_DEFAULT_DECLARE ScriptNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ScriptNonCopyMacro);

    public:
        explicit ScriptNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SCRIPT_NON_COPY_MACRO_H