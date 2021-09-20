// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:36)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_TENTH_SUBCLASS_SMART_POINTER_TEST_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_TENTH_SUBCLASS_SMART_POINTER_TEST_H

#include "CoreTools/Helper/UserMacro.h"

#include "NinthSubclassSmartPointerTest.h"

#include <string>

namespace CoreTools
{
	class TenthSubclassSmartPointerTest : public NinthSubclassSmartPointerTest
	{
	public:
		using ClassType = TenthSubclassSmartPointerTest;
		using ParentType = NinthSubclassSmartPointerTest;

	public:
		explicit TenthSubclassSmartPointerTest(int value, const std::string& name, double ratio); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SUITE_TENTH_SUBCLASS_SMART_POINTER_TEST_H