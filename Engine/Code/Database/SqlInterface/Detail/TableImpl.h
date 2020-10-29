//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 9:54)

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
        virtual ~TableImpl() noexcept = default;
        TableImpl(const TableImpl& rhs) = default;
        TableImpl& operator=(const TableImpl& rhs) = default;
        TableImpl(TableImpl&& rhs) noexcept = default;
        TableImpl& operator=(TableImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        [[nodiscard]] virtual ResultPtr Select(std::initializer_list<std::string> selectStatement, const std::string& whereStatement,
                                               const std::string& orderByStatement, const BindStatementType& bindStatement);

    public:
        ConfigurationStrategy m_ConfigurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_TABLE_IMPL_H
