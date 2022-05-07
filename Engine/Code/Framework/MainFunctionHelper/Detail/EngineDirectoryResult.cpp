///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 15:20)

#include "Framework/FrameworkExport.h"

#include "DirectoryDefaultName.h"
#include "EngineDirectoryResult.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using namespace std::literals;

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineDirectoryResult)

System::String Framework::EngineDirectoryResult::GetDirectory(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    const auto iter = result.find({ renderingDirectory, analysisDirectory });
    if (iter != result.cend())
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

// private
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
    const auto iter = result.find(index);
    if (iter == result.cend())
    {
        result.insert({ index, DirectoryDefaultName::GetDefaultName(analysisDirectory) });
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
    const auto iter = result.find(index);
    if (iter == result.cend())
    {
        result.insert({ index, DirectoryDefaultName::GetDefaultName(analysisDirectory) });
    }
}
