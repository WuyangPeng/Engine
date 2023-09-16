///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:15)

#ifndef SYSTEM_FILE_MANAGER_SUITE_READ_WRITE_FILE_TESTING_BASE_H
#define SYSTEM_FILE_MANAGER_SUITE_READ_WRITE_FILE_TESTING_BASE_H

#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"

namespace System
{
    class ReadWriteFileTestingBase : public FileTestingBase
    {
    public:
        using ClassType = ReadWriteFileTestingBase;
        using ParentType = FileTestingBase;

    public:
        explicit ReadWriteFileTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD String GetFileName() const;
        NODISCARD std::string GetFileContent() const;
        NODISCARD uint64_t GetLength(WindowsHandle handle);

        void WriteResultTest();
        void DoWriteResultTest(WindowsHandle handle);
        virtual void ReadResultTest(WindowsDWord inNumber, const BufferType& buffer);

    private:
        String fileName;
        std::string fileContent;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_READ_WRITE_FILE_TESTING_BASE_H