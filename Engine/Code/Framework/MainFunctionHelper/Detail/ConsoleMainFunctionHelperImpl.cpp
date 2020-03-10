// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 17:53)

#include "Framework/FrameworkExport.h"

#include "ConsoleMainFunctionHelperImpl.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::string;

Framework::ConsoleMainFunctionHelperImpl
	::ConsoleMainFunctionHelperImpl(int argc,char* argv[],const System::String& consoleTitle,const System::String& engineInstallationDirectory)	
	:m_ConsoleTitle{ consoleTitle }, m_Command{ argc, argv },
	 m_ApplicationProjectDirectory{ ProduceApplicationProjectDirectory(consoleTitle,engineInstallationDirectory) }
{	
	InsertEnvironmentDirectory();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ConsoleMainFunctionHelperImpl);

System::String Framework::ConsoleMainFunctionHelperImpl
	::GetApplicationProjectDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_ApplicationProjectDirectory;
}

// private
void Framework::ConsoleMainFunctionHelperImpl
	::InsertEnvironmentDirectory()
{
	// ʼ�ռ��Ӧ�ó���Ŀ¼��
	ENVIRONMENT_SINGLETON.InsertDirectory(m_ApplicationProjectDirectory);
}

// private
// static
System::String Framework::ConsoleMainFunctionHelperImpl
	::ProduceApplicationProjectDirectory(const System::String& consoleTitle,const System::String& engineInstallationDirectory)
{
	return engineInstallationDirectory + consoleTitle + SYSTEM_TEXT("/");
}




