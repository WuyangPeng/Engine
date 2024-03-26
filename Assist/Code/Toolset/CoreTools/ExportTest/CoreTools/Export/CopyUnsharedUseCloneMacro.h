/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:46)

#ifndef EXPORT_TEST_COPY_UNSHARED_USE_CLONE_MACRO_H
#define EXPORT_TEST_COPY_UNSHARED_USE_CLONE_MACRO_H

#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(ExportTest, CopyUnsharedUseCloneMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);
EXPORT_COPY_UNSHARED(ExportTest, CopyUnsharedUseCloneMacro, CopyUnsharedUseCloneMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);

namespace ExportTest
{
    class EXPORT_TEST_DEFAULT_DECLARE CopyUnsharedUseCloneMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(CopyUnsharedUseCloneMacro);

    public:
        explicit CopyUnsharedUseCloneMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_COPY_UNSHARED_USE_CLONE_MACRO_H