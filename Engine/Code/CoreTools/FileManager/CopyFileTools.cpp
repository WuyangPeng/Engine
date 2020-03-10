// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 17:04)

#include "CoreTools/CoreToolsExport.h"

#include "CopyFileTools.h"
#include "Detail/CopyFileToolsFactory.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CopyFileTools
	::CopyFileTools(const String& inFileName, const String& outFileName)
	:m_Impl{ CopyFileToolsFactory::Create(inFileName,outFileName) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, CopyFileTools)





