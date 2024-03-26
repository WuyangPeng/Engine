/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:23)

#ifndef EXPORT_TEST_EXPORT_CLASS_H
#define EXPORT_TEST_EXPORT_CLASS_H

#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

namespace ExportTest
{
    class EXPORT_TEST_DEFAULT_DECLARE ExportClass final
    {
    public:
        using ClassType = ExportClass;

    public:
        ExportClass() noexcept = default;
    };
}

#endif  // EXPORT_TEST_EXPORT_CLASS_H