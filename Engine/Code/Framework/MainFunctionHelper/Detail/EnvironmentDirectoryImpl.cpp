// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:52)

#include "Framework/FrameworkExport.h"

#include "EnvironmentDirectoryImpl.h" 
#include "DirectoryDefaultName.h"
#include "AnalysisEngineDirectory.h"
#include "CoreTools/FileManager/EnvironmentVariable.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using namespace std::literals;

Framework::EnvironmentDirectoryImpl
	::EnvironmentDirectoryImpl(const String& engineEnvironment, const String& engineDirectory)
	: m_EngineEnvironment{ engineEnvironment }, m_EngineDirectory{ GenerateEngineDirectory(engineEnvironment) }, m_EngineDirectoryPath{ GetEngineDirectoryPath(engineDirectory) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// static
// private
const System::String Framework::EnvironmentDirectoryImpl
	::GenerateEngineDirectory(const String& engineEnvironment)
{
	CoreTools::EnvironmentVariable variable{ engineEnvironment };
	auto engineInstallationDirectory = variable.GetVariable();

	return engineInstallationDirectory;
}

// static
// private
const Framework::EngineDirectoryPath Framework::EnvironmentDirectoryImpl
	::GetEngineDirectoryPath(const String& engineDirectory)
{ 
	auto jsonName = GetJsonName(engineDirectory);

	AnalysisEngineDirectory analysisEngineDirectory{ jsonName };

	return EngineDirectoryPath{ analysisEngineDirectory.GetEngineDirectoryResult() };		
}

// static
// private
const std::string Framework::EnvironmentDirectoryImpl
	::GetJsonName(const String& variableName)
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
bool Framework::EnvironmentDirectoryImpl
	::IsValid() const noexcept
{
	if (!m_EngineEnvironment.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

const System::String Framework::EnvironmentDirectoryImpl
	::GetEngineEnvironment() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_EngineEnvironment;
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetEngineDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	if (!m_EngineDirectory.empty())
		return m_EngineDirectory + DirectoryDefaultName::GetSuffix();
	else
		return DirectoryDefaultName::GetDefaultNullName();
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetDirectory(UpperDirectory analysisDirectory) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetEngineDirectory() + m_EngineDirectoryPath.GetDirectory(System::EnumCastUnderlying<AnalysisDirectory>(analysisDirectory)) + DirectoryDefaultName::GetSuffix();
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetPath(RenderingAnalysisDirectory analysisDirectory) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetPath(RenderingDirectory::Default, analysisDirectory);
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetPath(RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

#ifdef SYSTEM_LITTLE_ENDIAN
	return GetPath(EndianDirectory::LittleEndian, renderingDirectory, analysisDirectory);
#else // !SYSTEM_LITTLE_ENDIAN
	return GetPath(EndianDirectory::BigEndian, renderingDirectory, analysisDirectory);
#endif // SYSTEM_LITTLE_ENDIAN 
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	auto path = m_EngineDirectoryPath.GetPath(endianDirectory, renderingDirectory, System::EnumCastUnderlying<AnalysisDirectory>(analysisDirectory));
	if (!path.empty())
	{
		path += DirectoryDefaultName::GetSuffix();
	}

	return GetDirectory(UpperDirectory::Resource) + path;
}


