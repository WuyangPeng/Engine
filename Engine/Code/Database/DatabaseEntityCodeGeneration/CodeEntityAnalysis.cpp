/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:51)

#include "Database/DatabaseExport.h"

#include "CodeEntityAnalysis.h"
#include "Detail/CodeEntityAnalysisImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::CodeEntityAnalysis::CodeEntityAnalysis(const std::string& fileName)
    : impl{ fileName }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeEntityAnalysis)

System::String Database::CodeEntityAnalysis::GetNamespaceName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetNamespaceName();
}

Database::CodeEntityAnalysis::ContainerConstIter Database::CodeEntityAnalysis::begin() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetBegin();
}

Database::CodeEntityAnalysis::ContainerConstIter Database::CodeEntityAnalysis::end() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetEnd();
}
