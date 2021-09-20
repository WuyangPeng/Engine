//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 10:42)

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
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Database, Collection)

Database::Collection::DocResultPtr Database::Collection::ExecuteDoc(const string& findStatement, const BindStatementType& bindStatement, int limitStatement)
{
    

    return impl->ExecuteDoc(findStatement, bindStatement, limitStatement);
}
