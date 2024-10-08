/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/23 09:30)

#include "Framework/FrameworkExport.h"

#include "SystemManagerImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/TextParsing/Json/JsonAnalysisManager.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

Framework::SystemManagerImpl::SystemManagerImpl(const EnvironmentDirectory& environmentDirectory)
    : environment{ Environment::Create() },
      globalConfig{ boost::polymorphic_pointer_cast<GlobalConfig>(JSON_ANALYSIS_MANAGER_SINGLETON.Create(CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetDirectory(UpperDirectory::Configuration)) + "Global.json",
                                                                                                         GlobalConfig::GetCurrentRttiType().GetName())) },
      smtpTransportAsynchronous{ environmentDirectory },
      databaseManager{ CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetEngineDirectory() + environmentDirectory.GetDirectory(UpperDirectory::Configuration)) + "Database.json" }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, SystemManagerImpl)

CoreTools::GlobalConfig Framework::SystemManagerImpl::GetGlobalConfig() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return *globalConfig;
}

void Framework::SystemManagerImpl::SendSmtpTransportMessage(const std::string& title, const std::string& content)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    smtpTransportAsynchronous.Registered(title, content);
}

void Framework::SystemManagerImpl::ChangeDatabase(const String& databaseIndex, int64_t userId, const BasisDatabaseManager& basisDatabaseContainer)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return databaseManager.ChangeDatabase(databaseIndex, userId, basisDatabaseContainer);
}

Database::BasisDatabaseManager Framework::SystemManagerImpl::SelectOne(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return databaseManager.SelectOne(databaseIndex, basisDatabaseContainer, fieldNameContainer);
}

Database::DatabaseManager::ResultContainer Framework::SystemManagerImpl::SelectAll(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return databaseManager.SelectAll(databaseIndex, basisDatabaseContainer, fieldNameContainer);
}
