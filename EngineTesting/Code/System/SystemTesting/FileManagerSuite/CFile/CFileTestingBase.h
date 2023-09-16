///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:11)

#ifndef SYSTEM_FILE_MANAGER_SUITE_C_FILE_TESTING_BASE_H
#define SYSTEM_FILE_MANAGER_SUITE_C_FILE_TESTING_BASE_H

#include "System/FileManager/Using/CFileUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class CFileTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = CFileTestingBase;
        using ParentType = UnitTest;

    public:
        explicit CFileTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using BufferType = std::vector<char>;

    protected:
        NODISCARD FILE* OpenFile(const CFileString& mode);
        void CloseFile(FILE* file);

        NODISCARD virtual CFileString GetFileName() const;
        NODISCARD size_t WriteFile(FILE* file) noexcept;
        NODISCARD std::string GetFileContent() const;

        void FileContentSizeEqualTest(size_t length);
        void OriginalBufferEqualTest(const BufferType& buffer);

    private:
        std::string cFileContent;
        CFileString fileName;
        BufferType originalBuffer;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_C_FILE_TESTING_BASE_H