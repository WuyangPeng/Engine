///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 15:18)

#include "Framework/FrameworkExport.h"

#include "AnalysisEngineDirectory.h"
#include "DirectoryDefaultName.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using std::exception;
using std::string;

Framework::AnalysisEngineDirectory::AnalysisEngineDirectory(const string& jsonName)
    : basicTree{}, resourceTree{}, configurationTree{}, result{}
{
    if (!jsonName.empty())
    {
        Analysis(jsonName);
    }

    result.SetDefaultDirectory();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Framework::AnalysisEngineDirectory::Analysis(const string& jsonName)
{
    EXCEPTION_TRY
    {
        read_json(jsonName, basicTree);
        AnalysisBase();
        AnalysisRendering();
    }
    EXCEPTION_STD_EXCEPTION_CATCH(Framework)
}

// private
void Framework::AnalysisEngineDirectory::AnalysisBase()
{
    for (auto index = AnalysisDirectory::Resource; index <= AnalysisDirectory::Configuration; ++index)
    {
        InsertResult(RenderingDirectory::Null, index);
    }
}

// private
void Framework::AnalysisEngineDirectory::AnalysisRendering()
{
    for (auto index = RenderingDirectory::Default; index <= RenderingDirectory::DirectX; ++index)
    {
        AnalysisRendering(index);
    }
}

// private
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

// private
void Framework::AnalysisEngineDirectory::AnalysisRendering(RenderingDirectory renderingDirectory, const BasicTree& renderingTree)
{
    for (auto index = AnalysisDirectory::LittleEndian; index <= AnalysisDirectory::Image; ++index)
    {
        InsertResult(renderingDirectory, index, renderingTree);
    }
}

// private
void Framework::AnalysisEngineDirectory::InsertResult(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory)
{
    InsertResult(renderingDirectory, analysisDirectory, basicTree);
}

// private
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
