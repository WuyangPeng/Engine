// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 15:59)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutCallBackUnitTestSuite.h"
#include "Detail/OpenGLGlutCallBackUnitTestSuiteImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h" 
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowProcess/Detail/WindowMessageUnitTestSuiteStream.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"
using std::move;
using std::string; 
using std::make_shared;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)
Framework::OpenGLGlutCallBackUnitTestSuite
	::OpenGLGlutCallBackUnitTestSuite(int64_t delta, const string& suiteName)
	:ParentType{ delta }, m_Stream{ make_shared<StreamType>(true) }, m_Impl{ make_shared<ImplType>(suiteName, m_Stream->GetStreamShared()) }, m_IsInit{ false }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
} 
#include STSTEM_WARNING_POP

Framework::OpenGLGlutCallBackUnitTestSuite
	::OpenGLGlutCallBackUnitTestSuite(OpenGLGlutCallBackUnitTestSuite&& rhs) noexcept
	:ParentType{ move(rhs) }, m_Stream{ move(rhs.m_Stream) }, m_Impl{ move(rhs.m_Impl) }, m_IsInit{ rhs.m_IsInit }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::OpenGLGlutCallBackUnitTestSuite& Framework::OpenGLGlutCallBackUnitTestSuite
	::operator=(OpenGLGlutCallBackUnitTestSuite&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::operator=(move(rhs));

	m_Stream = move(rhs.m_Stream);
	m_Impl = move(rhs.m_Impl);
	m_IsInit = rhs.m_IsInit;

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::OpenGLGlutCallBackUnitTestSuite
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_Stream != nullptr && m_Impl != nullptr)
		return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT

bool Framework::OpenGLGlutCallBackUnitTestSuite
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_1; 

	if (!m_IsInit)
	{
		m_IsInit = true;
		return AddSuiteOnInitialize();
	}

	return true;
}

bool Framework::OpenGLGlutCallBackUnitTestSuite
	::SpecialKeysDown(int key, int xCoordinate, int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;	  

	m_Impl->KeyDownMessage(System::UnderlyingCastEnum<System::WindowsKeyCodes>(key));

	return ParentType::SpecialKeysDown(key, xCoordinate, yCoordinate);
}

bool Framework::OpenGLGlutCallBackUnitTestSuite
	::IdleFunction()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return ParentType::IdleFunction();
}

// protected
void Framework::OpenGLGlutCallBackUnitTestSuite
	::DoAddSuite(const Suite& suite)
{
	FRAMEWORK_CLASS_IS_VALID_1; 

	return m_Impl->AddSuite(suite);
}

// protected
CoreTools::OStreamShared Framework::OpenGLGlutCallBackUnitTestSuite
	::GetStreamShared() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return m_Stream->GetStreamShared();
}

int Framework::OpenGLGlutCallBackUnitTestSuite
	::GetPassedNumber() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1; 

	return m_Impl->GetPassedNumber();
}

// protected
bool  Framework::OpenGLGlutCallBackUnitTestSuite
	::IsPrintRun() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->IsPrintRun();
}

// protected
void Framework::OpenGLGlutCallBackUnitTestSuite
	::AddTest(const string& suiteName, Suite& suite, const string& testName, const UnitTestSharedPtr& unitTest)
{
	m_Impl->AddTest(suiteName, suite, testName, unitTest);
}

// private
bool Framework::OpenGLGlutCallBackUnitTestSuite
	::AddSuiteOnInitialize()
{
	const auto result = ParentType::Initialize();

	AddSuite();

	m_Impl->RunUnitTest();
	m_Impl->PrintReport();

	return result;
}
