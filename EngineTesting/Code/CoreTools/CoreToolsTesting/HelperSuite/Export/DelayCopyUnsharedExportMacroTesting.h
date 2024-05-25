/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/13 10:40)

#ifndef CORE_TOOLS_HELPER_SUITE_DELAY_COPY_UNSHARED_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_DELAY_COPY_UNSHARED_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DelayCopyUnsharedExportMacroTesting final : public UnitTest
    {
    public:
        using ClassType = DelayCopyUnsharedExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit DelayCopyUnsharedExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto count = 10;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        template <typename T>
        void DelayCopyUnsharedExportTest();

        template <typename T>
        void CountTest(const T& lhs, const T& rhs, int lhsCount, int rhsCount);
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_DELAY_COPY_UNSHARED_EXPORT_MACRO_TESTING_H