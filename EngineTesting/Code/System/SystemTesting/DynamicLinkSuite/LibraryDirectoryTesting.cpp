///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:08)

#include "LibraryDirectoryTesting.h"
#include "System/DynamicLink/LibraryDirectory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using namespace std::literals;

System::LibraryDirectoryTesting::LibraryDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LibraryDirectoryTesting)

void System::LibraryDirectoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LibraryDirectoryTesting::MainTest()
{
    const auto currentLibraryDirectory = GetCurrentLibraryDirectory();

    ASSERT_NOT_THROW_EXCEPTION_0(DllDirectoryAccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetEmptyDllDirectoryTest);

    ResetLibraryDirectory(currentLibraryDirectory);
}

void System::LibraryDirectoryTesting::DllDirectoryAccessTest()
{
    ResetLibraryDirectory(DYNAMIC_LINK_TEXT("D:/"s));

    const auto currentLibraryDirectory = GetCurrentLibraryDirectory();

    ASSERT_TRUE(0 < currentLibraryDirectory.size() && currentLibraryDirectory.size() < gMaxPath);

    ASSERT_EQUAL(GetLibraryDirectory(), currentLibraryDirectory);
}

void System::LibraryDirectoryTesting::SetEmptyDllDirectoryTest()
{
    ResetLibraryDirectory(DYNAMIC_LINK_TEXT(""s));

    const auto currentLibraryDirectory = GetCurrentLibraryDirectory();

    ASSERT_TRUE(currentLibraryDirectory.empty());

    ASSERT_EQUAL(GetLibraryDirectory(), currentLibraryDirectory);
}

System::DynamicLinkString System::LibraryDirectoryTesting::GetCurrentLibraryDirectory()
{
    using BufferType = std::array<DynamicLinkCharType, gMaxPath>;

    BufferType directoryName{};
    const auto maxFileNameLength = GetLibraryDirectory(gMaxPath, directoryName.data());
    DynamicLinkString currentLibraryDirectory{ directoryName.data() };

    ASSERT_EQUAL(maxFileNameLength, currentLibraryDirectory.size());

    return currentLibraryDirectory;
}

void System::LibraryDirectoryTesting::ResetLibraryDirectory(const DynamicLinkString& libraryDirectory)
{
    ASSERT_TRUE(SetLibraryDirectory(libraryDirectory.c_str()));
}
