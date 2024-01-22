/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:52)

#include "Database/DatabaseExport.h"

#include "AnalysisDatabaseConfiguration.h"
#include "Detail/AnalysisDatabaseConfigurationImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Database::AnalysisDatabaseConfiguration::AnalysisDatabaseConfiguration(const std::string& fileName)
    : impl{ fileName }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, AnalysisDatabaseConfiguration)

Database::ConfigurationStrategy Database::AnalysisDatabaseConfiguration::GetConfigurationStrategy(const String& name) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetConfigurationStrategy(name);
}

Database::AnalysisDatabaseConfiguration::ContainerConstIter Database::AnalysisDatabaseConfiguration::begin() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->begin();
}

Database::AnalysisDatabaseConfiguration::ContainerConstIter Database::AnalysisDatabaseConfiguration::end() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->end();
}

int Database::AnalysisDatabaseConfiguration::GetSize() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetSize();
}
