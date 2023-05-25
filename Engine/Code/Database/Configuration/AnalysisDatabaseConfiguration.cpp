///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 16:29)

#include "Database/DatabaseExport.h"

#include "AnalysisDatabaseConfiguration.h"
#include "Detail/AnalysisDatabaseConfigurationImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Database::AnalysisDatabaseConfiguration::AnalysisDatabaseConfiguration(const std::string& fileName)
    : impl{ fileName }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Database, AnalysisDatabaseConfiguration)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Database, AnalysisDatabaseConfiguration, GetConfigurationStrategy, System::String, Database::ConfigurationStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, AnalysisDatabaseConfiguration, begin, Database::AnalysisDatabaseConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, AnalysisDatabaseConfiguration, end, Database::AnalysisDatabaseConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, AnalysisDatabaseConfiguration, GetSize, int)
