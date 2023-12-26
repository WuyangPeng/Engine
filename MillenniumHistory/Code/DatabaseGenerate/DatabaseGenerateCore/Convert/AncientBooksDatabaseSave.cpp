/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/28 22:29)

#include "DatabaseGenerate/DatabaseGenerateCore/DatabaseGenerateCoreExport.h"

#include "AncientBooksDatabaseSave.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "Detail/AncientBooksDatabaseSaveImpl.h"

DatabaseGenerateCore::AncientBooksDatabaseSave::AncientBooksDatabaseSave(const DatabaseFlushSharedPtr& databaseFlush)
    : impl{ databaseFlush }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateCore, AncientBooksDatabaseSave)

void DatabaseGenerateCore::AncientBooksDatabaseSave::DatabaseSave(const AncientBooksContainer& ancientBooksContainer)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_9;

    return impl->DatabaseSave(ancientBooksContainer);
}