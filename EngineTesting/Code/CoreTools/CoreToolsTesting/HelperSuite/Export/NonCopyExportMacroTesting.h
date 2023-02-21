///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/11 23:17)

#ifndef CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class NonCopyExportMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = NonCopyExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit NonCopyExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        template <typename T>
        void NonCopyExportTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_H