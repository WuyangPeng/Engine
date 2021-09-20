///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++17
///	ÒýÇæ²âÊÔ°æ±¾£º0.7.1.2 (2021/04/23 14:37)

#include "ViewOfFileTesting.h"
#include "System/MemoryTools/Flags/ViewOfFileFlags.h"
#include "System/MemoryTools/Flags/VirtualToolsFlags.h"
#include "System/MemoryTools/ViewOfFile.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::ViewOfFileTesting::ViewOfFileTesting(const OStreamShared& stream)
    : ParentType{ stream },
      fileMapDesiredAccessFlags{ FileMapDesiredAccess::Write,
                                 FileMapDesiredAccess::Read,
                                 FileMapDesiredAccess::AllAccess,
                                 FileMapDesiredAccess::Execute,
                                 FileMapDesiredAccess::Copy }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ViewOfFileTesting)

void System::ViewOfFileTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ViewOfFileTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ViewOfFileTest);
}

void System::ViewOfFileTesting::ViewOfFileTest()
{
    for (auto fileMapDesiredAccess : fileMapDesiredAccessFlags)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoViewOfFileTest, fileMapDesiredAccess);
        ASSERT_NOT_THROW_EXCEPTION_1(DoViewOfFileUseBaseAddressTest, fileMapDesiredAccess);
    }
}

void System::ViewOfFileTesting::DoViewOfFileTest(FileMapDesiredAccess fileMapDesiredAccess)
{
    constexpr WindowsDWord maximumSizeLow{ 0xFFFF };
    const auto fileMapName = L"ViewOfFileTestingFileMap"s;

    auto loopTestFileName = fileMapName + System::ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    auto fileMappingHandle = CreateSystemFileMapping(g_InvalidHandleValue, MemoryProtect::ReadWrite, FileMapProtection::Default, 0, maximumSizeLow, loopTestFileName.c_str(), nullptr);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(fileMappingHandle, "CreateSystemFileMapping Ê§°Ü");

    auto buffer = MapSystemViewOfFile(fileMappingHandle, fileMapDesiredAccess, 0, 0, 0);
    ASSERT_UNEQUAL_NULL_PTR(buffer);

    ASSERT_TRUE(FlushSystemViewOfFile(buffer, 0));
    ASSERT_TRUE(UnmapSystemViewOfFile(buffer));
    ASSERT_TRUE(CloseFileMapping(fileMappingHandle));
}

void System::ViewOfFileTesting::DoViewOfFileUseBaseAddressTest(FileMapDesiredAccess fileMapDesiredAccess)
{
    constexpr WindowsDWord maximumSizeLow{ 0xFFFF };
    const auto fileMapName = L"ViewOfFileTestingFileMap"s;

    auto loopTestFileName = fileMapName + System::ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    auto fileMappingHandle = CreateSystemFileMapping(g_InvalidHandleValue, MemoryProtect::ReadWrite, FileMapProtection::Default, 0, maximumSizeLow, loopTestFileName.c_str(), nullptr);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(fileMappingHandle, "CreateSystemFileMapping Ê§°Ü");

    auto buffer = MapSystemViewOfFile(fileMappingHandle, fileMapDesiredAccess, 0, 0, 0, nullptr);
    ASSERT_UNEQUAL_NULL_PTR(buffer);

    ASSERT_TRUE(FlushSystemViewOfFile(buffer, 0));
    ASSERT_TRUE(UnmapSystemViewOfFile(buffer));
    ASSERT_TRUE(CloseFileMapping(fileMappingHandle));
}