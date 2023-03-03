///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/02/23 16:39)

#include "LoadingLibraryTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "CoreTools/Base/LoadingLibrary.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

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
    ASSERT_NOT_THROW_EXCEPTION_0(GetProcAddressTest);
    ASSERT_THROW_EXCEPTION_0(GetProcAddressErrorTest);
}

void CoreTools::LoadingLibraryTesting::LoadingNetMessageDllTest()
{
    const auto netMessageDll = SYSTEM_TEXT("netmsg.dll"s);

    LoadingLibrary library0{ netMessageDll, System::LoadLibraryType::DontResolveDllReferences };

    LoadingLibrary library1{ netMessageDll, System::LoadLibraryType::DontResolveDllReferences };

    ASSERT_EQUAL(library0.GetLoadedModule(), library1.GetLoadedModule());
    ASSERT_UNEQUAL_NULL_PTR(library0.GetLoadedModule());
}

void CoreTools::LoadingLibraryTesting::LoadingErrorDllTest()
{
    const auto errorDll = SYSTEM_TEXT("error.dll"s);

    LoadingLibrary library{ errorDll, System::LoadLibraryType::DontResolveDllReferences };
}

void CoreTools::LoadingLibraryTesting::GetProcAddressTest()
{
    const auto kernel32Dll = SYSTEM_TEXT("Kernel32.dll"s);

    LoadingLibrary library{ kernel32Dll, System::LoadLibraryType::NoFlags };

    ASSERT_UNEQUAL_NULL_PTR(library.GetLoadedModule());
    ASSERT_UNEQUAL_NULL_PTR(library.GetProcessAddress("GetLastError"));
}

void CoreTools::LoadingLibraryTesting::GetProcAddressErrorTest()
{
    const auto kernel32Dll = SYSTEM_TEXT("Kernel32.dll"s);

    LoadingLibrary library{ kernel32Dll, System::LoadLibraryType::NoFlags };

    ASSERT_UNEQUAL_NULL_PTR(library.GetLoadedModule());
    ASSERT_EQUAL_NULL_PTR(library.GetProcessAddress("GetLastErrorEx"));
}
