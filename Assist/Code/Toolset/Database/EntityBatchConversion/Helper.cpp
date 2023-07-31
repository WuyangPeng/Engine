///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/04 21:57)

#include "Helper.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityAnalysis.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityClass.h"
#include "Database/DatabaseEntityCodeGeneration/CodeFwdHeaderFileGeneration.h"
#include "Database/DatabaseEntityCodeGeneration/CodeHeaderFileGeneration.h"
#include "Database/DatabaseEntityCodeGeneration/CodeMappingAnalysis.h"
#include "Database/DatabaseEntityCodeGeneration/EntityHeaderFileGeneration.h"
#include "Database/DatabaseEntityCodeGeneration/EntitySourceFileGeneration.h"

#include <iostream>

BatchConversion::Helper::Helper(int argc, char** argv)
{
    CoreTools::UniqueIdManager::Create(CoreTools::UniqueIdSelect::Max);

#ifndef TCRE_USE_GCC

    const std::locale chs{ "chs" };
    COUT.imbue(chs);
    CERR.imbue(chs);

#endif  // TCRE_USE_GCC

    System::UnusedFunction(argc, argv);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

BatchConversion::Helper::~Helper() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    CoreTools::UniqueIdManager::Destroy();
}

CLASS_INVARIANT_STUB_DEFINE(BatchConversion, Helper)

int BatchConversion::Helper::Run()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        Conversion();
    }
    EXCEPTION_ENTRY_POINT_CATCH

    return 0;
}

void BatchConversion::Helper::Conversion()
{
    using BasicTree = boost::property_tree::basic_ptree<System::String, System::String>;

    BasicTree mainTree{};
    read_json("Configuration/EntityBatchConversion.json", mainTree);

    const auto input = mainTree.get(SYSTEM_TEXT("input"), System::String{});
    const auto codeOutput = mainTree.get(SYSTEM_TEXT("codeOutput"), System::String{});

    Database::CodeEntityAnalysis codeEntityAnalysis{ CoreTools::StringConversion::StandardConversionMultiByte(input) };
    Database::CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntity.json") };

    {
        Database::CodeFwdHeaderFileGeneration codeFwdHeaderFileGeneration{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntityFwd.txt"), codeEntityAnalysis, codeMappingAnalysis };

        if (const auto result = GetContent(codeOutput + SYSTEM_TEXT("/") + codeEntityAnalysis.GetNamespaceName() + SYSTEM_TEXT("Fwd.h"));
            result != codeFwdHeaderFileGeneration.GetContent())
        {
            CoreTools::OFStreamManager streamManager{ codeOutput + SYSTEM_TEXT("/") + codeEntityAnalysis.GetNamespaceName() + SYSTEM_TEXT("Fwd.h"), false };
            streamManager.SetSimplifiedChinese();

            streamManager << codeFwdHeaderFileGeneration.GetContent();
        }
    }

    {
        Database::CodeHeaderFileGeneration codeHeaderFileGeneration{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntity.txt"), codeEntityAnalysis, codeMappingAnalysis };

        if (const auto result = GetContent(codeOutput + SYSTEM_TEXT("/") + codeEntityAnalysis.GetNamespaceName() + SYSTEM_TEXT(".h"));
            result != codeHeaderFileGeneration.GetContent())
        {
            CoreTools::OFStreamManager streamManager{ codeOutput + SYSTEM_TEXT("/") + codeEntityAnalysis.GetNamespaceName() + SYSTEM_TEXT(".h"), false };
            streamManager.SetSimplifiedChinese();

            streamManager << codeHeaderFileGeneration.GetContent();
        }
    }

    {
        for (const auto& codeEntityClass : codeEntityAnalysis)
        {
            Database::EntityHeaderFileGeneration entityHeaderFileGeneration{ SYSTEM_TEXT("Resource/DatabaseEntity/EntityH.txt"),
                                                                             codeEntityAnalysis.GetNamespaceName(),
                                                                             codeEntityClass,
                                                                             codeMappingAnalysis };

            if (const auto result = GetContent(codeOutput + SYSTEM_TEXT("/") + codeEntityClass.GetEntityClassName() + SYSTEM_TEXT(".h"));
                result != entityHeaderFileGeneration.GetContent())
            {
                CoreTools::OFStreamManager streamManager{ codeOutput + SYSTEM_TEXT("/") + codeEntityClass.GetEntityClassName() + SYSTEM_TEXT(".h"), false };
                streamManager.SetSimplifiedChinese();

                streamManager << entityHeaderFileGeneration.GetContent();
            }
        }
    }

    {
        for (const auto& codeEntityClass : codeEntityAnalysis)
        {
            Database::EntitySourceFileGeneration entitySourceFileGeneration{ SYSTEM_TEXT("Resource/DatabaseEntity/EntityCpp.txt"),
                                                                             codeEntityAnalysis.GetNamespaceName(),
                                                                             codeEntityClass,
                                                                             codeMappingAnalysis };
            if (const auto result = GetContent(codeOutput + SYSTEM_TEXT("/") + codeEntityClass.GetEntityClassName() + SYSTEM_TEXT(".cpp"));
                result != entitySourceFileGeneration.GetContent())
            {
                CoreTools::OFStreamManager streamManager{ codeOutput + SYSTEM_TEXT("/") + codeEntityClass.GetEntityClassName() + SYSTEM_TEXT(".cpp"), false };
                streamManager.SetSimplifiedChinese();

                streamManager << entitySourceFileGeneration.GetContent();
            }
        }
    }
}

System::String BatchConversion::Helper::GetContent(const String& fileName)
{
    CoreTools::IFStreamManager streamManager{ fileName };
    streamManager.SetSimplifiedChinese();

    return streamManager.GetFileContent();
}
