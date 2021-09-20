///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 14:26)

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