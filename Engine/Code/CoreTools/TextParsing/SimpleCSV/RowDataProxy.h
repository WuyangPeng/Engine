///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:17)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_H

#include "CoreTools/CoreToolsDll.h"

#include "CellValue.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <deque>
#include <list>
#include <vector>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::RowDataProxyImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::CopyUnsharedImpl<CoreTools::SimpleCSV::RowDataProxy, CoreTools::SimpleCSV::RowDataProxyImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE RowDataProxy final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(RowDataProxy);
        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;
        using CellValueContainer = std::vector<CellValue>;
        using BoolContainer = std::vector<bool>;
        using RowSharedPtr = std::shared_ptr<Row>;

    public:
        explicit RowDataProxy(DisableNotThrow disableNotThrow);
        RowDataProxy(const ConstXMLDocumentSharedPtr& document, const RowSharedPtr& row, const XMLNode& rowNode);

        CLASS_INVARIANT_DECLARE;

        RowDataProxy& operator=(const CellValueContainer& values);
        RowDataProxy& operator=(const BoolContainer& values);

        NODISCARD CellValueContainer GetValues() const;
        NODISCARD SharedStringsSharedPtr GetSharedStrings();

        void DeleteCellValues(int count);
        void PrependCellValue(const CellValue& value, int column);

        NODISCARD XMLNode GetRowNode() const;

        void Clear();

        NODISCARD explicit operator CellValueContainer() const;
        NODISCARD explicit operator std::deque<CellValue>() const;
        NODISCARD explicit operator std::list<CellValue>() const;

        template <typename T, std::enable_if_t<!std::is_same_v<T, RowDataProxy> && TextParsing::RowDataProxyConditionType<T>::value, T>* = nullptr>
        RowDataProxy& operator=(const T& rhs);

        template <typename Container, std::enable_if_t<!std::is_same_v<Container, RowDataProxy> && TextParsing::RowDataProxyConditionType<Container>::value, Container>* = nullptr>
        NODISCARD explicit operator Container() const;

    private:
        template <typename Container, std::enable_if_t<!std::is_same_v<Container, RowDataProxy> && TextParsing::RowDataProxyConditionType<Container>::value, Container>* = nullptr>
        NODISCARD Container ConvertContainer() const;

        NODISCARD ConstXMLDocumentSharedPtr GetDocument();

        template <typename T, std::enable_if_t<!std::is_same_v<T, RowDataProxy> && TextParsing::RowDataProxyConditionType<T>::value, T>* = nullptr>
        void SetCellValue(const T& rhs);

        template <typename T, std::enable_if_t<!std::is_same_v<T, RowDataProxy> && TextParsing::RowDataProxyConditionType<T>::value, T>* = nullptr>
        void SetContainer(const T& rhs);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_H
