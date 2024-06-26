///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 16:32)

#include "EntityHeaderFileGenerationTesting.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "CoreTools/FileManager/OFileStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityAnalysis.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityClass.h"
#include "Database/DatabaseEntityCodeGeneration/EntityHeaderFileGeneration.h"

Database::EntityHeaderFileGenerationTesting::EntityHeaderFileGenerationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, EntityHeaderFileGenerationTesting)

void Database::EntityHeaderFileGenerationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::EntityHeaderFileGenerationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CodeHeaderFileGenerationTest);
}

void Database::EntityHeaderFileGenerationTesting::CodeHeaderFileGenerationTest()
{
    const CodeEntityAnalysis codeEntityAnalysis{ "Configuration/DatabaseEntity.json" };
    const CoreTools::CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/DatabaseEntity/DatabaseEntity.json") };

    for (const auto& codeEntityClass : codeEntityAnalysis)
    {
        EntityHeaderFileGeneration entityHeaderFileGeneration{ SYSTEM_TEXT("Resource/DatabaseEntity/EntityH.txt"),
                                                               codeEntityAnalysis.GetNamespaceName(),
                                                               codeEntityClass,
                                                               codeMappingAnalysis };

        CoreTools::OFileStreamManager streamManager{ SYSTEM_TEXT("Resource/DatabaseEntity/") + codeEntityClass.GetEntityClassName() + SYSTEM_TEXT(".h"), false };
        streamManager.SetSimplifiedChinese();

        streamManager << entityHeaderFileGeneration.GetContent();
    }
}
