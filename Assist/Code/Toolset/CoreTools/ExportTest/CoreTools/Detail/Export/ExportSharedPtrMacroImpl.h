///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 15:32)

#ifndef EXPORT_TEST_EXPORT_SHARED_PTR_MACRO_IMPL_H
#define EXPORT_TEST_EXPORT_SHARED_PTR_MACRO_IMPL_H

#include "CoreTools/Helper/UserMacro.h"
#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

namespace ExportTest
{
    class EXPORT_TEST_HIDDEN_DECLARE ExportSharedPtrMacroImpl final
    {
    public:
        using ClassType = ExportSharedPtrMacroImpl;

    public:
        ExportSharedPtrMacroImpl() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // EXPORT_TEST_EXPORT_SHARED_PTR_MACRO_IMPL_H