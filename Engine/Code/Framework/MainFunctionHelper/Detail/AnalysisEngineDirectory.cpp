/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/06/22 14:20)

#include "Framework/FrameworkExport.h"

#include "AnalysisEngineDirectory.h"
#include "DirectoryDefaultName.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using System::operator++;

Framework::AnalysisEngineDirectory::AnalysisEngineDirectory(const std::string& jsonName)
    : basicTree{}, resourceTree{}, configurationTree{}, result{}
{
    Init(jsonName);

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

void Framework::AnalysisEngineDirectory::Init(const std::string& jsonName)
{
    if (!jsonName.empty())
    {
        Analysis(jsonName);
    }

    result.SetDefaultDirectory();
}

void Framework::AnalysisEngineDirectory::Analysis(const std::string& jsonName)
{
    EXCEPTION_TRY
    {
        DoAnalysis(jsonName);
    }
    EXCEPTION_STD_EXCEPTION_CATCH(Framework)
}

void Framework::AnalysisEngineDirectory::DoAnalysis(const std::string& jsonName)
{
    read_json(jsonName, basicTree);
    AnalysisBase();
    AnalysisRendering();
}

void Framework::AnalysisEngineDirectory::AnalysisBase()
{
    for (auto index = AnalysisDirectory::Resource; index <= AnalysisDirectory::Configuration; ++index)
    {
        InsertResult(RenderingDirectory::Null, index);
    }
}

void Framework::AnalysisEngineDirectory::AnalysisRendering()
{
    for (auto index = RenderingDirectory::Default; index <= RenderingDirectory::DirectX; ++index)
    {
        AnalysisRendering(index);
    }
}

void Framework::AnalysisEngineDirectory::AnalysisRendering(RenderingDirectory renderingDirectory)
{
    EXCEPTION_TRY
    {
        DoAnalysisRendering(renderingDirectory);
    }
    EXCEPTION_STD_EXCEPTION_CATCH(Framework)
}

void Framework::AnalysisEngineDirectory::DoAnalysisRendering(RenderingDirectory renderingDirectory)
{
    const auto analysisDirectory = System::EnumCastUnderlying<AnalysisDirectory>(renderingDirectory);
    const auto& renderingTree = basicTree.get_child(DirectoryDefaultName::GetDefaultKeyName(analysisDirectory));

    AnalysisRendering(renderingDirectory, renderingTree);
}

void Framework::AnalysisEngineDirectory::AnalysisRendering(RenderingDirectory renderingDirectory, const BasicTree& renderingTree)
{
    for (auto index = AnalysisDirectory::LittleEndian; index <= AnalysisDirectory::Image; ++index)
    {
        InsertResult(renderingDirectory, index, renderingTree);
    }
}

void Framework::AnalysisEngineDirectory::InsertResult(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory)
{
    InsertResult(renderingDirectory, analysisDirectory, basicTree);
}

void Framework::AnalysisEngineDirectory::InsertResult(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory, const BasicTree& renderingTree)
{
    const auto defaultKey = DirectoryDefaultName::GetDefaultKeyName(analysisDirectory);
    const auto defaultName = DirectoryDefaultName::GetDefaultName(analysisDirectory);

    const auto resource = renderingTree.get(defaultKey, defaultName);
    result.InsertDirectory(renderingDirectory, analysisDirectory, resource);
}

CLASS_INVARIANT_STUB_DEFINE(Framework, AnalysisEngineDirectory)

Framework::EngineDirectoryResult Framework::AnalysisEngineDirectory::GetEngineDirectoryResult() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return result;
}
