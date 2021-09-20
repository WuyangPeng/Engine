// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:54)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuite.h"
#include "Detail/WindowMessageUnitTestSuiteImpl.h"
#include "Detail/WindowMessageUnitTestSuiteStream.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"
using std::string;
using std::make_shared;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)
Framework::WindowMessageUnitTestSuite
	::WindowMessageUnitTestSuite(int64_t delta,const string& suiteName)
	:ParentType{ delta }, m_Stream{ make_shared<StreamType>(true) },  impl{  suiteName, m_Stream->GetStreamShared()  }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowMessageUnitTestSuite
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_Stream != nullptr  )
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

System::WindowsLResult Framework::WindowMessageUnitTestSuite
	::CreateMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	;

	if (GetHwnd() == nullptr)
		return AddSuiteOnCreateMessage(hwnd, wParam, lParam);
	else
		return ParentType::CreateMessage(hwnd, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageUnitTestSuite
	::KeyDownMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	;

	auto windowsKeyCodes = boost::numeric_cast<int>(wParam);

	impl->KeyDownMessage(System::UnderlyingCastEnum<System::WindowsKeyCodes>(windowsKeyCodes));

	return ParentType::KeyDownMessage(hwnd, wParam, lParam);
}

void Framework::WindowMessageUnitTestSuite
	::Display(HWnd hwnd, int64_t timeDelta)
{
	;

	return ParentType::Display(hwnd, timeDelta);
} 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowMessageUnitTestSuite, IsPrintRun, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowMessageUnitTestSuite, GetPassedNumber, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, WindowMessageUnitTestSuite, AddSuite, Suite, void)

// protected
CoreTools::OStreamShared Framework::WindowMessageUnitTestSuite
	::GetStreamShared() noexcept
{
	;

	return m_Stream->GetStreamShared();
}

// protected
void Framework::WindowMessageUnitTestSuite
	::AddTest(const string& suiteName, Suite& suite, const string& testName, const UnitTestPtr& unitTest)
{
	;

	impl->AddTest(suiteName, suite, testName, unitTest);
}

// private
System::WindowsLResult Framework::WindowMessageUnitTestSuite
	::AddSuiteOnCreateMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	const auto result = ParentType::CreateMessage(hwnd, wParam, lParam);

	InitSuite();

	impl->RunUnitTestOnMessage(); 

	return result;
}

// protected
CoreTools::Suite Framework::WindowMessageUnitTestSuite
	::GenerateSuite(const string& name)
{
	return Suite{ name, GetStreamShared(), IsPrintRun() };
}

