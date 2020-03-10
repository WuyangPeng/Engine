// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 11:03)

#include "CoreTools/CoreToolsExport.h"

#include "LogConsoleTextColorsManager.h"
#include "Detail/LogConsoleTextColorsManagerImpl.h"
#include "Detail/LogConsoleTextColorsManagerFactory.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::ostream;

CoreTools::LogConsoleTextColorsManager
	::LogConsoleTextColorsManager(LogLevel logLevel)
	:m_Impl{ LogConsoleTextColorsManagerFactory::Create(logLevel) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogConsoleTextColorsManager
	::LogConsoleTextColorsManager(ostream* osPtr, LogLevel logLevel)
	:m_Impl{ LogConsoleTextColorsManagerFactory::Create(osPtr, logLevel) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, LogConsoleTextColorsManager)

