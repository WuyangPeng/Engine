// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:54)

#include "Framework/FrameworkExport.h"

#include "ConsoleMainFunctionHelper.h"
#include "Detail/ConsoleMainFunctionHelperImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <iostream>
#include <stdexcept>

using std::string;
using std::cerr;
using std::runtime_error;
using CoreTools::Error;

Framework::ConsoleMainFunctionHelper
	::ConsoleMainFunctionHelper(int argc,char* argv[],const System::String& consoleTitle,const EnvironmentDirectory& environmentDirectory)
	:MainFunctionHelperBase{ environmentDirectory }, m_Argc{ argc }, m_Argv{ argv }, m_Impl{}
{
	ConsoleMainFunctionHelperInit(consoleTitle);

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ConsoleMainFunctionHelper
	::~ConsoleMainFunctionHelper()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::ConsoleMainFunctionHelper
	::IsValid() const noexcept
{
	if(ParentType::IsValid() && 1 <= m_Argc && m_Argv[0] != nullptr)
		return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT

int Framework::ConsoleMainFunctionHelper
    ::GetArgc() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Argc;
}

char** Framework::ConsoleMainFunctionHelper
	::GetArgv() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Argv;
}

System::String Framework::ConsoleMainFunctionHelper
	::GetApplicationProjectDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	if(m_Impl != nullptr)
		return m_Impl->GetApplicationProjectDirectory();
	else
		return System::String();
}

// private
void Framework::ConsoleMainFunctionHelper
	::ConsoleMainFunctionHelperInit(const System::String& consoleTitle)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	try
	{
		System::String engineInstallationDirectory = GetEngineInstallationDirectory();

		m_Impl.reset(new ImplType(m_Argc, m_Argv, consoleTitle, engineInstallationDirectory));
	}
	catch (Error& error)
	{
		CERR << error.GetError() << SYSTEM_TEXT('\n');
	}
	catch (runtime_error& error)
	{
		cerr << error.what() << '\n';
	}
	catch (...)
	{
		CERR << SYSTEM_TEXT("Œ¥÷™¥ÌŒÛ\n");
	}
}






