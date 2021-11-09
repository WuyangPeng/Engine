///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/07 20:10)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    namespace SimpleCSV
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
            NODISCARD ValueType GetNumberType(const XMLNode& node) const;
            NODISCARD ValueType GetStringType(const std::string attributeValue) const;

        private:
            CellWeakPtr cell;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_IMPL_H
