///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/19 22:02)

#ifndef DATABASE_GENERATE_SERVER_TESTING_DATABASE_GENERATE_SERVER_SUITE_DATABASE_GENERATE_SERVER_MESSAGE_TESTING_H
#define DATABASE_GENERATE_SERVER_TESTING_DATABASE_GENERATE_SERVER_SUITE_DATABASE_GENERATE_SERVER_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerTesting
{
    class DatabaseGenerateServerMessageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DatabaseGenerateServerMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit DatabaseGenerateServerMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // DATABASE_GENERATE_SERVER_TESTING_DATABASE_GENERATE_SERVER_SUITE_DATABASE_GENERATE_SERVER_MESSAGE_TESTING_H
