/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 15:56)

#ifndef SYSTEM_TESTING_HELPER_SUITE_PRAGMA_WARNING_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_PRAGMA_WARNING_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief ��������ڲ�����������ͷ�ļ���
    /// ͨ������System/Helper/PragmaWarning�µ��ļ���ʵ�ֲ��ԣ�
    /// �౾���ǿղ��ԡ�
    class PragmaWarningTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PragmaWarningTesting;
        using ParentType = UnitTest;

    public:
        explicit PragmaWarningTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_PRAGMA_WARNING_TESTING_H
