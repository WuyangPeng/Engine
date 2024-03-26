/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:38)

#ifndef EXPORT_TEST_EXPORT_SHARED_PTR_MACRO_IMPL_H
#define EXPORT_TEST_EXPORT_SHARED_PTR_MACRO_IMPL_H

#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

#include "CoreTools/Helper/UserMacro.h"

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