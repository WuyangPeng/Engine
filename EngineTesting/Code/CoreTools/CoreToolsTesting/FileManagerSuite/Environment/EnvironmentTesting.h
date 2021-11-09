///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/08 14:00)

#ifndef CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H
#define CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EnvironmentTesting final : public UnitTest
    {
    public:
        using ClassType = EnvironmentTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit EnvironmentTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void InsertDirectoryTest();
        void EraseDirectoryTest();
        void GetPathReadingSucceedTest();
        void GetPathWritingSucceedTest();
        void GetPathReadingAndWritingSucceedTest();
        void GetPathReadingFailureTest();
        void GetPathWritingFailureTest();
        void GetPathReadingAndWritingFailureTest();
        void ConfigurationPathTest();

        NODISCARD static String GetEnvironmentFileName();
        NODISCARD static String GetEnvironmentPathFileName();
    };
}

#endif  // CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H