///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:51)

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