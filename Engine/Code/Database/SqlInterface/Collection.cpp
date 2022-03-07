///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 17:21)

#include "Database/DatabaseExport.h"

#include "Collection.h"
#include "Detail/CollectionFactory.h"
#include "Detail/CollectionImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

Database::Collection::Collection(const Schema& schema, const string& collectionName)
    : impl{ CoreTools::ImplCreateUseFactory::Default, schema, collectionName }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, Collection)

Database::Collection::ResultSharedPtr Database::Collection::ExecuteDoc(const string& findStatement, const BindStatementType& bindStatement, int limitStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->ExecuteDoc(findStatement, bindStatement, limitStatement);
}
