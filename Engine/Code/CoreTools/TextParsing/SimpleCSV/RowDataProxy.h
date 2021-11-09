///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/11 11:58)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_H

#include "CoreTools/CoreToolsDll.h"

#include "CellValue.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <deque>
#include <list>
#include <string>
#include <vector>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::RowDataProxyImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::CopyUnsharedImpl<CoreTools::SimpleCSV::RowDataProxy, CoreTools::SimpleCSV::RowDataProxyImpl>;

namespace CoreTools
{
    namespace SimpleCSV
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

            NODISCARD operator CellValueContainer() const;
            NODISCARD operator std::deque<CellValue>() const;
            NODISCARD operator std::list<CellValue>() const;

            template <typename T,
                      typename std::enable_if<!std::is_same_v<T, RowDataProxy> &&
                                                  std::is_base_of_v<typename std::bidirectional_iterator_tag,
                                                                    typename std::iterator_traits<typename T::iterator>::iterator_category>,
                                              T>::type* = nullptr>
            RowDataProxy& operator=(const T& values);

            template <typename Container,
                      typename std::enable_if<!std::is_same_v<Container, RowDataProxy> &&
                                                  std::is_base_of_v<typename std::bidirectional_iterator_tag,
                                                                    typename std::iterator_traits<typename Container::iterator>::iterator_category>,
                                              Container>::type* = nullptr>
            NODISCARD explicit operator Container() const;

        private:
            template <typename Container,
                      typename std::enable_if<!std::is_same_v<Container, RowDataProxy> &&
                                                  std::is_base_of_v<typename std::bidirectional_iterator_tag,
                                                                    typename std::iterator_traits<typename Container::iterator>::iterator_category>,
                                              Container>::type* = nullptr>
            NODISCARD Container ConvertContainer() const;

            NODISCARD ConstXMLDocumentSharedPtr GetDocument();

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_H
