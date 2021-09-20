///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 16:53)

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