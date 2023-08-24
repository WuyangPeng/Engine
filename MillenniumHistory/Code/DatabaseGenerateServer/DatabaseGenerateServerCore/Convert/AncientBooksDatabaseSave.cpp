///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/07/31 21:57)

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreExport.h"

#include "AncientBooksDatabaseSave.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "Detail/AncientBooksDatabaseSaveImpl.h"

DatabaseGenerateServerCore::AncientBooksDatabaseSave::AncientBooksDatabaseSave(const DatabaseFlushSharedPtr& databaseFlush)
    : impl{ databaseFlush }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateServerCore, AncientBooksDatabaseSave)

void DatabaseGenerateServerCore::AncientBooksDatabaseSave::DatabaseSave(const AncientBooksContainer& ancientBooksContainer)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_9;

    return impl->DatabaseSave(ancientBooksContainer);
}