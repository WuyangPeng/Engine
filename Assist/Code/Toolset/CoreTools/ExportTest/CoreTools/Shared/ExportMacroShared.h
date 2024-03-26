/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:55)

#ifndef EXPORT_TEST_EXPORT_MACRO_SHARED_H
#define EXPORT_TEST_EXPORT_MACRO_SHARED_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

SHARED_EXPORT_IMPL(ExportMacroSharedImpl, CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ExportMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(ExportMacroShared);

    public:
        explicit ExportMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_MACRO_SHARED_H