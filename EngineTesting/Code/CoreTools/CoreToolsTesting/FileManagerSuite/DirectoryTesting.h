/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/05/04 22:41)

#ifndef CORE_TOOLS_TESTING_DIRECTORY_TESTING_H
#define CORE_TOOLS_TESTING_DIRECTORY_TESTING_H

#include "System/Windows/WindowsSystem.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DirectoryTesting final : public UnitTest
    {
    public:
        using ClassType = DirectoryTesting;
        using ParentType = UnitTest;

    public:
        explicit DirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using String = System::String;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DirectoryTest();
        void DoDirectoryTest(const String& oldDirectoryName);

        NODISCARD String GetDirectory();
    };
}

#endif  // CORE_TOOLS_TESTING_DIRECTORY_TESTING_H