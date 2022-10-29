///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/16 21:45)

#ifndef EXPORT_TEST_NO_EXPORT_CLASS_H
#define EXPORT_TEST_NO_EXPORT_CLASS_H

#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

namespace ExportTest
{
    class EXPORT_TEST_HIDDEN_DECLARE NoExportClass final
    {
    public:
        using ClassType = NoExportClass;

    public:
        NoExportClass() noexcept;
    };
}

#endif  // EXPORT_TEST_NO_EXPORT_CLASS_H