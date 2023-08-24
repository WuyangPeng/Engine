///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 16:31)

#include "CodeFwdHeaderFileGenerationTesting.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityAnalysis.h"
#include "Database/DatabaseEntityCodeGeneration/CodeFwdHeaderFileGeneration.h"

Database::CodeFwdHeaderFileGenerationTesting::CodeFwdHeaderFileGenerationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, CodeFwdHeaderFileGenerationTesting)

void Database::CodeFwdHeaderFileGenerationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::CodeFwdHeaderFileGenerationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CodeFwdHeaderFileGenerationTest);
}

void Database::CodeFwdHeaderFileGenerationTesting::CodeFwdHeaderFileGenerationTest()
{
    const CodeEntityAnalysis codeEntityAnalysis{ "Configuration/DatabaseEntity.json" };
    const CoreTools::CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntity.json") };

    const CodeFwdHeaderFileGeneration codeFwdHeaderFileGeneration{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntityFwd.txt"), codeEntityAnalysis, codeMappingAnalysis };

    CoreTools::OFStreamManager streamManager{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntityFwd.h"), false };
    streamManager.SetSimplifiedChinese();

    streamManager << codeFwdHeaderFileGeneration.GetContent();
}
