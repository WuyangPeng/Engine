///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/30 14:54)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_STRTOK_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_STRTOK_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class StrtokTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = StrtokTesting;
        using ParentType = UnitTest;

    public:
        explicit StrtokTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void StrtokTest();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_STRTOK_TESTING_H