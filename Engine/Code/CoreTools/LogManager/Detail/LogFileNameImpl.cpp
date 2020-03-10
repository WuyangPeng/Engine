// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 10:27)

#include "CoreTools/CoreToolsExport.h"

#include "LogFileNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogFileNameImpl
	::LogFileNameImpl(const String& fileName)
	:m_FileName{ fileName }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogFileNameImpl)

System::String CoreTools::LogFileNameImpl
	::GetFileName() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_FileName;
}
