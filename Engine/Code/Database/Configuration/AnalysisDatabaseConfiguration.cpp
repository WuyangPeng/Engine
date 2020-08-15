// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:07)

#include "Database/DatabaseExport.h" 

#include "AnalysisDatabaseConfiguration.h"
#include "Detail/AnalysisDatabaseConfigurationImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::string;
using std::make_shared;

Database::AnalysisDatabaseConfiguration
	::AnalysisDatabaseConfiguration(const string& fileName)
	:m_Impl{ make_shared<ImplType>(fileName) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, AnalysisDatabaseConfiguration)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Database, AnalysisDatabaseConfiguration, GetConfigurationStrategy, System::String, Database::ConfigurationStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, AnalysisDatabaseConfiguration, GetBegin, Database::AnalysisDatabaseConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, AnalysisDatabaseConfiguration, GetEnd, Database::AnalysisDatabaseConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, AnalysisDatabaseConfiguration, GetSize, int)
