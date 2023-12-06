/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:50)

#include "AncientBooksDatabaseSaveTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Article.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ArticleContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/AncientBooksDatabaseSave.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::AncientBooksDatabaseSaveTesting::AncientBooksDatabaseSaveTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, AncientBooksDatabaseSaveTesting)

void DatabaseGenerateCoreTesting::AncientBooksDatabaseSaveTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::AncientBooksDatabaseSave convertEntity{ databaseFlush };

    convertEntity.DatabaseSave(ancientBooksContainer);
}
