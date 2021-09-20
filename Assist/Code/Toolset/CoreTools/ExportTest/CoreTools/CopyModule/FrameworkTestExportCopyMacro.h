///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 14:33)

#ifndef EXPORT_TEST_FRAMEWORK_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_FRAMEWORK_TEST_EXPORT_COPY_MACRO_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

EXPORT_SHARED_PTR(Framework, FrameworkTestExportCopyMacroImpl, FRAMEWORK_DEFAULT_DECLARE);
FRAMEWORK_COPY_EXPORT(FrameworkTestExportCopyMacro, FrameworkTestExportCopyMacroImpl, DELAY_COPY_UNSHARED);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE FrameworkTestExportCopyMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(FrameworkTestExportCopyMacro);

    public:
        explicit FrameworkTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_TEST_EXPORT_COPY_MACRO_H