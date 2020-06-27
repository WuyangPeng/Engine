// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:31)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestStream.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <iostream>

using std::ostream;

CoreTools::UnitTestStream
	::UnitTestStream(const OStreamShared& osPtr)
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
	return true; 
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::OStreamShared& CoreTools::UnitTestStream
	::GetStream()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_OsPtr;
}

bool CoreTools::UnitTestStream::IsStreamSharedFile() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_OsPtr.IsFile();
}

