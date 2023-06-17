///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 10:45)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateDirectoryImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

using std::string;
using namespace std::literals;

const System::String AssistTools::GenerateTemplateDirectoryImpl::forwardSlash{ SYSTEM_TEXT("/") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::engineDirectory{ SYSTEM_TEXT("Engine") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::projectName{ SYSTEM_TEXT("ProjectName") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::coreName{ SYSTEM_TEXT("ToolsName") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::moduleName{ SYSTEM_TEXT("ModuleName") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::exeProjectName{ SYSTEM_TEXT("ExeProjectName") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::includeName{ SYSTEM_TEXT("IncludeName") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::dllProjectName{ SYSTEM_TEXT("DllProjectName") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::logFileName{ SYSTEM_TEXT("Log") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::configurationDirectory{ SYSTEM_TEXT("Configuration") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::managerName{ SYSTEM_TEXT("ManagerName") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::resource{ SYSTEM_TEXT("Resource") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::update{ SYSTEM_TEXT("Update.txt") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::codeDirectory{ SYSTEM_TEXT("Code") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::testing{ SYSTEM_TEXT("Testing") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::debugLibName{ SYSTEM_TEXT("DebugLibName") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::releaseLibName{ SYSTEM_TEXT("ReleaseLibName") };

const System::String AssistTools::GenerateTemplateDirectoryImpl::gameIncludeName{ SYSTEM_TEXT("GameIncludeName") };

AssistTools::GenerateTemplateDirectoryImpl::GenerateTemplateDirectoryImpl(const System::String& directory, const string& configurationFileName)
    : directory{ directory }, stringReplacing{ configurationFileName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateDirectoryImpl)

System::String AssistTools::GenerateTemplateDirectoryImpl::GetDirectory() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return directory;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetForwardSlash()
{
    return forwardSlash;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetEngineDirectory()
{
    return engineDirectory;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetProjectName()
{
    return projectName;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetCoreName()
{
    return coreName;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetModuleName()
{
    return moduleName;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetExeProjectName()
{
    return exeProjectName;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetDllProjectName()
{
    return dllProjectName;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetIncludeName()
{
    return includeName;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetLogFileName()
{
    return logFileName;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetConfigurationDirectory()
{
    return configurationDirectory;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetManagerName()
{
    return managerName;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetResource()
{
    return resource;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetUpdate()
{
    return update;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetCodeDirectory()
{
    return codeDirectory;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetReplacing(const System::String& original) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return stringReplacing.GetReplacing(original);
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetTesting()
{
    return testing;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetDebugLibName()
{
    return debugLibName;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetReleaseLibName()
{
    return releaseLibName;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetTestingIncludeName()
{
    return testing + includeName;
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetNewProjectName()
{
    return SYSTEM_TEXT("NewProjectName"s);
}

System::String AssistTools::GenerateTemplateDirectoryImpl::GetGameIncludeName()
{
    return gameIncludeName;
}
