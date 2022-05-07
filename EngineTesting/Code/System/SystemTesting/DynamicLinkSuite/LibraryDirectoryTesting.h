///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/26 13:44)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LIBRARY_DIRECTORY_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LIBRARY_DIRECTORY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class LibraryDirectoryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LibraryDirectoryTesting;
        using ParentType = UnitTest;

    public:
        explicit LibraryDirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DllDirectoryAccessTest();

        NODISCARD DynamicLinkString GetCurrentLibraryDirectory();       
        void ResetLibraryDirectory(const DynamicLinkString& libraryDirectory);
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LIBRARY_DIRECTORY_TESTING_H