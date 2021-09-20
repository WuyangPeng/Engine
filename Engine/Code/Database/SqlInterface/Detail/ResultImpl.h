//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 9:49)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/ResultRow.h"

namespace Database
{
    class ResultFactory;
    class DATABASE_HIDDEN_DECLARE ResultImpl
    {
    public:
        using ClassType = ResultImpl;
        using ImplTypePtr = std::shared_ptr<ClassType>;
        using ResultRowPtr = std::unique_ptr<ResultRow>;
        using ResultRowContainer = std::vector<ResultRowPtr>;
        using FactoryType = ResultFactory;

    public:
        explicit ResultImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~ResultImpl() noexcept = default;
        ResultImpl(const ResultImpl& rhs) = default;
        ResultImpl& operator=(const ResultImpl& rhs) = default;
        ResultImpl(ResultImpl&& rhs) noexcept = default;
        ResultImpl& operator=(ResultImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual ResultRowPtr FetchOne();
        [[nodiscard]] virtual ResultRowContainer FetchAll();
        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;

    private:
        ConfigurationStrategy m_ConfigurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H
