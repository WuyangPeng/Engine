///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:17)

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
#include "Framework/WindowProcess/Detail/WindowMessageUnitTestSuiteStream.h"

Framework::OpenGLGlutCallBackUnitTestSuite::OpenGLGlutCallBackUnitTestSuite(int64_t delta, const std::string& suiteName)
    : ParentType{ delta }, stream{ std::make_shared<StreamType>(true) }, impl{ make_shared<ImplType>(suiteName, stream->GetStreamShared()) }, isInit{ false }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::OpenGLGlutCallBackUnitTestSuite::OpenGLGlutCallBackUnitTestSuite(OpenGLGlutCallBackUnitTestSuite&& rhs) noexcept
    : ParentType{ std::move(rhs) }, stream{ move(rhs.stream) }, impl{ move(rhs.impl) }, isInit{ rhs.isInit }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::OpenGLGlutCallBackUnitTestSuite& Framework::OpenGLGlutCallBackUnitTestSuite::operator=(OpenGLGlutCallBackUnitTestSuite&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));

    stream = move(rhs.stream);
    impl = move(rhs.impl);
    isInit = rhs.isInit;

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::OpenGLGlutCallBackUnitTestSuite::IsValid() const noexcept
{
    if (ParentType::IsValid() && stream != nullptr && impl != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool Framework::OpenGLGlutCallBackUnitTestSuite::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!isInit)
    {
        isInit = true;
        return AddSuiteOnInitialize();
    }

    return true;
}

bool Framework::OpenGLGlutCallBackUnitTestSuite::SpecialKeysDown(int key, int xCoordinate, int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    impl->KeyDownMessage(System::UnderlyingCastEnum<System::WindowsKeyCodes>(key));

    return ParentType::SpecialKeysDown(key, xCoordinate, yCoordinate);
}

bool Framework::OpenGLGlutCallBackUnitTestSuite::IdleFunction()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::IdleFunction();
}

// protected
void Framework::OpenGLGlutCallBackUnitTestSuite::DoAddSuite(const Suite& suite)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->AddSuite(suite);
}

// protected
CoreTools::OStreamShared Framework::OpenGLGlutCallBackUnitTestSuite::GetStreamShared() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return stream->GetStreamShared();
}

int Framework::OpenGLGlutCallBackUnitTestSuite::GetPassedNumber() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetPassedNumber();
}

// protected
bool Framework::OpenGLGlutCallBackUnitTestSuite::IsPrintRun() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->IsPrintRun();
}

// protected
void Framework::OpenGLGlutCallBackUnitTestSuite::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
    impl->AddTest(suiteName, suite, testName, unitTest);
}

// private
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
