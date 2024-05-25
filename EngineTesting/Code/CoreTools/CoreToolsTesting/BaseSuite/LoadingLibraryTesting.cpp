/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 14:42)

#include "LoadingLibraryTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "CoreTools/Base/LoadingLibrary.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

namespace CoreTools
{
    const auto kernel32Dll = SYSTEM_TEXT("Kernel32.dll"s);
}

CoreTools::LoadingLibraryTesting::LoadingLibraryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LoadingLibraryTesting)

void CoreTools::LoadingLibraryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LoadingLibraryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadingNetMessageDllTest);
    ASSERT_THROW_EXCEPTION_0(LoadingErrorDllTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetProcessAddressTest);
    ASSERT_THROW_EXCEPTION_0(GetProcessAddressErrorTest);
}

void CoreTools::LoadingLibraryTesting::LoadingNetMessageDllTest()
{
    const auto netMessageDll = SYSTEM_TEXT("netmsg.dll"s);

    LoadingLibrary library0{ netMessageDll, System::LoadLibraryType::DoNotResolveDllReferences };

    LoadingLibrary library1{ netMessageDll, System::LoadLibraryType::DoNotResolveDllReferences };

    ASSERT_EQUAL(library0.GetLoadedModule(), library1.GetLoadedModule());
    ASSERT_UNEQUAL_NULL_PTR(library0.GetLoadedModule());
}

void CoreTools::LoadingLibraryTesting::LoadingErrorDllTest()
{
    const auto errorDll = SYSTEM_TEXT("error.dll"s);

    LoadingLibrary library{ errorDll, System::LoadLibraryType::DoNotResolveDllReferences };
}

void CoreTools::LoadingLibraryTesting::GetProcessAddressTest()
{
    LoadingLibrary library{ kernel32Dll, System::LoadLibraryType::NoFlags };

    ASSERT_UNEQUAL_NULL_PTR(library.GetLoadedModule());
    ASSERT_UNEQUAL_NULL_PTR(library.GetProcessAddress("GetLastError"));
}

void CoreTools::LoadingLibraryTesting::GetProcessAddressErrorTest()
{
    LoadingLibrary library{ kernel32Dll, System::LoadLibraryType::NoFlags };

    ASSERT_UNEQUAL_NULL_PTR(library.GetLoadedModule());
    ASSERT_EQUAL_NULL_PTR(library.GetProcessAddress("GetLastErrorEx"));
}
