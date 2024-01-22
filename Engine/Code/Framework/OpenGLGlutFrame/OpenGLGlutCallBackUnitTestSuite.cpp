/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:53)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutCallBackUnitTestSuite.h"
#include "Detail/OpenGLGlutCallBackUnitTestSuiteImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"
#include "CoreTools/UnitTestSuite/Suite.h"

Framework::OpenGLGlutCallBackUnitTestSuite::OpenGLGlutCallBackUnitTestSuite(int64_t delta, const std::string& suiteName)
    : ParentType{ delta }, impl{ suiteName }, isInit{ false }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutCallBackUnitTestSuite)

bool Framework::OpenGLGlutCallBackUnitTestSuite::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (!isInit)
    {
        isInit = true;
        return AddSuiteOnInitialize();
    }

    return true;
}

bool Framework::OpenGLGlutCallBackUnitTestSuite::SpecialKeysDown(int key, int xCoordinate, int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    impl->KeyDownMessage(System::UnderlyingCastEnum<System::WindowsKeyCodes>(key));

    return ParentType::SpecialKeysDown(key, xCoordinate, yCoordinate);
}

bool Framework::OpenGLGlutCallBackUnitTestSuite::IdleFunction()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::IdleFunction();
}

void Framework::OpenGLGlutCallBackUnitTestSuite::DoAddSuite(const Suite& suite)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->AddSuite(suite);
}

CoreTools::OStreamShared Framework::OpenGLGlutCallBackUnitTestSuite::GetStreamShared() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->GetStreamShared();
}

int Framework::OpenGLGlutCallBackUnitTestSuite::GetPassedNumber() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetPassedNumber();
}

bool Framework::OpenGLGlutCallBackUnitTestSuite::IsPrintRun() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsPrintRun();
}

void Framework::OpenGLGlutCallBackUnitTestSuite::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
    impl->AddTest(suiteName, suite, testName, unitTest);
}

bool Framework::OpenGLGlutCallBackUnitTestSuite::AddSuiteOnInitialize()
{
    const auto result = ParentType::Initialize();

    AddSuite();

    impl->RunUnitTest();
    impl->PrintReport();

    return result;
}

Framework::OpenGLGlutCallBackUnitTestSuite::Suite Framework::OpenGLGlutCallBackUnitTestSuite::GenerateSuite(const std::string& name)
{
    return Suite{ name, GetStreamShared(), IsPrintRun() };
}
