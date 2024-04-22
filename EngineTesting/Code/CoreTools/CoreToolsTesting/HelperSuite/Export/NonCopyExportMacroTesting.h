/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/13 10:40)

#ifndef CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class NonCopyExportMacroTesting final : public UnitTest
    {
    public:
        using ClassType = NonCopyExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit NonCopyExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        template <typename T>
        void NonCopyExportTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_H