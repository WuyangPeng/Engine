// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/29 11:25)

#include "Framework/FrameworkExport.h"

#include "EngineDirectoryPath.h" 
#include "DirectoryDefaultName.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

Framework::EngineDirectoryPath
	::EngineDirectoryPath(const EngineDirectoryResult& result)
	:m_Result{ result }
{
	Analysis();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Framework::EngineDirectoryPath
	::Analysis()
{
	for (auto index = RenderingDirectory::Default; index <= RenderingDirectory::DirectX; ++index)
	{
		Analysis(index);
	}
}

void Framework::EngineDirectoryPath
	::Analysis(RenderingDirectory renderingDirectory)
{
	for (auto index = EndianDirectory::LittleEndian; index <= EndianDirectory::BigEndian; ++index)
	{
		Analysis(renderingDirectory, index);
	}
}

void Framework::EngineDirectoryPath
	::Analysis(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory)
{
	for (auto index = AnalysisDirectory::Directory; index <= AnalysisDirectory::Image; ++index)
	{
		Analysis(renderingDirectory, endianDirectory, index);
	}
}

void Framework::EngineDirectoryPath
	::Analysis(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory, AnalysisDirectory analysisDirectory)
{	
	auto directory = GetDirectoryResult(renderingDirectory, endianDirectory, analysisDirectory);

	m_PathType.insert({ { endianDirectory,renderingDirectory,analysisDirectory }, directory });
}

const Framework::EngineDirectoryPath::String Framework::EngineDirectoryPath
	::GetDirectoryResult(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory, AnalysisDirectory analysisDirectory)
{
	auto endianDirectoryDescribe = m_Result.GetDirectory(renderingDirectory, System::EnumCastUnderlying<AnalysisDirectory>(endianDirectory));

	auto directory = m_Result.GetDirectory(renderingDirectory, analysisDirectory);

	if (analysisDirectory == AnalysisDirectory::Directory)
	{
		if (!directory.empty())
		{
			directory += DirectoryDefaultName::GetSuffix();
		}

		directory += endianDirectoryDescribe;
	}
	else
	{
		auto renderingDirectoryDescribe = m_Result.GetDirectory(renderingDirectory, AnalysisDirectory::Directory);

		if (!renderingDirectoryDescribe.empty())
		{
			renderingDirectoryDescribe += DirectoryDefaultName::GetSuffix();
		}

		if (!endianDirectoryDescribe.empty())
		{
			endianDirectoryDescribe += DirectoryDefaultName::GetSuffix();
		}

		directory = renderingDirectoryDescribe + endianDirectoryDescribe + directory;
	}

	return directory;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineDirectoryPath)

const System::String Framework::EngineDirectoryPath
	::GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	const auto iter = m_PathType.find({ endianDirectory ,renderingDirectory,analysisDirectory });
	if (iter != m_PathType.cend())
	{
		return iter->second;
	}
	else
	{
		return DirectoryDefaultName::GetDefaultNullName();
	}
}

const System::String Framework::EngineDirectoryPath
	::GetDirectory(AnalysisDirectory analysisDirectory) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Result.GetDirectory(analysisDirectory);
}

