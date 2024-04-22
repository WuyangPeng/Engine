/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 15:45)

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

        template <typename T>
        requires(!std::is_same_v<T, CoreTools::SimpleCSV::RowDataProxy> && CoreTools::TextParsing::RowDataProxyConditionType<T>::value)
        RowDataProxy& operator=(const T& rhs);

        template <typename Container>
        requires(!std::is_same_v<Container, CoreTools::SimpleCSV::RowDataProxy> && CoreTools::TextParsing::RowDataProxyConditionType<Container>::value)
        NODISCARD explicit operator Container() const;

    private:
        template <typename Container>
        requires(!std::is_same_v<Container, CoreTools::SimpleCSV::RowDataProxy> && CoreTools::TextParsing::RowDataProxyConditionType<Container>::value)
        NODISCARD Container ConvertContainer() const;

        NODISCARD ConstXMLDocumentSharedPtr GetDocument();

        template <typename T>
        requires(!std::is_same_v<T, CoreTools::SimpleCSV::RowDataProxy> && CoreTools::TextParsing::RowDataProxyConditionType<T>::value)
        void SetCellValue(const T& rhs);

        template <typename T>
        requires(!std::is_same_v<T, CoreTools::SimpleCSV::RowDataProxy> && CoreTools::TextParsing::RowDataProxyConditionType<T>::value)
        void SetContainer(const T& rhs);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_H
