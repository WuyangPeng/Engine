// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.3.0.1 (2020/05/28 10:41)

#include "Framework/FrameworkExport.h"

#include "EngineDirectoryResult.h" 
#include "DirectoryDefaultName.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using namespace std::literals;

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineDirectoryResult)

const System::String Framework::EngineDirectoryResult
	::GetDirectory(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	const auto iter = m_Result.find({ renderingDirectory,analysisDirectory });
	if (iter != m_Result.cend())
	{
		return iter->second;
	}
	else
	{
		return DirectoryDefaultName::GetDefaultNullName();
	}
}

const System::String Framework::EngineDirectoryResult
	::GetDirectory(AnalysisDirectory analysisDirectory) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return GetDirectory(RenderingDirectory::Null, analysisDirectory);
}

void Framework::EngineDirectoryResult
	::InsertDirectory(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory, const String& directory)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_Result.insert({ { renderingDirectory,analysisDirectory },directory });
}

void Framework::EngineDirectoryResult
	::SetDefaultDirectory()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SetDefaultBaseDirectory();
	SetDefaultRenderingDirectory();
}

// private
void Framework::EngineDirectoryResult
	::SetDefaultBaseDirectory()
{
	for (auto index = AnalysisDirectory::Resource; index <= AnalysisDirectory::Configuration; ++index)
	{
		SetDefaultBaseDirectory(index);
	}
}

void Framework::EngineDirectoryResult
	::SetDefaultBaseDirectory(AnalysisDirectory analysisDirectory)
{
	const ResultIndex index{ RenderingDirectory::Null,analysisDirectory };
	const auto iter = m_Result.find(index);
	if (iter == m_Result.cend())
	{
		m_Result.insert({ index, DirectoryDefaultName::GetDefaultName(analysisDirectory) });
	}
}

void Framework::EngineDirectoryResult
	::SetDefaultRenderingDirectory()
{
	for (auto index = RenderingDirectory::Default; index <= RenderingDirectory::DirectX; ++index)
	{
		SetDefaultRenderingDirectory(index);
	}
}

void Framework::EngineDirectoryResult
	::SetDefaultRenderingDirectory(RenderingDirectory renderingDirectory)
{
	for (auto index = AnalysisDirectory::LittleEndian; index <= AnalysisDirectory::Image; ++index)
	{
		SetDefaultRenderingDirectory(renderingDirectory, index);
	}
}

void Framework::EngineDirectoryResult
	::SetDefaultRenderingDirectory(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory)
{
	const ResultIndex index{ renderingDirectory,analysisDirectory };
	const auto iter = m_Result.find(index);
	if (iter == m_Result.cend())
	{
		m_Result.insert({ index, DirectoryDefaultName::GetDefaultName(analysisDirectory) });
	}
}
