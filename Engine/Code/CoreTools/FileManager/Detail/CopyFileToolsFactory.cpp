// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 14:52)

#include "CoreTools/CoreToolsExport.h"

#include "CopyFileToolsFactory.h"
#include "CommonCopyFileTools.h"
#include "WindowsCopyFileTools.h" 

using std::make_shared;

// static 
CoreTools::CopyFileToolsFactory::CopyFileToolsPtr CoreTools::CopyFileToolsFactory
	::Create(const String& inFileName, const String& outFileName)
{
#ifdef SYSTEM_PLATFORM_WIN32
	return make_shared<WindowsCopyFileTools>(inFileName, outFileName);
#else // !SYSTEM_PLATFORM_WIN32
	return make_shared<CommonCopyFileTools>(inFileName, outFileName);
#endif	// SYSTEM_PLATFORM_WIN32
}




