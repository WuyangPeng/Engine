///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:02)

#ifndef EXPORT_TEST_FRAMEWORK_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_FRAMEWORK_TEST_EXPORT_MACRO_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(Framework, FrameworkTestExportMacroImpl, FRAMEWORK_DEFAULT_DECLARE);
FRAMEWORK_EXPORT(FrameworkTestExportMacroImpl, NON_COPY);
FRAMEWORK_EXPORT_UNIQUE_PTR(FrameworkTestExportMacro);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE FrameworkTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(FrameworkTestExportMacro);

    public:
        explicit FrameworkTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_TEST_EXPORT_MACRO_H