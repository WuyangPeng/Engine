// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 10:39)

#include "FourthSubclassSmartPointerTest.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::FourthSubclassSmartPointerTest
	::FourthSubclassSmartPointerTest(int value, const string& name)
	:ParentType{ value }, m_Name{ name }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FourthSubclassSmartPointerTest)

const string CoreTools::FourthSubclassSmartPointerTest
	::GetName() const
{
	CLASS_IS_VALID_CONST_9;

	return m_Name;
}
