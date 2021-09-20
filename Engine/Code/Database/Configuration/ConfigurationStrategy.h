//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 20:26)

#ifndef DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_H
#define DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_H

#include "Database/DatabaseDll.h"

#include "Flags/ConfigurationStrategyFlags.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <map>
#include <string>
#include <vector>

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(ConfigurationStrategyImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE ConfigurationStrategy final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ConfigurationStrategy);
        using FlagsOption = std::vector<std::string>;
        using StringOption = std::map<std::string, std::string>;
        using BooleanOption = std::map<std::string, bool>;
        using IntOption = std::map<std::string, int>;
        using SSLOption = std::map<std::string, std::string>;
        using DBMapping = std::map<int, std::string>;

    public:
        ConfigurationStrategy(WrappersStrategy wrappersStrategy, const std::string& ip, int port,
                              const std::string& hostName, const std::string& userName, const std::string& password);
        ConfigurationStrategy(WrappersStrategy wrappersStrategy, const std::string& ip, int port,
                              const std::string& hostName, const std::string& userName, const std::string& password,
                              bool pooling, int poolMaxSize, int poolQueueTimeout, int poolMaxIdleTime,
                              const FlagsOption& flagsOption, const StringOption& stringOption, const BooleanOption& booleanOption,
                              const IntOption& intOption, const SSLOption& sslOption, const DBMapping& dbMapping);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] WrappersStrategy GetWrappersStrategy() const noexcept;

        [[nodiscard]] std::string GetIP() const;
        [[nodiscard]] int GetPort() const noexcept;
        [[nodiscard]] std::string GetDBHostName() const;
        [[nodiscard]] std::string GetDBUserName() const;
        [[nodiscard]] std::string GetDBPassword() const;
        [[nodiscard]] FlagsOption GetFlagsOption() const;
        [[nodiscard]] StringOption GetStringOptions() const;
        [[nodiscard]] BooleanOption GetBooleanOptions() const;
        [[nodiscard]] IntOption GetIntOptions() const;
        [[nodiscard]] SSLOption GetSSLOptions() const;
        [[nodiscard]] DBMapping GetDBMapping() const;
        [[nodiscard]] bool IsUseSSL() const noexcept;
        [[nodiscard]] std::string GetDBName(int dbIndex) const;

        [[nodiscard]] bool GetPooling() const noexcept;
        [[nodiscard]] int GetPoolMaxSize() const noexcept;
        [[nodiscard]] int GetPoolQueueTimeout() const noexcept;
        [[nodiscard]] int GetPoolMaxIdleTime() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_H
