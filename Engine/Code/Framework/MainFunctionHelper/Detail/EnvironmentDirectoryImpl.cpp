///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:40)

#include "Framework/FrameworkExport.h"

#include "AnalysisEngineDirectory.h"
#include "DirectoryDefaultName.h"
#include "EnvironmentDirectoryImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/EnvironmentVariable.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using namespace std::literals;

Framework::EnvironmentDirectoryImpl::EnvironmentDirectoryImpl(const String& engineEnvironment, const String& engineDirectory)
    : engineEnvironment{ engineEnvironment }, engineDirectory{ GenerateEngineDirectory(engineEnvironment) }, engineDirectoryPath{ GetEngineDirectoryPath(engineDirectory) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// static
// private
System::String Framework::EnvironmentDirectoryImpl::GenerateEngineDirectory(const String& engineEnvironment)
{
    CoreTools::EnvironmentVariable variable{ engineEnvironment };
    auto engineInstallationDirectory = variable.GetVariable();

    return engineInstallationDirectory;
}

// static
// private
Framework::EngineDirectoryPath Framework::EnvironmentDirectoryImpl::GetEngineDirectoryPath(const String& engineDirectory)
{
    auto jsonName = GetJsonName(engineDirectory);

    AnalysisEngineDirectory analysisEngineDirectory{ jsonName };

    return EngineDirectoryPath{ analysisEngineDirectory.GetEngineDirectoryResult() };
}

// static
// private
std::string Framework::EnvironmentDirectoryImpl::GetJsonName(const String& variableName)
{
    if (variableName.empty() || variableName == SYSTEM_TEXT("Default"s))
    {
        return "";
    }
    else
    {
        CoreTools::EnvironmentVariable environmentVariable{ variableName };

        return CoreTools::StringConversion::StandardConversionMultiByte(environmentVariable.GetVariable());
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::EnvironmentDirectoryImpl::IsValid() const noexcept
{
    if (!engineEnvironment.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

System::String Framework::EnvironmentDirectoryImpl::GetEngineEnvironment() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return engineEnvironment;
}

System::String Framework::EnvironmentDirectoryImpl::GetEngineDirectory() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    if (!engineDirectory.empty())
        return engineDirectory + DirectoryDefaultName::GetSuffix();
    else
        return DirectoryDefaultName::GetDefaultNullName();
}

System::String Framework::EnvironmentDirectoryImpl::GetDirectory(UpperDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return GetEngineDirectory() + engineDirectoryPath.GetDirectory(System::EnumCastUnderlying<AnalysisDirectory>(analysisDirectory)) + DirectoryDefaultName::GetSuffix();
}

System::String Framework::EnvironmentDirectoryImpl::GetPath(RenderingAnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return GetPath(RenderingDirectory::Default, analysisDirectory);
}

System::String Framework::EnvironmentDirectoryImpl::GetPath(RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

#ifdef SYSTEM_LITTLE_ENDIAN

    return GetPath(EndianDirectory::LittleEndian, renderingDirectory, analysisDirectory);

#else  // !SYSTEM_LITTLE_ENDIAN

    return GetPath(EndianDirectory::BigEndian, renderingDirectory, analysisDirectory);

#endif  // SYSTEM_LITTLE_ENDIAN
}

System::String Framework::EnvironmentDirectoryImpl::GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    auto path = engineDirectoryPath.GetPath(endianDirectory, renderingDirectory, System::EnumCastUnderlying<AnalysisDirectory>(analysisDirectory));
    if (!path.empty())
    {
        path += DirectoryDefaultName::GetSuffix();
    }

    return GetDirectory(UpperDirectory::Resource) + path;
}
