///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/26 13:44)

#include "LibraryDirectoryTesting.h"
#include "System/DynamicLink/LibraryDirectory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
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

    ResetLibraryDirectory(currentLibraryDirectory);
}

void System::LibraryDirectoryTesting::DllDirectoryAccessTest()
{
    ResetLibraryDirectory(DYNAMIC_LINK_TEXT("D:/"s));

    auto currentLibraryDirectory = GetCurrentLibraryDirectory();

    ASSERT_TRUE(0 < currentLibraryDirectory.size() && currentLibraryDirectory.size() < g_MaxPath);

    ResetLibraryDirectory(DYNAMIC_LINK_TEXT(""s));

    currentLibraryDirectory = GetCurrentLibraryDirectory();

    ASSERT_TRUE(currentLibraryDirectory.empty());
}

System::DynamicLinkString System::LibraryDirectoryTesting::GetCurrentLibraryDirectory()
{
    array<DynamicLinkCharType, g_MaxPath> directoryName{};
    const auto maxFileNameLength = GetLibraryDirectory(g_MaxPath, directoryName.data());
    DynamicLinkString currentLibraryDirectory{ directoryName.data() };

    ASSERT_EQUAL(maxFileNameLength, currentLibraryDirectory.size());

    return currentLibraryDirectory;
}

void System::LibraryDirectoryTesting::ResetLibraryDirectory(const DynamicLinkString& libraryDirectory)
{
    ASSERT_TRUE(SetLibraryDirectory(libraryDirectory.c_str()));
}
