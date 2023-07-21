///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/02 18:26)

#include "Database/DatabaseExport.h"

#include "CodeMapping.h"
#include "Detail/CodeMappingImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Database, CodeMapping)

Database::CodeMapping Database::CodeMapping::Create()
{
    return CodeMapping{ CoreTools::DisableNotThrow::Disable };
}

Database::CodeMapping::CodeMapping(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeMapping)

void Database::CodeMapping::Insert(const String& codeKey, const String& element)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->Insert(codeKey, element);
}

System::String Database::CodeMapping::GetElement(const String& codeKey) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetElement(codeKey);
}
