///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 17:25)

#ifndef EXPORT_TEST_VISIBLE_SYMBOL_H
#define EXPORT_TEST_VISIBLE_SYMBOL_H

#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

namespace ExportTest
{
    class EXPORT_TEST_VISIBLE VisibleClass final
    {
    public:
        using ClassType = VisibleClass;

    public:
        VisibleClass() noexcept = default;
    };
}

#endif  // EXPORT_TEST_VISIBLE_SYMBOL_H