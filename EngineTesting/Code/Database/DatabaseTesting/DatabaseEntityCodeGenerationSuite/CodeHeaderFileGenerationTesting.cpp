///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 16:32)

#include "CodeHeaderFileGenerationTesting.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "CoreTools/FileManager/OFileStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityAnalysis.h"
#include "Database/DatabaseEntityCodeGeneration/CodeHeaderFileGeneration.h"

Database::CodeHeaderFileGenerationTesting::CodeHeaderFileGenerationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, CodeHeaderFileGenerationTesting)

void Database::CodeHeaderFileGenerationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::CodeHeaderFileGenerationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CodeHeaderFileGenerationTest);
}

void Database::CodeHeaderFileGenerationTesting::CodeHeaderFileGenerationTest()
{
    const CodeEntityAnalysis codeEntityAnalysis{ "Configuration/DatabaseEntity.json" };
    const CoreTools::CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntity.json") };

    const CodeHeaderFileGeneration codeHeaderFileGeneration{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntity.txt"), codeEntityAnalysis, codeMappingAnalysis };

    CoreTools::OFileStreamManager streamManager{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntity.h"), false };
    streamManager.SetSimplifiedChinese();

    streamManager << codeHeaderFileGeneration.GetContent();
}
