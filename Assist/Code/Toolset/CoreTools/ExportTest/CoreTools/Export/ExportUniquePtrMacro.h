/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:48)

#ifndef EXPORT_TEST_EXPORT_UNIQUE_PTR_MACRO_H
#define EXPORT_TEST_EXPORT_UNIQUE_PTR_MACRO_H

#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

#include "CoreTools/Helper/ExportMacro.h"

EXPORT_UNIQUE_PTR(ExportTest, ExportUniquePtrMacro, EXPORT_TEST_DEFAULT_DECLARE);

namespace ExportTest
{
    class EXPORT_TEST_DEFAULT_DECLARE ExportUniquePtrMacro final
    {
    public:
        using ClassType = ExportUniquePtrMacro;

    public:
        ExportUniquePtrMacro() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // EXPORT_TEST_TEST_EXPORT_MACRO_H