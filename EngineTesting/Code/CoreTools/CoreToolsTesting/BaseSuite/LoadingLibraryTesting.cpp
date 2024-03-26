///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 17:05)

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
    const auto kernel32Dll = SYSTEM_TEXT("Kernel32.dll"s);

    LoadingLibrary library{ kernel32Dll, System::LoadLibraryType::NoFlags };

    ASSERT_UNEQUAL_NULL_PTR(library.GetLoadedModule());
    ASSERT_UNEQUAL_NULL_PTR(library.GetProcessAddress("GetLastError"));
}

void CoreTools::LoadingLibraryTesting::GetProcessAddressErrorTest()
{
    const auto kernel32Dll = SYSTEM_TEXT("Kernel32.dll"s);

    LoadingLibrary library{ kernel32Dll, System::LoadLibraryType::NoFlags };

    ASSERT_UNEQUAL_NULL_PTR(library.GetLoadedModule());
    ASSERT_EQUAL_NULL_PTR(library.GetProcessAddress("GetLastErrorEx"));
}
