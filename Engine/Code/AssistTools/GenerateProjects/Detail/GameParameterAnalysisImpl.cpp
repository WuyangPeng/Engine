///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 11:02)

#include "AssistTools/AssistToolsExport.h"

#include "GameParameterAnalysisImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AssistTools::GameParameterAnalysisImpl::GameParameterAnalysisImpl(const std::string& fileName)
    : fileName{ fileName },
      mainTree{},
      coreName{},
      coreCapital{},
      projectChineseName{},
      projectDescribeName{},
      projectName{},
      projectCapital{},
      projectAbbreviation{},
      endYear{},
      version{},
      versionNum{},
      gameModule{},
      middleLayer{}
{
    Analysis();

    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

void AssistTools::GameParameterAnalysisImpl::Analysis()
{
    AnalysisJson();
    AnalysisMain();
}

void AssistTools::GameParameterAnalysisImpl::AnalysisJson()
{
    if (System::IFileStream fileStream{ CoreTools::StringConversion::MultiByteConversionStandard(fileName) };
        fileStream)
    {
        const std::locale chs{ "chs" };
        fileStream.imbue(chs);

        read_json(fileStream, mainTree);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件：") + CoreTools::StringConversion::MultiByteConversionStandard(fileName) + SYSTEM_TEXT("不存在"))
    }
}

void AssistTools::GameParameterAnalysisImpl::AnalysisMain()
{
    coreName = mainTree.get(SYSTEM_TEXT("CoreName"), SYSTEM_TEXT("Core"));
    coreCapital = mainTree.get(SYSTEM_TEXT("CoreCapital"), SYSTEM_TEXT("CORE"));
    projectChineseName = mainTree.get(SYSTEM_TEXT("ProjectChineseName"), String{});
    projectDescribeName = mainTree.get(SYSTEM_TEXT("ProjectDescribeName"), String{});
    projectName = mainTree.get(SYSTEM_TEXT("ProjectName"), String{});
    projectCapital = mainTree.get(SYSTEM_TEXT("ProjectCapital"), String{});
    projectAbbreviation = mainTree.get(SYSTEM_TEXT("ProjectAbbreviation"), String{});
    endYear = mainTree.get(SYSTEM_TEXT("EndYear"), SYSTEM_TEXT("2023"));
    version = mainTree.get(SYSTEM_TEXT("Version"), CoreTools::StringConversion ::MultiByteConversionStandard(CoreTools::Version::GetVersion()));
    versionNum = mainTree.get(SYSTEM_TEXT("VersionNum"), System::ToString(CoreTools::Version::GetTCREFullVersion()));

    for (const auto& tree : mainTree.get_child(SYSTEM_TEXT("Module")))
    {
        EXCEPTION_TRY
        {
            InsertModule(tree.first, tree.second);
        }
        EXCEPTION_ENGINE_EXCEPTION_CATCH(AssistTools)
    }

    for (const auto& tree : mainTree.get_child(SYSTEM_TEXT("MiddleLayer")))
    {
        EXCEPTION_TRY
        {
            InsertMiddleLayer(tree.first, tree.second);
        }
        EXCEPTION_ENGINE_EXCEPTION_CATCH(AssistTools)
    }
}

void AssistTools::GameParameterAnalysisImpl::InsertModule(const String& moduleName, const BasicTree& basicTree)
{
    const auto chineseName = basicTree.get(SYSTEM_TEXT("ChineseName"), String{});
    const auto isClient = basicTree.get(SYSTEM_TEXT("IsClient"), false);
    const auto uppercase = basicTree.get(SYSTEM_TEXT("Uppercase"), String{});

    gameModule.emplace_back(moduleName, chineseName, isClient, uppercase);
}

void AssistTools::GameParameterAnalysisImpl::InsertMiddleLayer(const String& middleLayerName, const BasicTree& basicTree)
{
    const auto uppercase = basicTree.get(SYSTEM_TEXT("Uppercase"), String{});
    const auto isManager = basicTree.get(SYSTEM_TEXT("IsManager"), false);

    middleLayer.emplace_back(middleLayerName, uppercase, isManager);
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GameParameterAnalysisImpl)

int AssistTools::GameParameterAnalysisImpl::GetModuleCount() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(gameModule.size());
}

AssistTools::GameParameterAnalysisImpl::GameModuleContainerConstIter AssistTools::GameParameterAnalysisImpl::GetModuleBegin() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return gameModule.cbegin();
}

AssistTools::GameParameterAnalysisImpl::GameModuleContainerConstIter AssistTools::GameParameterAnalysisImpl::GetModuleEnd() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return gameModule.cend();
}

AssistTools::GameParameterAnalysisImpl::MiddleLayerContainerConstIter AssistTools::GameParameterAnalysisImpl::GetMiddleLayerBegin() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return middleLayer.cbegin();
}

AssistTools::GameParameterAnalysisImpl::MiddleLayerContainerConstIter AssistTools::GameParameterAnalysisImpl::GetMiddleLayerEnd() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return middleLayer.cend();
}

System::String AssistTools::GameParameterAnalysisImpl::GetCoreName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return coreName;
}

System::String AssistTools::GameParameterAnalysisImpl::GetCoreCapital() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return coreCapital;
}

System::String AssistTools::GameParameterAnalysisImpl::GetProjectChineseName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return projectChineseName;
}

System::String AssistTools::GameParameterAnalysisImpl::GetProjectDescribeName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return projectDescribeName;
}

System::String AssistTools::GameParameterAnalysisImpl::GetProjectName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return projectName;
}

System::String AssistTools::GameParameterAnalysisImpl::GetProjectCapital() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return projectCapital;
}

System::String AssistTools::GameParameterAnalysisImpl::GetProjectAbbreviation() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return projectAbbreviation;
}

System::String AssistTools::GameParameterAnalysisImpl::GetEndYear() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return endYear;
}

System::String AssistTools::GameParameterAnalysisImpl::GetVersion() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return version;
}

AssistTools::GameParameterAnalysisImpl::String AssistTools::GameParameterAnalysisImpl::GetVersionNum() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return versionNum;
}
