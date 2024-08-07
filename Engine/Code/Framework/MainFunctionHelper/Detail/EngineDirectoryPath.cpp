/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/07 10:34)

#include "Framework/FrameworkExport.h"

#include "DirectoryDefaultName.h"
#include "EngineDirectoryPath.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using System::operator++;

Framework::EngineDirectoryPath::EngineDirectoryPath(EngineDirectoryResult result)
    : result{ std::move(result) }
{
    Analysis();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

void Framework::EngineDirectoryPath::Analysis()
{
    for (auto index = RenderingDirectory::Default; index <= RenderingDirectory::DirectX; ++index)
    {
        Analysis(index);
    }
}

void Framework::EngineDirectoryPath::Analysis(RenderingDirectory renderingDirectory)
{
    for (auto index = EndianDirectory::LittleEndian; index <= EndianDirectory::BigEndian; ++index)
    {
        Analysis(renderingDirectory, index);
    }
}

void Framework::EngineDirectoryPath::Analysis(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory)
{
    for (auto index = AnalysisDirectory::Directory; index <= AnalysisDirectory::Image; ++index)
    {
        Analysis(renderingDirectory, endianDirectory, index);
    }
}

void Framework::EngineDirectoryPath::Analysis(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory, AnalysisDirectory analysisDirectory)
{
    const auto directory = GetDirectoryResult(renderingDirectory, endianDirectory, analysisDirectory);

    pathType.emplace(IndexType{ endianDirectory, renderingDirectory, analysisDirectory }, directory);
}

System::String Framework::EngineDirectoryPath::GetDirectoryResult(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory, AnalysisDirectory analysisDirectory) const
{
    const auto endianDirectoryDescribe = result.GetDirectory(renderingDirectory, System::EnumCastUnderlying<AnalysisDirectory>(endianDirectory));

    const auto directory = result.GetDirectory(renderingDirectory, analysisDirectory);

    if (analysisDirectory == AnalysisDirectory::Directory)
    {
        return GetNoRenderingDirectoryResult(endianDirectoryDescribe, directory);
    }
    else
    {
        return GetRenderingDirectoryResult(renderingDirectory, endianDirectoryDescribe, directory);
    }
}

System::String Framework::EngineDirectoryPath::GetRenderingDirectoryResult(RenderingDirectory renderingDirectory, const String& endianDirectoryDescribe, const String& directory) const
{
    auto renderingDirectoryDescribe = result.GetDirectory(renderingDirectory, AnalysisDirectory::Directory);

    if (!renderingDirectoryDescribe.empty())
    {
        renderingDirectoryDescribe += DirectoryDefaultName::GetSuffix();
    }

    if (endianDirectoryDescribe.empty())
    {
        return renderingDirectoryDescribe + directory;
    }
    else
    {
        return renderingDirectoryDescribe + endianDirectoryDescribe + DirectoryDefaultName::GetSuffix() + directory;
    }
}

System::String Framework::EngineDirectoryPath::GetNoRenderingDirectoryResult(const String& endianDirectoryDescribe, const String& directory)
{
    if (directory.empty())
    {
        return endianDirectoryDescribe;
    }
    else
    {
        return directory + DirectoryDefaultName::GetSuffix() + endianDirectoryDescribe;
    }
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineDirectoryPath)

System::String Framework::EngineDirectoryPath::GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (const auto iter = pathType.find({ endianDirectory, renderingDirectory, analysisDirectory });
        iter != pathType.cend())
    {
        return iter->second;
    }
    else
    {
        return DirectoryDefaultName::GetDefaultNullName();
    }
}

System::String Framework::EngineDirectoryPath::GetDirectory(AnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return result.GetDirectory(analysisDirectory);
}
