///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:53)

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