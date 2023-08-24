///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:48)

#include "Framework/FrameworkExport.h"

#include "DirectoryDefaultName.h"
#include "EngineDirectoryResult.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using System::operator++;

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineDirectoryResult)

System::String Framework::EngineDirectoryResult::GetDirectory(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (const auto iter = result.find({ renderingDirectory, analysisDirectory });
        iter != result.cend())
    {
        return iter->second;
    }
    else
    {
        return DirectoryDefaultName::GetDefaultNullName();
    }
}

System::String Framework::EngineDirectoryResult::GetDirectory(AnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return GetDirectory(RenderingDirectory::Null, analysisDirectory);
}

void Framework::EngineDirectoryResult::InsertDirectory(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory, const String& directory)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    result.emplace(ResultIndex{ renderingDirectory, analysisDirectory }, directory);
}

void Framework::EngineDirectoryResult::SetDefaultDirectory()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    SetDefaultBaseDirectory();
    SetDefaultRenderingDirectory();
}

void Framework::EngineDirectoryResult::SetDefaultBaseDirectory()
{
    for (auto index = AnalysisDirectory::Resource; index <= AnalysisDirectory::Configuration; ++index)
    {
        SetDefaultBaseDirectory(index);
    }
}

void Framework::EngineDirectoryResult::SetDefaultBaseDirectory(AnalysisDirectory analysisDirectory)
{
    const ResultIndex index{ RenderingDirectory::Null, analysisDirectory };

    if (const auto iter = result.find(index);
        iter == result.cend())
    {
        result.emplace(index, DirectoryDefaultName::GetDefaultName(analysisDirectory));
    }
}

void Framework::EngineDirectoryResult::SetDefaultRenderingDirectory()
{
    for (auto index = RenderingDirectory::Default; index <= RenderingDirectory::DirectX; ++index)
    {
        SetDefaultRenderingDirectory(index);
    }
}

void Framework::EngineDirectoryResult::SetDefaultRenderingDirectory(RenderingDirectory renderingDirectory)
{
    for (auto index = AnalysisDirectory::LittleEndian; index <= AnalysisDirectory::Image; ++index)
    {
        SetDefaultRenderingDirectory(renderingDirectory, index);
    }
}

void Framework::EngineDirectoryResult::SetDefaultRenderingDirectory(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory)
{
    const ResultIndex index{ renderingDirectory, analysisDirectory };

    if (const auto iter = result.find(index);
        iter == result.cend())
    {
        result.emplace(index, DirectoryDefaultName::GetDefaultName(analysisDirectory));
    }
}
