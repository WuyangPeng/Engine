///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/02 18:46)

#include "Database/DatabaseExport.h"

#include "CodeMappingAnalysis.h"
#include "Detail/CodeMappingAnalysisImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::CodeMappingAnalysis::CodeMappingAnalysis(const String& fileName)
    : impl{ fileName }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeMappingAnalysis)

System::String Database::CodeMappingAnalysis::GetElement(const String& codeKey) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetElement(codeKey);
}
