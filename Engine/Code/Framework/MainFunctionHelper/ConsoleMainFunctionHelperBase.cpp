// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:52)

#include "Framework/FrameworkExport.h"

#include "ConsoleMainFunctionHelperBase.h"
#include "Detail/DirectoryDefaultName.h"
#include "Detail/ConsoleMainFunctionHelperBaseImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::ConsoleMainFunctionHelperBase
	::ConsoleMainFunctionHelperBase(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
	:MainFunctionHelperBase{ environmentDirectory }, impl{ }, m_Argc{ argc }, m_Argv{ argv }
{
	ConsoleMainFunctionHelperInit(consoleTitle);

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Framework::ConsoleMainFunctionHelperBase
	::ConsoleMainFunctionHelperInit(const System::String& consoleTitle)
{
	EXCEPTION_TRY
	{
		auto engineInstallationDirectory = GetEngineInstallationDirectory();

		impl = make_shared<ImplType>(m_Argc, m_Argv, consoleTitle, engineInstallationDirectory);
	}
	EXCEPTION_ENTRY_POINT_CATCH
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::ConsoleMainFunctionHelperBase
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 1 <= m_Argc && m_Argv != nullptr && *m_Argv != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int Framework::ConsoleMainFunctionHelperBase
	::GetArgc() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Argc;
}

char** Framework::ConsoleMainFunctionHelperBase
	::GetArgv() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Argv;
}

System::String Framework::ConsoleMainFunctionHelperBase
	::GetApplicationProjectDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	if (impl != nullptr)
		return impl->GetApplicationProjectDirectory();
	else
		return DirectoryDefaultName::GetDefaultNullName();
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ConsoleMainFunctionHelperBase, GetCommand, Framework::ConsoleMainFunctionHelperBase::Command)
