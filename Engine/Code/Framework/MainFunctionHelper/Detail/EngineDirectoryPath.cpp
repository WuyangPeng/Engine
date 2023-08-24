///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:49)

#include "Framework/FrameworkExport.h"

#include "DirectoryDefaultName.h"
#include "EngineDirectoryPath.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using System::operator++;

Framework::EngineDirectoryPath::EngineDirectoryPath(const EngineDirectoryResult& result)
    : result{ result }
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
    auto directory = GetDirectoryResult(renderingDirectory, endianDirectory, analysisDirectory);

    pathType.emplace(IndexType{ endianDirectory, renderingDirectory, analysisDirectory }, directory);
}

Framework::EngineDirectoryPath::String Framework::EngineDirectoryPath::GetDirectoryResult(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory, AnalysisDirectory analysisDirectory)
{
    auto endianDirectoryDescribe = result.GetDirectory(renderingDirectory, System::EnumCastUnderlying<AnalysisDirectory>(endianDirectory));

    auto directory = result.GetDirectory(renderingDirectory, analysisDirectory);

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
        auto renderingDirectoryDescribe = result.GetDirectory(renderingDirectory, AnalysisDirectory::Directory);

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

NODISCARD System::String Framework::EngineDirectoryPath::GetDirectory(AnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return result.GetDirectory(analysisDirectory);
}
