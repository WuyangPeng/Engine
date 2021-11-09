///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/07 11:09)

#ifndef CORE_TOOLS_TESTING_FILE_HANDLE_HELPER_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_HANDLE_HELPER_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FileHandleHelperTesting final : public UnitTest
    {
    public:
        using ClassType = FileHandleHelperTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit FileHandleHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LoadFromFileTest();
        void AppendToFileTest();
        void SaveIntoFileTest();

        NODISCARD static String GetFileHandleHelperName();
        NODISCARD static std::string GetFileHandleHelperContent();
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_HANDLE_HELPER_MANAGER_TESTING_H
