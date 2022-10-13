///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.2 (2022/09/18 14:44)

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