///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:25)

#include "FileHandlePointerTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;
using namespace std::literals;

System::FileHandlePointerTesting::FileHandlePointerTesting(const OStreamShared& stream)
    : ParentType{ stream }
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

    auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents, FileHandleCreationDisposition::CreateAlways);

    ASSERT_TRUE(IsFileHandleValid(handle));

    vector<char> buffer(100, '\a');
    WindowsDWord outNumber{ 0 };
    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &outNumber));
    ASSERT_EQUAL(outNumber, buffer.size());

    ASSERT_TRUE(FlushSystemFileBuffers(handle));

    constexpr WindowsLong distanceToMove{ 10 };

    WindowsLargeInteger newFilePointer{};

    ASSERT_TRUE(SetSystemFilePointer(handle, distanceToMove, &newFilePointer, FilePointer::Begin));
    ASSERT_EQUAL(newFilePointer.QuadPart, distanceToMove);

    newFilePointer.QuadPart = -newFilePointer.QuadPart;
    ASSERT_TRUE(SetSystemFilePointer(handle, newFilePointer, &newFilePointer, FilePointer::End));
    ASSERT_EQUAL(newFilePointer.QuadPart, boost::numeric_cast<int>(buffer.size() - distanceToMove));

    ASSERT_TRUE(SetSystemFilePointer(handle, distanceToMove, &newFilePointer, FilePointer::Current));
    ASSERT_EQUAL(newFilePointer.QuadPart, boost::numeric_cast<int>(buffer.size()));

    ASSERT_TRUE(SetEndOfSystemFile(handle));

    ASSERT_TRUE(SetSystemFilePointer(handle, -distanceToMove, &newFilePointer, FilePointer::Current));
    ASSERT_EQUAL(newFilePointer.QuadPart, boost::numeric_cast<int>(buffer.size()) - distanceToMove);

    ASSERT_TRUE(CloseSystemFile(handle));
}
