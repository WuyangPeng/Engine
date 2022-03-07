///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 14:02)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/ResultRow.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE ResultImpl
    {
    public:
        using ClassType = ResultImpl;
        using FactoryType = ResultFactory;
        using ResultRowUniquePtr = std::unique_ptr<ResultRow>;
        using ResultRowContainer = std::vector<ResultRowUniquePtr>;

    public:
        explicit ResultImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~ResultImpl() noexcept = default;
        ResultImpl(const ResultImpl& rhs) noexcept = default;
        ResultImpl& operator=(const ResultImpl& rhs) noexcept = default;
        ResultImpl(ResultImpl&& rhs) noexcept = default;
        ResultImpl& operator=(ResultImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ResultRowUniquePtr FetchOne();
        NODISCARD virtual ResultRowContainer FetchAll();
        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

    private:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H
