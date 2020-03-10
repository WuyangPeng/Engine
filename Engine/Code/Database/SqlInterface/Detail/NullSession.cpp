// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 10:03)

#include "Database/DatabaseExport.h"

#include "NullSession.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::make_shared;

Database::NullSession
	::NullSession(const ConfigurationStrategy& configurationStrategy)
	: ParentType{ configurationStrategy }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::NullSession
	::~NullSession()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, NullSession)



