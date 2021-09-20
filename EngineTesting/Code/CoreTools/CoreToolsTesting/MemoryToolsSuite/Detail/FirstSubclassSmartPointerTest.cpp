// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:39)

#include "FirstSubclassSmartPointerTest.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::FirstSubclassSmartPointerTest
	::FirstSubclassSmartPointerTest(int value) noexcept
	:m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::FirstSubclassSmartPointerTest
	::~FirstSubclassSmartPointerTest()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FirstSubclassSmartPointerTest)

int CoreTools::FirstSubclassSmartPointerTest
	::GetValue() const noexcept
{
	CLASS_IS_VALID_CONST_9;

	return m_Value;
}
