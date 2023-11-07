///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:01)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LIBRARY_DIRECTORY_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LIBRARY_DIRECTORY_TESTING_H

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
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
        void DoRunUnitTest() override;
        void MainTest();

        void DllDirectoryAccessTest();
        void SetEmptyDllDirectoryTest();

        NODISCARD DynamicLinkString GetCurrentLibraryDirectory();
        void ResetLibraryDirectory(const DynamicLinkString& libraryDirectory);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LIBRARY_DIRECTORY_TESTING_H