// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:35)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_FIFTH_SUBCLASS_SMART_POINTER_TEST_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_FIFTH_SUBCLASS_SMART_POINTER_TEST_H

#include "FourthSubclassSmartPointerTest.h"

#include <string>

namespace CoreTools
{
	class FifthSubclassSmartPointerTest : public FourthSubclassSmartPointerTest
	{
	public:
		using ClassType = FifthSubclassSmartPointerTest;
		using ParentType = FourthSubclassSmartPointerTest;

	public:
		explicit FifthSubclassSmartPointerTest(int value, const std::string& name); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SUITE_FIFTH_SUBCLASS_SMART_POINTER_TEST_H