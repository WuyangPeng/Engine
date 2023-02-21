///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 17:17)

#ifndef EXPORT_TEST_CORE_TOOLS_MACRO_SHARED_H
#define EXPORT_TEST_CORE_TOOLS_MACRO_SHARED_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

CORE_TOOLS_SHARED_EXPORT_IMPL(CoreToolsMacroSharedImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CoreToolsMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(CoreToolsMacroShared);

    public:
        explicit CoreToolsMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_CORE_TOOLS_MACRO_SHARED_H