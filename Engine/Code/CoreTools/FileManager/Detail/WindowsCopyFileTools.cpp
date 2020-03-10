// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 17:02)

#include "CoreTools/CoreToolsExport.h"

#include "WindowsCopyFileTools.h"
#include "System/FileManager/File.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::WindowsCopyFileTools
	::WindowsCopyFileTools(const String& inFileName, const String& outFileName)
	:m_InFileName{ inFileName }, m_OutFileName{ outFileName }
{
	if (!System::CopySystemFile(m_InFileName.c_str(), m_OutFileName.c_str()))
	{
		THROW_WINDOWS_EXCEPTION;
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WindowsCopyFileTools)





