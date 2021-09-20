///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:52)

#ifndef EXPORT_TEST_COPY_UNSHARED_USE_CLONE_MACRO_H
#define EXPORT_TEST_COPY_UNSHARED_USE_CLONE_MACRO_H

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

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