///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 14:56)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_VALUE_H
#define CORE_TOOLS_TEXT_PARSING_CELL_VALUE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/TextParsing/Flags/CSVCondition.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>
#include <variant>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::CellValueImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::DelayCopyUnsharedImpl<CoreTools::SimpleCSV::CellValue, CoreTools::SimpleCSV::CellValueImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE CellValue final : public boost::totally_ordered<CellValue>
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(CellValue);

    public:
        NODISCARD static CellValue CreateDefault();
        NODISCARD static CellValue CreateError();

        explicit CellValue(bool value);
        explicit CellValue(int value);
        explicit CellValue(int64_t value);
        explicit CellValue(double value);
        explicit CellValue(const std::string& value);
        explicit CellValue(const char* value);

        CLASS_INVARIANT_DECLARE;

        template <typename T, std::enable_if_t<TextParsing::cellValueCondition<T>>* = nullptr>
        CellValue& operator=(T rhs);

        template <typename T, std::enable_if_t<std::is_same_v<T, CellValue> || TextParsing::cellValueCondition<T>>* = nullptr>
        void Set(T rhs) noexcept(std::is_same_v<T, CellValue>);

        template <typename T, std::enable_if_t<TextParsing::cellValueCondition<T>>* = nullptr>
        NODISCARD T Get() const;

        template <typename T, std::enable_if_t<TextParsing::cellValueCondition<T>>* = nullptr>
        NODISCARD explicit operator T() const;

        NODISCARD bool GetBool() const;
        NODISCARD int64_t GetIntegral() const;
        NODISCARD double GetDouble() const;
        NODISCARD std::string GetString() const;

        void Clear();
        void SetError();
        NODISCARD ValueType GetType() const noexcept;
        NODISCARD std::string GetTypeAsString() const;
        NODISCARD bool IsEqual(const CellValue& rhs) const noexcept;
        NODISCARD bool IsLess(const CellValue& rhs) const noexcept;

    private:
        explicit CellValue(DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };

    CORE_TOOLS_DEFAULT_DECLARE NODISCARD bool operator==(const CellValue& lhs, const CellValue& rhs) noexcept;
    CORE_TOOLS_DEFAULT_DECLARE NODISCARD bool operator<(const CellValue& lhs, const CellValue& rhs) noexcept;

    CORE_TOOLS_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const CellValue& value);
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_VALUE_H
