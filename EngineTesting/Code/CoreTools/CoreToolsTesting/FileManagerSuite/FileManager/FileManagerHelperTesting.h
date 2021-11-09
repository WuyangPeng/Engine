///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/07 14:43)

#ifndef CORE_TOOLS_TESTING_FILE_MANAGER_HELPER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_MANAGER_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FileManagerHelperTesting final : public UnitTest
    {
    public:
        using ClassType = FileManagerHelperTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit FileManagerHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LoadFromFileTest(bool binaryFile);
        void AppendToFileTest(bool binaryFile);
        void SaveIntoFileTest(bool binaryFile);
        void IsFileExistsTest();

        NODISCARD static String GetFileManagerHelperName();
        NODISCARD static std::string GetFileManagerHelperContent();
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_MANAGER_HELPER_TESTING_H