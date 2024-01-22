/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:46)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_VALUE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_VALUE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/Flags/CSVCondition.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <string>
#include <variant>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE CellValueImpl final
    {
    public:
        using ClassType = CellValueImpl;

    public:
        CellValueImpl() noexcept;
        explicit CellValueImpl(bool value) noexcept;
        explicit CellValueImpl(int64_t value) noexcept;
        explicit CellValueImpl(int value) noexcept;
        explicit CellValueImpl(double value) noexcept;
        explicit CellValueImpl(const std::string& value);

        CLASS_INVARIANT_DECLARE;

        template <typename T, std::enable_if_t<TextParsing::cellValueCondition<T>>* = nullptr>
        CellValueImpl& operator=(T rhs);

        template <typename T, std::enable_if_t<TextParsing::cellValueCondition<T>>* = nullptr>
        void Set(T rhs);

        template <typename T, std::enable_if_t<TextParsing::cellValueCondition<T>>* = nullptr>
        NODISCARD T Get() const;

        void Clear() noexcept;
        void SetError() noexcept;
        NODISCARD ValueType GetType() const noexcept;
        NODISCARD std::string GetTypeAsString() const;
        NODISCARD bool IsEqual(const CellValueImpl& rhs) const noexcept;
        NODISCARD bool IsLess(const CellValueImpl& rhs) const noexcept;

    private:
        std::variant<std::string, int64_t, double, bool> cellValue;
        ValueType cellType;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_VALUE_IMPL_H
