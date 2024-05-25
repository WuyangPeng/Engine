/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 21:19)

#include "CodeMappingAnalysisTesting.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace CoreTools
{
    const auto nonExistentFileName = SYSTEM_TEXT("Resource/CSVEngineering/NonExistent.json");
    const auto csvEngineeringFileName = SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json");
    const auto key = SYSTEM_TEXT("IncludeEnum");
    const auto element = SYSTEM_TEXT("#include \"Flags/$EnumName$.h\"");
}

CoreTools::CodeMappingAnalysisTesting::CodeMappingAnalysisTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CodeMappingAnalysisTesting)

void CoreTools::CodeMappingAnalysisTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CodeMappingAnalysisTesting::MainTest()
{
    ASSERT_THROW_EXCEPTION_0(MultiByteGetElementFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiByteGetElementSuccessTest);
    ASSERT_THROW_EXCEPTION_0(WideCharGetElementFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharGetElementSuccessTest);
}

void CoreTools::CodeMappingAnalysisTesting::MultiByteGetElementFailTest()
{
    const CodeMappingAnalysis codeMappingAnalysis{ StringConversion::StandardConversionMultiByte(nonExistentFileName) };
}

void CoreTools::CodeMappingAnalysisTesting::MultiByteGetElementSuccessTest()
{
    const CodeMappingAnalysis codeMappingAnalysis{ StringConversion::StandardConversionMultiByte(csvEngineeringFileName) };
    ASSERT_EQUAL(codeMappingAnalysis.GetElement(key), element);
}

void CoreTools::CodeMappingAnalysisTesting::WideCharGetElementFailTest()
{
    const CodeMappingAnalysis codeMappingAnalysis{ StringConversion::StandardConversionWideChar(nonExistentFileName) };
}

void CoreTools::CodeMappingAnalysisTesting::WideCharGetElementSuccessTest()
{
    const CodeMappingAnalysis codeMappingAnalysis{ StringConversion::StandardConversionWideChar(csvEngineeringFileName) };
    ASSERT_EQUAL(codeMappingAnalysis.GetElement(key), element);
}
