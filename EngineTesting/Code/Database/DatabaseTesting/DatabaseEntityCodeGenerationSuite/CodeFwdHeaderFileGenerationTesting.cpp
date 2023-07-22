///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/02 20:52)

#include "CodeFwdHeaderFileGenerationTesting.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityAnalysis.h"
#include "Database/DatabaseEntityCodeGeneration/CodeFwdHeaderFileGeneration.h"
#include "Database/DatabaseEntityCodeGeneration/CodeMappingAnalysis.h"

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
    CodeEntityAnalysis codeEntityAnalysis{ "Configuration/DatabaseEntity.json" };
    CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntity.json") };

    CodeFwdHeaderFileGeneration codeFwdHeaderFileGeneration{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntityFwd.txt"), codeEntityAnalysis, codeMappingAnalysis };

    CoreTools::OFStreamManager streamManager{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntityFwd.h"), false };
    streamManager.SetSimplifiedChinese();

    streamManager << codeFwdHeaderFileGeneration.GetContent();
}