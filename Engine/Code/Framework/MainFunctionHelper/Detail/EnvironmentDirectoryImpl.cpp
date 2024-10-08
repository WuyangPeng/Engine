/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/06 19:33)

#include "Framework/FrameworkExport.h"

#include "AnalysisEngineDirectory.h"
#include "DirectoryDefaultName.h"
#include "EnvironmentDirectoryImpl.h"
#include "System/DynamicLink/LibraryTools.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/EnvironmentVariable.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

Framework::EnvironmentDirectoryImpl::EnvironmentDirectoryImpl(const String& engineEnvironment, const String& engineDirectory)
    : engineEnvironment{ engineEnvironment }, engineDirectory{ GenerateEngineDirectory(engineEnvironment) }, engineDirectoryPath{ GetEngineDirectoryPath(engineDirectory) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

System::String Framework::EnvironmentDirectoryImpl::GenerateEngineDirectory(const String& engineEnvironment)
{
    const CoreTools::EnvironmentVariable variable{ engineEnvironment };

    return variable.GetVariable();
}

Framework::EngineDirectoryPath Framework::EnvironmentDirectoryImpl::GetEngineDirectoryPath(const String& engineDirectory)
{
    const auto jsonName = GetJsonName(engineDirectory);

    const AnalysisEngineDirectory analysisEngineDirectory{ jsonName };

    return EngineDirectoryPath{ analysisEngineDirectory.GetEngineDirectoryResult() };
}

std::string Framework::EnvironmentDirectoryImpl::GetJsonName(const String& variableName)
{
    if (variableName.empty() || variableName == SYSTEM_TEXT("Default"))
    {
        return "";
    }
    else
    {
        const CoreTools::EnvironmentVariable environmentVariable{ variableName };

        return CoreTools::StringConversion::StandardConversionMultiByte(environmentVariable.GetVariable());
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::EnvironmentDirectoryImpl::IsValid() const noexcept
{
    return !engineEnvironment.empty();
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

    if (engineDirectory.empty())
    {
        return DirectoryDefaultName::GetDefaultNullName();
    }
    else
    {
        return engineDirectory + DirectoryDefaultName::GetSuffix();
    }
}

System::String Framework::EnvironmentDirectoryImpl::GetDirectory(UpperDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return GetEngineDirectory() + engineDirectoryPath.GetDirectory(System::EnumCastUnderlying<AnalysisDirectory>(analysisDirectory)) + DirectoryDefaultName::GetSuffix();
}

Framework::EnvironmentDirectoryImpl::String Framework::EnvironmentDirectoryImpl::GetExecutableConfigurationDirectory() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return GetDirectory(UpperDirectory::Configuration) + CoreTools::StringConversion::MultiByteConversionStandard(System::GetExecutableNameRemoveSuffix()) + DirectoryDefaultName::GetSuffix();
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
