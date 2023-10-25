///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 15:42)

#ifndef CORE_TOOLS_HELPER_SUITE_MODULE_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MODULE_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ModuleExportMacroTesting final : public UnitTest
    {
    public:
        using ClassType = ModuleExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ModuleExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        template <typename T>
        void ModuleExportTest();

        void DatabaseExportTest();
        void ScriptExportTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MODULE_EXPORT_MACRO_TESTING_H