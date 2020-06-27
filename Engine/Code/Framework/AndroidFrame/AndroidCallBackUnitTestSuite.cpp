// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 16:42)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackUnitTestSuite.h"
#include "Detail/AndroidCallBackUnitTestSuiteImpl.h"
#include "Detail/AndroidCallBackUnitTestSuiteImpl.h"
#include "System/Android/AndroidInputKeyEvent.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowProcess/Detail/WindowMessageUnitTestSuiteStream.h"
 
using std::move;
using std::string;
using std::make_shared;

Framework::AndroidCallBackUnitTestSuite
	::AndroidCallBackUnitTestSuite(int64_t delta, const string& suiteName)
	:ParentType{ delta }, m_StreamType{ make_shared<StreamType>(true) },
	 m_Impl{ make_shared<ImplType>(suiteName, m_StreamType->GetStreamShared()) }, m_IsInit{ false }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::AndroidCallBackUnitTestSuite
	::AndroidCallBackUnitTestSuite(AndroidCallBackUnitTestSuite&& rhs) noexcept
	:ParentType{ move(rhs) }, m_StreamType{ move(rhs.m_StreamType) },m_Impl{ move(rhs.m_Impl) }, m_IsInit{ rhs.m_IsInit }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::AndroidCallBackUnitTestSuite& Framework::AndroidCallBackUnitTestSuite
	::operator=(AndroidCallBackUnitTestSuite&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::operator=(move(rhs));

	m_StreamType = move(rhs.m_StreamType);
	m_Impl = move(rhs.m_Impl);
	m_IsInit = rhs.m_IsInit;

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::AndroidCallBackUnitTestSuite
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_StreamType != nullptr && m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

bool Framework::AndroidCallBackUnitTestSuite
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (!m_IsInit)
	{
		m_IsInit = true;

		return AddSuiteOnInitialize();
	}
	else
	{
		return true;
	}	
}

int Framework::AndroidCallBackUnitTestSuite
	::KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
	FRAMEWORK_CLASS_IS_VALID_1; 

	const auto keyCode = System::AndroidKeyEventGetKeyCode(androidInputEvent);

	switch (keyCode)
	{
	case System::AndroidKeyCodes::F1:
	{
		ResetTestData();
		break;
	}

	case System::AndroidKeyCodes::F5:
	{
		RunUnitTest();
		break;
	}

	default:
		break;
	}

	return ParentType::KeyDownMessage(androidApp, androidInputEvent);
}

void Framework::AndroidCallBackUnitTestSuite
	::Display(AndroidApp* androidApp, int64_t timeDelta)
{
	FRAMEWORK_CLASS_IS_VALID_1;
 
	return ParentType::Display(androidApp, timeDelta);
}

void Framework::AndroidCallBackUnitTestSuite
	::DoAddSuite(const Suite& suite)
{
	FRAMEWORK_CLASS_IS_VALID_1; 

	return m_Impl->AddSuite(suite);
}

CoreTools::OStreamShared Framework::AndroidCallBackUnitTestSuite
	::GetStreamShared() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return  m_StreamType->GetStreamShared();
}

int Framework::AndroidCallBackUnitTestSuite
	::GetPassedNumber() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return m_Impl->GetPassedNumber();
}

// private
bool Framework::AndroidCallBackUnitTestSuite
	::AddSuiteOnInitialize()
{
	const auto result = ParentType::Initialize();

	AddSuite();

	m_Impl->RunUnitTest();
	m_Impl->PrintReport();

	return result;
}

// private
void Framework::AndroidCallBackUnitTestSuite
	::ResetTestData()
{
	m_Impl->ResetTestData();
	GetStreamShared() << "测试数据已清零。\n";
}

// private
void Framework::AndroidCallBackUnitTestSuite
	::RunUnitTest()
{
	m_Impl->RunUnitTest();
	m_Impl->PrintReport();
}

void Framework::AndroidCallBackUnitTestSuite
	::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
	m_Impl->AddTest(suiteName, suite, testName, unitTest);
}

bool  Framework::AndroidCallBackUnitTestSuite
	::IsPrintRun() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return true;
}