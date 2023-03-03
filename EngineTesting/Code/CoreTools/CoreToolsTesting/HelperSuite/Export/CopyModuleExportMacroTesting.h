///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/11 0:01)

#ifndef CORE_TOOLS_HELPER_SUITE_COPY_MODULE_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_COPY_MODULE_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CopyModuleExportMacroTesting final : public UnitTest
    {
    public:
        using ClassType = CopyModuleExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit CopyModuleExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        template <typename T>
        void CopyModuleExportTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_COPY_MODULE_EXPORT_MACRO_TESTING_H