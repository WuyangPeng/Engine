///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:53)

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
        ExportClass() noexcept;
    };
}

#endif  // EXPORT_TEST_EXPORT_CLASS_H