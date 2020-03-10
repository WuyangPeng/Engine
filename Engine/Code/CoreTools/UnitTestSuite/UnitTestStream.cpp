// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:31)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestStream.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <iostream>

using std::ostream;

CoreTools::UnitTestStream
	::UnitTestStream(ostream* osPtr)
	:m_OsPtr{ osPtr }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::UnitTestStream
	::~UnitTestStream()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UnitTestStream
	::IsValid() const noexcept
{
	if (m_OsPtr != nullptr && *m_OsPtr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

ostream* CoreTools::UnitTestStream
	::GetStream() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_OsPtr;
}

void CoreTools::UnitTestStream
	::SetStream(ostream* osPtr)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_0(osPtr != nullptr, "指针无效");

	m_OsPtr = osPtr;
}
