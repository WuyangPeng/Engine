///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.4 (2023/03/17 14:43)

#ifndef EXPORT_TEST_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_COPY_UNSHARED_MACRO_H

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

EXPORT_SHARED_PTR(ExportTest, CopyUnsharedMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);
EXPORT_COPY_UNSHARED(ExportTest, CopyUnsharedMacro, CopyUnsharedMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);

namespace ExportTest
{
    class EXPORT_TEST_DEFAULT_DECLARE CopyUnsharedMacro final
    {
    public:
        TYPE_DECLARE(CopyUnsharedMacro);
        using PackageType = CoreTools::CopyUnsharedImpl<ClassType, ImplType>;
        using ClassShareType = PackageType::ClassShareType;
        using SharedPtr = std::shared_ptr<ImplType>;

    public:
        COPY_UNSHARED_CLONE_SELF_DECLARE;

    public:
        explicit CopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_COPY_UNSHARED_MACRO_H