///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 17:41)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <any>
#include <memory>
#include <string>
#include <vector>

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(BasisDatabaseImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE BasisDatabase
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(BasisDatabase);
        using ByteArray = std::vector<uint8_t>;
        using ObjectSharedPtr = std::shared_ptr<BasisDatabase>;
        using ObjectArray = std::vector<ObjectSharedPtr>;
        using StringArray = std::vector<std::string>;
        using Int32Array = std::vector<int32_t>;
        using Int64Array = std::vector<int64_t>;
        using DoubleArray = std::vector<double>;

    public:
        explicit BasisDatabase(const std::string_view& fieldName);
        BasisDatabase(const std::string_view& fieldName, const std::string& value);
        BasisDatabase(const std::string_view& fieldName, int32_t value);
        BasisDatabase(const std::string_view& fieldName, int64_t value);
        BasisDatabase(const std::string_view& fieldName, uint64_t value);
        BasisDatabase(const std::string_view& fieldName, const ByteArray& value);
        BasisDatabase(const std::string_view& fieldName, bool value);
        BasisDatabase(const std::string_view& fieldName, const ObjectSharedPtr& value);
        BasisDatabase(const std::string_view& fieldName, const ObjectArray& value);

        BasisDatabase(const std::string_view& fieldName, const StringArray& value);
        BasisDatabase(const std::string_view& fieldName, const Int32Array& value);
        BasisDatabase(const std::string_view& fieldName, const Int64Array& value);
        BasisDatabase(const std::string_view& fieldName, const DoubleArray& value);

        template <typename T>
        requires(std::is_integral_v<T>)
        BasisDatabase(const std::string_view& fieldName, T value);

        template <typename T>
        requires(std::is_floating_point_v<T>)
        BasisDatabase(const std::string_view& fieldName, T value);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string_view GetFieldName() const noexcept;
        NODISCARD DataType GetDataType() const noexcept;

        template <DataType Type>
        NODISCARD typename DataTypeTraits<Type>::Type GetValue() const;

        template <DataType Type>
        NODISCARD std::string GetArrayStringValue() const;

        NODISCARD std::any GetAnyValue() const;

        NODISCARD std::string GetSqlFieldString() const;
        NODISCARD std::string GetString() const;
        NODISCARD std::string GetQuotationMarkString() const;

    private:
        BasisDatabase(const std::string_view& fieldName, DataType dataType, const std::any& value);

    private:
        PackageType impl;
    };

}
#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_H