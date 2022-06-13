///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:57)

#ifndef CORE_TOOLS_TESTING_IFSTREAM_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_IFSTREAM_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class IFStreamManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = IFStreamManagerTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit IFStreamManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        void IFStreamManagerSucceedTest();
        void IFStreamManagerBackupFileTest();
        void IFStreamManagerDeleteBackupFileTest();

    private:
        static NODISCARD String GetIFStreamFileName();
        static NODISCARD String GetIFStreamFileContent();

        System::String backupFile;
    };
}

#endif  // CORE_TOOLS_TESTING_IFSTREAM_MANAGER_TESTING_H
