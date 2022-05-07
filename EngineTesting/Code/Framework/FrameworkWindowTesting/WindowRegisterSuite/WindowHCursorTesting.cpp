// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/07 19:21)

#include "resource.h"
#include "WindowHCursorTesting.h"  
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/WindowRegister/WindowHCursor.h"

#include <algorithm>

namespace Framework
{
	using TestingType = WindowHCursor;
}

Framework::WindowHCursorTesting
	::WindowHCursorTesting(const OStreamShared& stream, HInstance instance)
	:ParentType{ stream }, m_Instance{ instance },
	 m_Container{ { 0, System::g_Arrow },
				  { 32512, System::g_Arrow },
				  { 32513, System::g_Ibeam },
				  { 32514, System::g_Wait },
				  { 32515, System::g_Cross },
				  { 32516, System::g_UpArrow },
				  { 32642, System::g_SizeNwse },
				  { 32643, System::g_SizeNesw },
				  { 32644, System::g_SizeWe },
				  { 32645, System::g_SizeNs },
				  { 32646, System::g_SizeAll },
				  { 32648, System::g_No },
				  { 32649, System::g_IDCHand },
				  { 32650, System::g_AppStarting },
				  { 32651, System::g_Help } }
{ 
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowHCursorTesting)

void Framework::WindowHCursorTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowHCursorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CreateTest);
}

void Framework::WindowHCursorTesting
	::ConstructorTest()
{ 
	for_each(m_Container.begin(),m_Container.end(),[this](const auto& value) 
	{		
		const TestingType windowHCursor1{ value.second };
		ASSERT_EQUAL(windowHCursor1.GetHCursor(), System::LoadSystemCursor(nullptr, value.second));				
	});

	const TestingType windowHIcon2{ m_Instance,IDC_CURSOR1 };
	ASSERT_EQUAL(windowHIcon2.GetHCursor(), System::LoadSystemCursor(m_Instance, System::MakeIntreSource(IDC_CURSOR1)));
}

void Framework::WindowHCursorTesting
	::CreateTest()
{
	for_each(m_Container.begin(), m_Container.end(), [this](const auto& value)
	{
		const auto windowHCursor1 = TestingType::Create(m_Instance, true, value.first);
		ASSERT_EQUAL(windowHCursor1.GetHCursor(), System::LoadSystemCursor(nullptr, value.second));		 		
	});

	const auto windowHCursor2 = TestingType::Create(m_Instance, false, IDC_CURSOR1);
	ASSERT_EQUAL(windowHCursor2.GetHCursor(), System::LoadSystemCursor(m_Instance, System::MakeIntreSource(IDC_CURSOR1)));
}


