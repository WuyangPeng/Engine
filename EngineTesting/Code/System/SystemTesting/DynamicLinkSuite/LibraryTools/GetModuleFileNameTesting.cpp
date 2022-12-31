///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/09 13:55)

#include "GetModuleFileNameTesting.h"
#include "System/DynamicLink/LibraryTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetModuleFileNameTesting::GetModuleFileNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetModuleFileNameTesting)

void System::GetModuleFileNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetModuleFileNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetModuleFileNameSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetModuleFileNameFailureTest);
}

void System::GetModuleFileNameTesting::GetModuleFileNameSucceedTest()
{
    const auto libraryModule = GetDynamicLibrary();

    ASSERT_NOT_THROW_EXCEPTION_1(DoGetModuleFileNameSucceedTest, libraryModule);

    ASSERT_NOT_THROW_EXCEPTION_1(Destroy, libraryModule);
}

void System::GetModuleFileNameTesting::DoGetModuleFileNameSucceedTest(const System::DynamicLinkModule libraryModule)
{
    const auto dllModuleFileName = GetDynamicLinkFileNameTest(libraryModule);

    ASSERT_UNEQUAL(dllModuleFileName.find(GetResource()), DynamicLinkString::npos);
    ASSERT_UNEQUAL(dllModuleFileName.find(GetResourcesLibrary()), DynamicLinkString::npos);
}

System::DynamicLinkString System::GetModuleFileNameTesting::GetDynamicLinkFileNameTest(System::DynamicLinkModule libraryModule)
{
    BufferType moduleFileName{};
    const auto maxFileNameLength = GetDynamicLinkFileName(libraryModule, moduleFileName.data(), gMaxPath);

    DynamicLinkString dllModuleFileName{ moduleFileName.data() };

    ASSERT_NOT_THROW_EXCEPTION_3(DllModuleFileNameTest, maxFileNameLength, libraryModule, dllModuleFileName);

    return dllModuleFileName;
}

void System::GetModuleFileNameTesting::DllModuleFileNameTest(WindowsDWord maxFileNameLength, DynamicLinkModule libraryModule, const DynamicLinkString& dllModuleFileName)
{
    ASSERT_TRUE(0 < maxFileNameLength && maxFileNameLength < gMaxPath);
    ASSERT_EQUAL(dllModuleFileName.size(), maxFileNameLength);

    ASSERT_EQUAL(dllModuleFileName, GetDynamicLinkFileName(libraryModule));
}

void System::GetModuleFileNameTesting::GetModuleFileNameFailureTest()
{
    const auto libraryModule = GetDynamicLibrary();
    ASSERT_NOT_THROW_EXCEPTION_1(Destroy, libraryModule);

    BufferType moduleFileName{};
    const auto maxFileNameLength = GetDynamicLinkFileName(libraryModule, moduleFileName.data(), gMaxPath);

    ASSERT_NOT_THROW_EXCEPTION_3(DllModuleFileNameFailureTest, maxFileNameLength, libraryModule, moduleFileName);
}

void System::GetModuleFileNameTesting::DllModuleFileNameFailureTest(WindowsDWord maxFileNameLength, DynamicLinkModule libraryModule, const BufferType& moduleFileName)
{
    ASSERT_EQUAL(0u, maxFileNameLength);

    for (auto value : moduleFileName)
    {
        ASSERT_EQUAL(value, nullDynamicLinkChar);
    }

    ASSERT_TRUE(GetDynamicLinkFileName(libraryModule).empty());
}
