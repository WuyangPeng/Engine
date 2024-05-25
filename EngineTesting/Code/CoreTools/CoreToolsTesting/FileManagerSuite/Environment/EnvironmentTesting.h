/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 16:43)

#ifndef CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H
#define CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H

#include "CoreTools/FileManager/Environment.h"
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
        void DoRunUnitTest() override;
        void MainTest();

        void InsertDirectoryTest();
        void EraseDirectoryTest();
        void GetPathReadingSucceedTest();
        void GetPathWritingSucceedTest();
        void GetPathReadingAndWritingSucceedTest();
        void GetPathReadingFailureTest();
        void GetPathWritingFailureTest() const;
        void GetPathReadingAndWritingFailureTest() const;

        NODISCARD static String GetEnvironmentFileName();
        NODISCARD static String GetEnvironmentPathFileName();

    private:
        Environment environment;
    };
}

#endif  // CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H