/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/23 09:19)

#ifndef FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/EngineConfiguration/GlobalConfig.h"
#include "CoreTools/FileManager/Environment.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseManager.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"
#include "Framework/Smtp/Detail/SmtpTransportAsynchronous.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE SystemManagerImpl
    {
    public:
        using ClassType = SystemManagerImpl;

        using String = System::String;
        using Environment = CoreTools::Environment;
        using GlobalConfig = CoreTools::GlobalConfig;
        using DisableNotThrow = CoreTools::DisableNotThrow;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using ResultContainer = Database::DatabaseManager::ResultContainer;
        using FieldNameContainer = Database::DatabaseManager::FieldNameContainer;

    public:
        explicit SystemManagerImpl(const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD GlobalConfig GetGlobalConfig() const;

        void SendSmtpTransportMessage(const std::string& title, const std::string& content);

        void ChangeDatabase(const String& databaseIndex, int64_t userId, const BasisDatabaseManager& basisDatabaseContainer);

        NODISCARD BasisDatabaseManager SelectOne(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const;
        NODISCARD ResultContainer SelectAll(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const;

    private:
        using GlobalConfigSharedPtr = std::shared_ptr<GlobalConfig>;
        using DatabaseManager = Database::DatabaseManager;

    private:
        // 支持访问环境变量和路径。
        Environment environment;

        GlobalConfigSharedPtr globalConfig;
        SmtpTransportAsynchronous smtpTransportAsynchronous;
        DatabaseManager databaseManager;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_IMPL_H
