// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 15:36)

#include "WindowInstanceParameterTesting.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using namespace std::literals;

namespace Framework
{
	using TestingType = WindowInstanceParameter;
}

Framework::WindowInstanceParameterTesting
	::WindowInstanceParameterTesting(const OStreamShared& stream, HInstance instance)
	:ParentType{ stream }, m_Instance{ instance }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowInstanceParameterTesting)

void Framework::WindowInstanceParameterTesting ::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}


 

void Framework::WindowInstanceParameterTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
}

void Framework::WindowInstanceParameterTesting
	::ValueTest()
{
	const auto className = SYSTEM_TEXT("ClassName"s) ;

	TestingType parameter{ m_Instance, className };

	ASSERT_EQUAL(m_Instance, parameter.GetHInstance());
	ASSERT_EQUAL(className, parameter.GetWindowClassName());
}
