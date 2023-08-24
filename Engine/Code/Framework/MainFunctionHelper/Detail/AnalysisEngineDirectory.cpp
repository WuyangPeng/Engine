///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:50)

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
    if (!jsonName.empty())
    {
        Analysis(jsonName);
    }

    result.SetDefaultDirectory();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

void Framework::AnalysisEngineDirectory::Analysis(const std::string& jsonName)
{
    EXCEPTION_TRY
    {
        read_json(jsonName, basicTree);
        AnalysisBase();
        AnalysisRendering();
    }
    EXCEPTION_STD_EXCEPTION_CATCH(Framework)
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
        const auto analysisDirectory = System::EnumCastUnderlying<AnalysisDirectory>(renderingDirectory);
        const auto renderingTree = basicTree.get_child(DirectoryDefaultName::GetDefaultKeyName(analysisDirectory));

        AnalysisRendering(renderingDirectory, renderingTree);
    }
    EXCEPTION_STD_EXCEPTION_CATCH(Framework)
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
