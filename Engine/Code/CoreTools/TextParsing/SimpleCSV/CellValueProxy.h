/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:39)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_H
#define CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_H

#include "CoreTools/CoreToolsDll.h"

#include "CellValue.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::CellValueProxyImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::CopyUnsharedImpl<CoreTools::SimpleCSV::CellValueProxy, CoreTools::SimpleCSV::CellValueProxyImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE CellValueProxy final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(CellValueProxy);

        using CellSharedPtr = std::shared_ptr<Cell>;

    public:
        NODISCARD static CellValueProxy CreateEmpty();
        explicit CellValueProxy(const CellSharedPtr& cell);

    private:
        enum class CellValueProxyCreate
        {
            Init,
        };

    private:
        explicit CellValueProxy(CellValueProxyCreate cellValueProxyCreate);

    public:
        CLASS_INVARIANT_DECLARE;

        template <typename T>
        requires(CoreTools::TextParsing::cellValueProxyCondition<T> || std::is_same_v<std::decay_t<T>, CoreTools::SimpleCSV::CellValue>)
        CellValueProxy& operator=(T&& rhs);

        template <typename T>
        requires(CoreTools::TextParsing::cellValueProxyCondition<T> || std::is_same_v<std::decay_t<T>, CoreTools::SimpleCSV::CellValue>)
        void Set(T&& rhs);

        template <typename T>
        requires(CoreTools::TextParsing::cellValueProxyCondition<T>)
        NODISCARD T Get() const;

        void Clear();
        void SetError();
        NODISCARD ValueType GetType() const;
        NODISCARD std::string GetTypeAsString() const;

        void SetInteger(int64_t numberValue);
        void SetBoolean(bool numberValue);
        void SetFloat(double numberValue);
        void SetString(const std::string& stringValue);

        void SetCellValue(const CellValue& cellValue);

        NODISCARD CellValue GetValue() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_H
