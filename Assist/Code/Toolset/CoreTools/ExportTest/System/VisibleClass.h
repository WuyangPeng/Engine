///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 14:26)

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