/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 16:41)

#include "Helper.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/Tools.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIdManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCSV.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCode.h"

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
    read_json("Configuration/BatchConversion.json", mainTree);

    const auto input = mainTree.get(SYSTEM_TEXT("input"), System::String{});
    const auto codeInput = mainTree.get(SYSTEM_TEXT("codeInput"), System::String{});
    const auto csvOutput = mainTree.get(SYSTEM_TEXT("csvOutput"), System::String{});
    const auto codeOutput = mainTree.get(SYSTEM_TEXT("codeOutput"), System::String{});

    CoreTools::BatchConversionCSV(input, csvOutput);
    CoreTools::BatchConversionCode(csvOutput, codeInput, codeOutput);

    System::SystemPause();
}
