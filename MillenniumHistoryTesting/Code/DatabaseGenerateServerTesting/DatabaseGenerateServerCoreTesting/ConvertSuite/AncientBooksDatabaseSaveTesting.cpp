///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/09 22:12)

#include "AncientBooksDatabaseSaveTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Article.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ArticleContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/AncientBooksDatabaseSave.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::AncientBooksDatabaseSaveTesting::AncientBooksDatabaseSaveTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, AncientBooksDatabaseSaveTesting)

void DatabaseGenerateServerCoreTesting::AncientBooksDatabaseSaveTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::AncientBooksDatabaseSave convertEntity{ databaseFlush };

    convertEntity.DatabaseSave(ancientBooksContainer);
}
