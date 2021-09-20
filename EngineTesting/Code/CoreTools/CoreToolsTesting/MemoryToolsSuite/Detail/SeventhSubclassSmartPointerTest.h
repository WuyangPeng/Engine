// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 10:36)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_SEVENTH_SUBCLASS_SMART_POINTER_TEST_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_SEVENTH_SUBCLASS_SMART_POINTER_TEST_H

#include "SixthSubclassSmartPointerTest.h"

#include <string>

namespace CoreTools
{
	class SeventhSubclassSmartPointerTest : public SixthSubclassSmartPointerTest
	{
	public:
		using ClassType = SeventhSubclassSmartPointerTest;
		using ParentType = SixthSubclassSmartPointerTest;

	public:
		explicit SeventhSubclassSmartPointerTest(int value, const std::string& name); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SUITE_SEVENTH_SUBCLASS_SMART_POINTER_TEST_H