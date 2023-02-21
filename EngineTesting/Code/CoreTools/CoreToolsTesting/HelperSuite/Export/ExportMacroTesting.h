///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/11 15:30)

#ifndef CORE_TOOLS_HELPER_SUITE_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ExportMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ExportSharedPtrMacroTest();
        void ExportUniquePtrMacroTest() noexcept;
        void ExportSharedImplMacroSharedTest();
        void ExportNonCopyImplMacroTest();
        void ExportPerformanceUnsharedImplMacroTest();

        void ExportImplMacroTest();
        void ExportConstImplMacroTest();

        template <typename T>
        void CopyExportTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_EXPORT_MACRO_TESTING_H