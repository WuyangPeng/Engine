/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:00)

#include "AssistTools/AssistToolsExport.h"

#include "CodeModuleTestingGenerate.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/Replace.h"
#include "AssistTools/GenerateProjects/Using/GenerateEngineUsing.h"

AssistTools::CodeModuleTestingGenerate::CodeModuleTestingGenerate(const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, GenerateDirectory generateDirectory) noexcept
    : ParentType{ gameParameterAnalysis, codeMappingAnalysis },
      generateDirectory{ std::move(generateDirectory) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, CodeModuleTestingGenerate)

void AssistTools::CodeModuleTestingGenerate::GenerateModule(const GameModule& gameModule)
{
    const auto directory = generateDirectory.GetGenerateDirectory(moduleDescribe, gameModule.GetModuleName() + testingDescribe.data());
    directory.CreateFileDirectory();

    const ReplaceContainer replace{ Replace{ moduleNameDescribe, gameModule.GetModuleName() },
                                    Replace{ moduleUppercaseDescribe, gameModule.GetUppercaseName() },
                                    Replace{ moduleChineseNameDescribe, gameModule.GetChineseName() } };

    GenerateCodeModule(gameModule, replace, directory, moduleCoreDescribe, coreTestingDescribe);
    GenerateCodeModule(gameModule, replace, directory, moduleMiddleLayerDescribe, middleLayerTestingDescribe);
    GenerateCodeModule(gameModule, replace, directory, moduleDescribe, testingDescribe);
}

void AssistTools::CodeModuleTestingGenerate::GenerateCodeModule(const GameModule& gameModule, const ReplaceContainer& replace, const GenerateDirectory& directory, const StringView& describe, const StringView& suffix)
{
    const auto nextDirectory = directory.GetGenerateDirectory(describe, gameModule.GetModuleName() + suffix.data());
    nextDirectory.CreateFileDirectory();

    GenerateByContent(replace, nextDirectory);
}

void AssistTools::CodeModuleTestingGenerate::GenerateByContent(const ReplaceContainer& replace, const GenerateDirectory& directory)
{
    GenerateFile::GenerateByContent(directory, GetContent(directory.GetInputDirectory(), SYSTEM_TEXT("TestingH")), SYSTEM_TEXT("Testing.h"), replace);
    GenerateFile::GenerateByContent(directory, GetContent(directory.GetInputDirectory(), SYSTEM_TEXT("TestingHelperCpp")), SYSTEM_TEXT("TestingHelper.cpp"), replace);
    GenerateFile::GenerateByContent(directory, GetContent(directory.GetInputDirectory(), SYSTEM_TEXT("TestingHelperH")), SYSTEM_TEXT("TestingHelper.h"), replace);
    GenerateFile::GenerateByContent(directory, GetContent(directory.GetInputDirectory(), SYSTEM_TEXT("TestingLibCpp")), SYSTEM_TEXT("TestingLib.cpp"), replace);
    GenerateFile::GenerateByContent(directory, GetContent(directory.GetInputDirectory(), SYSTEM_TEXT("TestingMainCpp")), SYSTEM_TEXT("TestingMain.cpp"), replace);
}
