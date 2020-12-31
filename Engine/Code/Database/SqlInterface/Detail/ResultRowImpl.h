//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 9:50)

#ifndef DATABASE_SQL_INTERFACE_RESULT_DOC_ROW_IMPL_H
#define DATABASE_SQL_INTERFACE_RESULT_DOC_ROW_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"

#include <iosfwd>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE ResultRowImpl
    {
    public:
        using ClassType = ResultRowImpl;
        using ImplTypePtr = std::shared_ptr<ClassType>;

    public:
        explicit ResultRowImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~ResultRowImpl() noexcept = default;
        ResultRowImpl(const ResultRowImpl& rhs) = default;
        ResultRowImpl& operator=(const ResultRowImpl& rhs) = default;
        ResultRowImpl(ResultRowImpl&& rhs) noexcept = default;
        ResultRowImpl& operator=(ResultRowImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Print(std::ostream& os) const;

        [[nodiscard]] virtual int GetIntValue(int pos) const;
        [[nodiscard]] virtual uint32_t GetUIntValue(int pos) const;
        [[nodiscard]] virtual int64_t GetInt64Value(int pos) const;
        [[nodiscard]] virtual uint64_t GetUInt64Value(int pos) const;
        [[nodiscard]] virtual float GetFloatValue(int pos) const;
        [[nodiscard]] virtual double GetDoubleValue(int pos) const;
        [[nodiscard]] virtual bool GetBoolValue(int pos) const;
        [[nodiscard]] virtual std::string GetStringValue(int pos) const;
        [[nodiscard]] virtual std::wstring GetWStringValue(int pos) const;
        [[nodiscard]] virtual int GetColCount() const;

    public:
        ConfigurationStrategy m_ConfigurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_RESULT_DOC_ROW_IMPL_H
