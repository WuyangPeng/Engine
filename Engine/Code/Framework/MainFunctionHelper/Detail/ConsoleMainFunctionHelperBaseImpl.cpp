// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:50)

#include "Framework/FrameworkExport.h"

#include "ConsoleMainFunctionHelperBaseImpl.h" 
#include "DirectoryDefaultName.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ConsoleMainFunctionHelperBaseImpl
	::ConsoleMainFunctionHelperBaseImpl(int argc, char** argv, const String& consoleTitle, const String& engineInstallationDirectory)
	:m_ConsoleTitle{ consoleTitle }, m_Command{ argc, argv },
	 m_ApplicationProjectDirectory{ ProduceApplicationProjectDirectory(consoleTitle,engineInstallationDirectory) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ConsoleMainFunctionHelperBaseImpl);

System::String Framework::ConsoleMainFunctionHelperBaseImpl
	::GetApplicationProjectDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_ApplicationProjectDirectory;
}

// private
// static
System::String Framework::ConsoleMainFunctionHelperBaseImpl
	::ProduceApplicationProjectDirectory(const String& consoleTitle, const String& engineInstallationDirectory)
{
	return engineInstallationDirectory + consoleTitle + DirectoryDefaultName::GetDefaultNullName();
}

Framework::ConsoleMainFunctionHelperBaseImpl::Command Framework::ConsoleMainFunctionHelperBaseImpl
	::GetCommand() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Command;
}



