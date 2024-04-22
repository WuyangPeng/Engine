/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 17:08)

#ifndef CORE_TOOLS_TESTING_I_FILE_STREAM_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_I_FILE_STREAM_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class IFileStreamManagerTesting final : public UnitTest
    {
    public:
        using ClassType = IFileStreamManagerTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit IFileStreamManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

    private:
        void IFileStreamManagerSucceedTest();
        void IFileStreamManagerBackupFileTest();
        void IFileStreamManagerDeleteBackupFileTest();
        void SeparateTest();

        static NODISCARD String GetIFileStreamFileName();
        static NODISCARD String GetIFileStreamFileContent();

    private:
        System::String backupFile;
    };
}

#endif  // CORE_TOOLS_TESTING_I_FILE_STREAM_MANAGER_TESTING_H
