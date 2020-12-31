// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/29 11:23)

#include "Framework/FrameworkExport.h"

#include "AnalysisEngineDirectory.h" 
#include "DirectoryDefaultName.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using std::string;
using std::exception;

Framework::AnalysisEngineDirectory
	::AnalysisEngineDirectory(const string& jsonName)
	: m_BasicTree{ }, m_ResourceTree{ }, m_ConfigurationTree{ }, m_Result{ }
{
	if (!jsonName.empty())
	{
		Analysis(jsonName);
	}
	
	m_Result.SetDefaultDirectory();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Framework::AnalysisEngineDirectory
	::Analysis(const string& jsonName)
{
	EXCEPTION_TRY
	{
		read_json(jsonName, m_BasicTree);
		AnalysisBase();
		AnalysisRendering();
	}
	EXCEPTION_STD_EXCEPTION_CATCH(Framework)
}

// private
void Framework::AnalysisEngineDirectory
	::AnalysisBase()
{
	for (auto index = AnalysisDirectory::Resource; index <= AnalysisDirectory::Configuration; ++index)
	{
		InsertResult(RenderingDirectory::Null, index);
	}
}

// private
void Framework::AnalysisEngineDirectory
	::AnalysisRendering()
{
	for (auto index = RenderingDirectory::Default; index <= RenderingDirectory::DirectX; ++index)
	{
		AnalysisRendering(index);
	}
}

// private
void Framework::AnalysisEngineDirectory
	::AnalysisRendering(RenderingDirectory renderingDirectory)
{
	EXCEPTION_TRY
	{
		const auto analysisDirectory = System::EnumCastUnderlying<AnalysisDirectory>(renderingDirectory);
		const BasicTree renderingTree{ m_BasicTree.get_child(DirectoryDefaultName::GetDefaultKeyName(analysisDirectory)) };

		AnalysisRendering(renderingDirectory, renderingTree);
	}
	EXCEPTION_STD_EXCEPTION_CATCH(Framework)
}

// private
void Framework::AnalysisEngineDirectory
	::AnalysisRendering(RenderingDirectory renderingDirectory, const BasicTree& renderingTree)
{
	for (auto index = AnalysisDirectory::LittleEndian; index <= AnalysisDirectory::Image; ++index)
	{
		InsertResult(renderingDirectory, index, renderingTree);
	}
}

// private
void Framework::AnalysisEngineDirectory
	::InsertResult(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory)
{
	InsertResult(renderingDirectory, analysisDirectory, m_BasicTree);
}

// private
void Framework::AnalysisEngineDirectory
	::InsertResult(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory, const BasicTree& renderingTree)
{
	const auto defaultKey = DirectoryDefaultName::GetDefaultKeyName(analysisDirectory);
	const auto defaultName = DirectoryDefaultName::GetDefaultName(analysisDirectory);

	const auto resource = renderingTree.get(defaultKey, defaultName);
	m_Result.InsertDirectory(renderingDirectory, analysisDirectory, resource);
}

CLASS_INVARIANT_STUB_DEFINE(Framework, AnalysisEngineDirectory)

const Framework::EngineDirectoryResult Framework::AnalysisEngineDirectory
	::GetEngineDirectoryResult() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Result;
}
