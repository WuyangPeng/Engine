///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:19)

#include "FileHandlePointerTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::FileHandlePointerTesting::FileHandlePointerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      buffer(100, '\a'),
      distanceToMove{ 10 }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileHandlePointerTesting)

void System::FileHandlePointerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FileHandlePointerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FilePointerTest);
}

void System::FileHandlePointerTesting::FilePointerTest()
{
    const auto fileName = SYSTEM_TEXT("Resource/FileTesting/FilePointerText.txt"s);

    const auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents, FileHandleCreationDisposition::CreateAlways);

    ASSERT_NOT_THROW_EXCEPTION_1(DoFilePointerTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::FileHandlePointerTesting::DoFilePointerTest(WindowsHandle handle)
{
    ASSERT_TRUE(IsFileHandleValid(handle));

    ASSERT_NOT_THROW_EXCEPTION_1(FlushSystemFileBuffersTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(SetFilePointerTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(SetEndOfFileTest, handle);
}

void System::FileHandlePointerTesting::SetFilePointerTest(WindowsHandle handle)
{
    WindowsLargeInteger newFilePointer{};

    ASSERT_TRUE(SetSystemFilePointer(handle, distanceToMove, &newFilePointer, FilePointer::Begin));
    ASSERT_EQUAL(newFilePointer.QuadPart, distanceToMove);

    newFilePointer.QuadPart = -newFilePointer.QuadPart;
    ASSERT_TRUE(SetSystemFilePointer(handle, newFilePointer, &newFilePointer, FilePointer::End));
    ASSERT_EQUAL(newFilePointer.QuadPart, boost::numeric_cast<int>(buffer.size() - distanceToMove));

    ASSERT_TRUE(SetSystemFilePointer(handle, distanceToMove, &newFilePointer, FilePointer::Current));
    ASSERT_EQUAL(newFilePointer.QuadPart, boost::numeric_cast<int>(buffer.size()));
}

void System::FileHandlePointerTesting::FlushSystemFileBuffersTest(WindowsHandle handle)
{
    WindowsDWord outNumber{ 0 };
    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &outNumber));
    ASSERT_EQUAL(outNumber, buffer.size());

    ASSERT_TRUE(FlushSystemFileBuffers(handle));
}

void System::FileHandlePointerTesting::SetEndOfFileTest(WindowsHandle handle)
{
    ASSERT_TRUE(SetEndOfSystemFile(handle));

    WindowsLargeInteger newFilePointer{};
    ASSERT_TRUE(SetSystemFilePointer(handle, -distanceToMove, &newFilePointer, FilePointer::Current));
    ASSERT_EQUAL(newFilePointer.QuadPart, boost::numeric_cast<int>(buffer.size()) - distanceToMove);
}
