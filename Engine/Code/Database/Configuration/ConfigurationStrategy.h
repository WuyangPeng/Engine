// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:44)

#ifndef DATABASE_DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_H
#define DATABASE_DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_H

#include "Database/DatabaseDll.h"

#include "Flags/ConfigurationStrategyFlags.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <map>
#include <string>
#include <vector>

DATABASE_EXPORT_SHARED_PTR(ConfigurationStrategyImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE ConfigurationStrategy
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(ConfigurationStrategy);
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

        WrappersStrategy GetWrappersStrategy() const noexcept;

        std::string GetIP() const;
        int GetPort() const noexcept;
        std::string GetDBHostName() const;
        std::string GetDBUserName() const;
        std::string GetDBPassword() const;
        FlagsOption GetFlagsOption() const;
        StringOption GetStringOptions() const;
        BooleanOption GetBooleanOptions() const;
        IntOption GetIntOptions() const;
        SSLOption GetSSLOptions() const;
        DBMapping GetDBMapping() const;
        bool IsUseSSL() const noexcept;
        std::string GetDBName(int dbIndex) const;

        bool GetPooling() const noexcept;
        int GetPoolMaxSize() const noexcept;
        int GetPoolQueueTimeout() const noexcept;
        int GetPoolMaxIdleTime() const noexcept;

    private:
        IMPL_TYPE_DECLARE(ConfigurationStrategy);
    };
}

#endif  // DATABASE_DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_H
