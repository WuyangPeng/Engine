///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/02 18:01)

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