///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/08 21:16)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LIBRARY_DIRECTORY_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LIBRARY_DIRECTORY_TESTING_H

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
        void SetEmptyDllDirectoryTest();

        NODISCARD DynamicLinkString GetCurrentLibraryDirectory();
        void ResetLibraryDirectory(const DynamicLinkString& libraryDirectory);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LIBRARY_DIRECTORY_TESTING_H