///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 11:24)

#include "Database/DatabaseExport.h"

#include "AnalysisDatabaseConfiguration.h"
#include "Detail/AnalysisDatabaseConfigurationImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

Database::AnalysisDatabaseConfiguration::AnalysisDatabaseConfiguration(const string& fileName)
    : impl{ fileName }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Database, AnalysisDatabaseConfiguration)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Database, AnalysisDatabaseConfiguration, GetConfigurationStrategy, System::String, Database::ConfigurationStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, AnalysisDatabaseConfiguration, begin, Database::AnalysisDatabaseConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, AnalysisDatabaseConfiguration, end, Database::AnalysisDatabaseConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, AnalysisDatabaseConfiguration, GetSize, int)
