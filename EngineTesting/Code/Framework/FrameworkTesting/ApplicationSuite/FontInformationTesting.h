///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 20:33)

#ifndef FRAMEWORK_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class FontInformationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FontInformationTesting;
        using ParentType = UnitTest;

    public:
        explicit FontInformationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest() noexcept;
    };
}

#endif  // FRAMEWORK_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H
