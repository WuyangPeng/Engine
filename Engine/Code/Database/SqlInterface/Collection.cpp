// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.2 (2019/07/03 10:07)

#include "Database/DatabaseExport.h"

#include "Collection.h"
#include "Detail/CollectionFactory.h"
#include "Detail/CollectionImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::string;

Database::Collection
	::Collection(const Schema& schema,const string& collectionName)
	: m_Impl{ CollectionFactory::Create(schema,collectionName) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
} 

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, Collection)

Database::Collection::DocResultPtr Database::Collection
	::ExecuteDoc(const string& findStatement, const BindStatementType& bindStatement, int limitStatement)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ExecuteDoc(findStatement, bindStatement, limitStatement);
}


