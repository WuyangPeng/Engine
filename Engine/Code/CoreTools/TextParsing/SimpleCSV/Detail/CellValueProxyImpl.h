/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:52)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE CellValueProxyImpl final
    {
    public:
        using ClassType = CellValueProxyImpl;

        using CellSharedPtr = std::shared_ptr<Cell>;

    public:
        CellValueProxyImpl() noexcept;
        explicit CellValueProxyImpl(const CellSharedPtr& cell) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Clear();
        void SetError();

        NODISCARD ValueType GetType() const;
        NODISCARD std::string GetTypeAsString() const;

        void SetInteger(int64_t numberValue);
        void SetBoolean(bool numberValue);
        void SetFloat(double numberValue);
        void SetString(const std::string& stringValue);

        NODISCARD CellValue GetValue() const;

    private:
        using CellWeakPtr = std::weak_ptr<Cell>;

    private:
        NODISCARD XMLNode GetXMLNode() const;
        NODISCARD XMLNode AppendAttributeT();
        NODISCARD XMLNode AppendChildV();
        NODISCARD std::string GetAttributeValue() const;
        NODISCARD static ValueType GetNumberType(const XMLNode& node);
        NODISCARD static ValueType GetStringType(const std::string& attributeValue) noexcept;

    private:
        CellWeakPtr cell;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_IMPL_H
