///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 20:27)

#ifndef CORE_TOOLS_TESTING_IF_STREAM_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_IF_STREAM_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class IFStreamManagerTesting final : public UnitTest
    {
    public:
        using ClassType = IFStreamManagerTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit IFStreamManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

    private:
        void IFStreamManagerSucceedTest();
        void IFStreamManagerBackupFileTest();
        void IFStreamManagerDeleteBackupFileTest();
        static NODISCARD String GetIFStreamFileName();
        static NODISCARD String GetIFStreamFileContent();

    private:
        System::String backupFile;
    };
}

#endif  // CORE_TOOLS_TESTING_IF_STREAM_MANAGER_TESTING_H
