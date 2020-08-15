// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/16 11:26)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/ResultRow.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE ResultImpl
    {
    public:
        using ClassType = ResultImpl;
        using ImplTypePtr = std::shared_ptr<ClassType>;
        using ResultRowPtr = std::unique_ptr<ResultRow>;
        using ResultRowContainer = std::vector<ResultRowPtr>;

    public:
        explicit ResultImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~ResultImpl();
        ResultImpl(const ResultImpl&) = default;
        ResultImpl& operator=(const ResultImpl&) = default;
        ResultImpl(ResultImpl&&) = default;
        ResultImpl& operator=(ResultImpl&&) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual ResultRowPtr FetchOne();
        virtual ResultRowContainer FetchAll();
        ConfigurationStrategy GetConfigurationStrategy() const noexcept;

    private:
        ConfigurationStrategy m_ConfigurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H
