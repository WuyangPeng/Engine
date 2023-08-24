///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/17 09:22)

#include "GenerateEngine.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateEngine.h"

GameTemplate::GenerateEngine ::GenerateEngine(std::string configurationFileName)
    : configurationFileName{ std::move(configurationFileName) }
{
    Generate();

    System::SystemPause();

    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(GameTemplate, GenerateEngine)

void GameTemplate::GenerateEngine ::Generate()
{
    using BasicTree = boost::property_tree::basic_ptree<System::String, System::String>;

    BasicTree mainTree{};
    read_json(configurationFileName, mainTree);

    const auto input = mainTree.get(SYSTEM_TEXT("input"), System::String{});
    const auto output = mainTree.get(SYSTEM_TEXT("output"), System::String{});

    const AssistTools::GenerateEngine generateEngine{ input, output };

    generateEngine.Generate();
}