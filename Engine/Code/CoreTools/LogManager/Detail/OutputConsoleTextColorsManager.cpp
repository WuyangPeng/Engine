// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 11:00)

#include "CoreTools/CoreToolsExport.h"

#include "OutputConsoleTextColorsManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Console/ConsoleTextColorsManagerDetail.h"

CoreTools::OutputConsoleTextColorsManager
	::OutputConsoleTextColorsManager(LogLevel logLevel)
	:ParentType{ logLevel }, m_ConsoleTextColorsManager{ GetTextColor(logLevel), GetIntensified(logLevel) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::OutputConsoleTextColorsManager
	::~OutputConsoleTextColorsManager()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, OutputConsoleTextColorsManager)


