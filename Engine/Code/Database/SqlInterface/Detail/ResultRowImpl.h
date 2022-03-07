///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 14:09)

#ifndef DATABASE_SQL_INTERFACE_RESULT_DOC_ROW_IMPL_H
#define DATABASE_SQL_INTERFACE_RESULT_DOC_ROW_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

#include <iosfwd>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE ResultRowImpl
    {
    public:
        using ClassType = ResultRowImpl;
        using FactoryType = ResultRowFactory;

    public:
        explicit ResultRowImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~ResultRowImpl() noexcept = default;
        ResultRowImpl(const ResultRowImpl& rhs) noexcept = default;
        ResultRowImpl& operator=(const ResultRowImpl& rhs) noexcept = default;
        ResultRowImpl(ResultRowImpl&& rhs) noexcept = default;
        ResultRowImpl& operator=(ResultRowImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Print(std::ostream& os) const = 0;

        NODISCARD virtual int GetIntValue(int pos) const;
        NODISCARD virtual uint32_t GetUIntValue(int pos) const;
        NODISCARD virtual int64_t GetInt64Value(int pos) const;
        NODISCARD virtual uint64_t GetUInt64Value(int pos) const;
        NODISCARD virtual float GetFloatValue(int pos) const;
        NODISCARD virtual double GetDoubleValue(int pos) const;
        NODISCARD virtual bool GetBoolValue(int pos) const;
        NODISCARD virtual std::string GetStringValue(int pos) const;
        NODISCARD virtual std::wstring GetWStringValue(int pos) const;
        NODISCARD virtual int GetColCount() const = 0;

    public:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_RESULT_DOC_ROW_IMPL_H
