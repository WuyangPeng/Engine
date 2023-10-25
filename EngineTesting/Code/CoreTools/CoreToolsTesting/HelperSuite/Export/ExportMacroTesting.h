///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 15:42)

#ifndef CORE_TOOLS_HELPER_SUITE_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ExportMacroTesting final : public UnitTest
    {
    public:
        using ClassType = ExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
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