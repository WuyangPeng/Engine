// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/10 22:20)

#include "WindowNameTesting.h"
#include "Framework/WindowRegister/WindowName.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using namespace std::literals;

namespace Framework
{
	using TestingType = WindowName;
}

Framework::WindowNameTesting
	::WindowNameTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowNameTesting)

void Framework::WindowNameTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowNameTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
}

void Framework::WindowNameTesting
	::NameTest()
{
	const auto className = SYSTEM_TEXT("className"s);
	const auto menuName = SYSTEM_TEXT("menuName"s);

	TestingType name{ className, menuName };

	ASSERT_EQUAL(name.GetWindowClassName(), className);
	ASSERT_EQUAL(name.GetWindowMenuName(), menuName);
}

