/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:02)

#include "ReadWriteFileTestingBase.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ReadWriteFileTestingBase::ReadWriteFileTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      fileName{ SYSTEM_TEXT("Resource/FileTesting/FileTestingText.txt") },
      fileContent{ CoreTools::Version::GetVersion() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ReadWriteFileTestingBase)

System::String System::ReadWriteFileTestingBase::GetFileName() const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return fileName;
}

std::string System::ReadWriteFileTestingBase::GetFileContent() const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return fileContent;
}

uint64_t System::ReadWriteFileTestingBase::GetLength(WindowsHandle handle)
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    uint64_t size{ 0 };
    ASSERT_TRUE(GetFileLength(handle, size));

    return size;
}

void System::ReadWriteFileTestingBase::WriteResultTest()
{
    const auto handle = CreateSystemFile(GetFileName(), FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_NOT_THROW_EXCEPTION_1(DoWriteResultTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::ReadWriteFileTestingBase::DoWriteResultTest(WindowsHandle handle)
{
    ASSERT_TRUE(IsFileHandleValid(handle));

    const auto size = GetLength(handle);

    BufferType buffer(boost::numeric_cast<size_t>(size));

    WindowsDWord inNumber{ 0 };
    ASSERT_TRUE(ReadSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(size), &inNumber));

    ASSERT_NOT_THROW_EXCEPTION_2(ReadResultTest, inNumber, buffer);
}

void System::ReadWriteFileTestingBase::ReadResultTest(WindowsDWord inNumber, const BufferType& buffer)
{
    ASSERT_EQUAL(inNumber, fileContent.size() * 2);

    BufferType originalBuffer{ fileContent.begin(), fileContent.end() };
    originalBuffer.insert(originalBuffer.end(), fileContent.begin(), fileContent.end());

    ASSERT_EQUAL(buffer, originalBuffer);
}