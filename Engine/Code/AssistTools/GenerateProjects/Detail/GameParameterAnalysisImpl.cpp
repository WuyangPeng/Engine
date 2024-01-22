/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:59)

#include "AssistTools/AssistToolsExport.h"

#include "GameParameterAnalysisImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Time/Year.h"
#include "AssistTools/GenerateProjects/Flags/GameParameterType.h"
#include "AssistTools/GenerateProjects/Flags/ProjectServiceType.h"
#include "AssistTools/GenerateProjects/Using/GameParameterUsing.h"

AssistTools::GameParameterAnalysisImpl::GameParameterAnalysisImpl(std::string fileName)
    : fileName{ std::move(fileName) },
      mainTree{},
      gameParameter{},
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
    read_json(fileName, mainTree);
}

void AssistTools::GameParameterAnalysisImpl::AnalysisMain()
{
    AnalysisGameParameter();
    AnalysisModule();
    AnalysisMiddleLayer();
}

void AssistTools::GameParameterAnalysisImpl::AnalysisGameParameter()
{
    for (const auto& element : GetGameParameterContainer())
    {
        gameParameter.emplace(element.GetGameParameterType(), CoreTools::StringConversion::Utf8ConversionStandard(mainTree.get(element.GetKeyName(), element.GetDefaultValue())));
    }
}

void AssistTools::GameParameterAnalysisImpl::AnalysisModule()
{
    for (const auto& [moduleName, basicTree] : mainTree.get_child(moduleKey.data()))
    {
        AnalysisModule(moduleName, basicTree);
    }
}

void AssistTools::GameParameterAnalysisImpl::AnalysisModule(const std::string& moduleName, const BasicTree& basicTree)
{
    EXCEPTION_TRY
    {
        InsertModule(moduleName, basicTree);
    }
    EXCEPTION_ENGINE_EXCEPTION_CATCH(AssistTools)
}

void AssistTools::GameParameterAnalysisImpl::InsertModule(const std::string& moduleName, const BasicTree& basicTree)
{
    const auto chineseName = CoreTools::StringConversion::Utf8ConversionStandard(basicTree.get(chineseNameKey.data(), ""));
    const auto projectServiceType = System::UnderlyingCastEnum<ProjectServiceType>(basicTree.get(projectServiceTypeKey.data(), System::EnumCastUnderlying(ProjectServiceType::Tools)));
    const auto uppercase = CoreTools::StringConversion::Utf8ConversionStandard(basicTree.get(uppercaseKey.data(), ""));

    GameModule::GuidContainer guid{};
    auto index = 0;
    for (auto& element : guid)
    {
        element = CoreTools::StringConversion::Utf8ConversionStandard(basicTree.get(guidKey.data() + std::to_string(index), ""));

        ++index;
    }

    gameModule.emplace_back(CoreTools::StringConversion::Utf8ConversionStandard(moduleName), chineseName, projectServiceType, uppercase, guid);
}

void AssistTools::GameParameterAnalysisImpl::AnalysisMiddleLayer()
{
    for (const auto& [middleLayerName, basicTree] : mainTree.get_child(middleLayerKey.data()))
    {
        AnalysisMiddleLayer(middleLayerName, basicTree);
    }
}

void AssistTools::GameParameterAnalysisImpl::AnalysisMiddleLayer(const std::string& middleLayerName, const BasicTree& basicTree)
{
    EXCEPTION_TRY
    {
        InsertMiddleLayer(middleLayerName, basicTree);
    }
    EXCEPTION_ENGINE_EXCEPTION_CATCH(AssistTools)
}

void AssistTools::GameParameterAnalysisImpl::InsertMiddleLayer(const std::string& middleLayerName, const BasicTree& basicTree)
{
    const auto uppercase = CoreTools::StringConversion::Utf8ConversionStandard(basicTree.get(uppercaseKey.data(), ""));
    const auto isManager = basicTree.get(isManagerKey.data(), false);

    middleLayer.emplace_back(CoreTools::StringConversion::Utf8ConversionStandard(middleLayerName), uppercase, isManager);
}

const AssistTools::GameParameterAnalysisImpl::GameParameterContainer& AssistTools::GameParameterAnalysisImpl::GetGameParameterContainer()
{
    static GameParameterContainer gameParameterContainer{ GameParameter{ GameParameterType::CoreName, "Core" },
                                                          GameParameter{ GameParameterType::CoreCapital, "CORE" },
                                                          GameParameter{ GameParameterType::ProjectChineseName },
                                                          GameParameter{ GameParameterType::ProjectDescribeName },
                                                          GameParameter{ GameParameterType::ProjectName },
                                                          GameParameter{ GameParameterType::ProjectCapital },
                                                          GameParameter{ GameParameterType::ProjectAbbreviation },
                                                          GameParameter{ GameParameterType::EndYear, std::to_string(CoreTools::Year::GetCurrentYear()) },
                                                          GameParameter{ GameParameterType::Version, CoreTools::Version::GetVersion() },
                                                          GameParameter{ GameParameterType::VersionNum, std::to_string(CoreTools::Version::GetTCREFullVersion()) },
                                                          GameParameter{ GameParameterType::TestingName } };

    return gameParameterContainer;
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

bool AssistTools::GameParameterAnalysisImpl::HasTools() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    for (const auto& element : gameModule)
    {
        if (element.GetProjectServiceType() == ProjectServiceType::Tools)
        {
            return true;
        }
    }

    return false;
}

AssistTools::GameParameterAnalysisImpl::String AssistTools::GameParameterAnalysisImpl::GetGameParameter(GameParameterType gameParameterType) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    if (const auto iter = gameParameter.find(gameParameterType);
        iter != gameParameter.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应参数，GameParameterType = ") + System::ToString(gameParameterType))
    }
}
