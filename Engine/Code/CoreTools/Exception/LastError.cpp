// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:47)

#include "CoreTools/CoreToolsExport.h"

#include "LastError.h"
#include "System/Window/LastPlatformError.h"
#include "System/Window/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LastError
	::LastError()
	:m_LastError{ System::GetPlatformLastError() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::LastError
	::~LastError()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	System::SetPlatformLastError(System::WindowError::Success);
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LastError)

CoreTools::LastError::WindowError CoreTools::LastError
	::GetLastError() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_LastError;
}
