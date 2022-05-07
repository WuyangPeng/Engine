///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/14 17:44)

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
        void ExportCopyUnsharedImplMacroTest();
        void ExportDelayCopyUnsharedImplMacroTest();

        void ExportImplMacroTest();
        void ExportCopyImplMacroTest();
        void ExportConstImplMacroTest();
        void CopyUnsharedMacroTest();
        void CopyUnsharedUseCloneMacroTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_EXPORT_MACRO_TESTING_H