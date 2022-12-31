///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/12 23:38)

#ifndef SYSTEM_FILE_MANAGER_SUITE_FILE_TESTING_BASE_H
#define SYSTEM_FILE_MANAGER_SUITE_FILE_TESTING_BASE_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FileTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = FileTestingBase;
        using ParentType = UnitTest;

    public:
        explicit FileTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void CloseFile(WindowsHandle handle);
        void IsFileHandleValidTest(WindowsHandle handle);
        void RemoveFile(const String& fileName);

    protected:
        using BufferType = std::vector<char>;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_FILE_TESTING_BASE_H