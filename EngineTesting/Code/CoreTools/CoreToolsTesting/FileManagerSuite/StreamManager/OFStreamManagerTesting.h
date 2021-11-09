///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/06 14:33)

#ifndef CORE_TOOLS_TESTING_OFSTREAM_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_OFSTREAM_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class OFStreamManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OFStreamManagerTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit OFStreamManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OFStreamManagerMessageTest();
        void OFStreamManagerSizeTest();

    private:
        static NODISCARD String GetOFStreamFileName();
        static NODISCARD String GetOFStreamFileContent();
    };
}

#endif  // CORE_TOOLS_TESTING_OFSTREAM_MANAGER_TESTING_H
