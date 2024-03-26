/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/07 17:21)

#ifndef SYSTEM_TESTING_HELPER_SUITE_PRAGMA_MESSAGE_MACRO_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_PRAGMA_MESSAGE_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief ��������ڲ��Ժ�#pragma message
    /// ͨ������System/Helper/PragmaMessageMacro.h��ʵ�ֲ��ԣ�
    /// �౾���ǿղ��ԡ�
    class PragmaMessageMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PragmaMessageMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit PragmaMessageMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_PRAGMA_MESSAGE_MACRO_TESTING_H
