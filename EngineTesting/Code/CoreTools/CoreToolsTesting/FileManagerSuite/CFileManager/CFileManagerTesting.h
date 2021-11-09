///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/06 13:49)

#ifndef CORE_TOOLS_TESTING_C_FILE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_C_FILE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CFileManagerTesting final : public UnitTest
    {
    public:
        using ClassType = CFileManagerTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit CFileManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CFileManagerHelperTest();

        void LoadFromFileTest(bool binaryFile);
        void LoadFromFileUseEnvironmentTest(bool binaryFile);
        void AppendToFileTest(bool binaryFile);
        void SaveIntoFileTest(bool binaryFile);

        NODISCARD static String GetDirectory();
        NODISCARD static String GetFileName();
        NODISCARD static String GetFileManagerHelperFileName();
        NODISCARD static std::string GetFileManagerContent();
    };
}

#endif  // CORE_TOOLS_TESTING_C_FILE_MANAGER_TESTING_H