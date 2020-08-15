// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:28)

#ifndef DATABASE_SQL_INTERFACE_TABLE_IMPL_H
#define DATABASE_SQL_INTERFACE_TABLE_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Result.h"

#include <map>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE TableImpl
    {
    public:
        using ClassType = TableImpl;
        using ImplTypePtr = std::shared_ptr<ClassType>;
        using ResultPtr = std::shared_ptr<Result>;
        using BindStatementType = std::map<std::string, std::string>;

    public:
        explicit TableImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~TableImpl();
        TableImpl(const TableImpl&) = default;
        TableImpl& operator=(const TableImpl&) = default;
        TableImpl(TableImpl&&) = default;
        TableImpl& operator=(TableImpl&&) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        virtual ResultPtr Select(std::initializer_list<std::string> selectStatement, const std::string& whereStatement,
                                 const std::string& orderByStatement, const BindStatementType& bindStatement);

    public:
        ConfigurationStrategy m_ConfigurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_TABLE_IMPL_H
