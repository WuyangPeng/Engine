///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 10:18)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_H
#define CORE_TOOLS_TEXT_PARSING_ROW_H

#include "CoreTools/CoreToolsDll.h"

#include "RowDataProxy.h"
#include "XmlParser.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::RowImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::NonCopyImpl<CoreTools::SimpleCSV::RowImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE Row final : public boost::totally_ordered<Row>
    {
    public:
        NON_COPY_TYPE_DECLARE(Row);
        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;
        using RowSharedPtr = std::shared_ptr<Row>;

    public:
        NODISCARD static RowSharedPtr CreateRow(const ConstXMLDocumentSharedPtr& document);
        NODISCARD static RowSharedPtr CreateRow(const ConstXMLDocumentSharedPtr& document, const XMLNode& rowNode, const SharedStringsSharedPtr& sharedStrings);

        CLASS_INVARIANT_DECLARE;

        NODISCARD double GetHeight() const;
        void SetHeight(double height);
        NODISCARD double GetDescent() const;
        void SetDescent(double descent);
        NODISCARD bool IsHidden() const;
        void SetHidden(bool state);
        NODISCARD int GetRowNumber() const;
        NODISCARD int GetCellCount() const;
        NODISCARD RowDataProxy& GetValues() noexcept;
        NODISCARD const RowDataProxy& GetValues() const noexcept;
        NODISCARD RowDataRange GetCells() const;
        NODISCARD RowDataRange GetCells(int cellCount) const;
        NODISCARD RowDataRange GetCells(int firstCell, int lastCell) const;
        NODISCARD XMLNode GetRowNode() const;
        NODISCARD SharedStringsSharedPtr GetSharedStrings();
        NODISCARD bool IsSame(const Row& rhs) const;
        NODISCARD bool IsLess(const Row& rhs) const;

        template <typename T>
        NODISCARD T GetValues() const
        {
            return static_cast<T>(GetValues());
        }

    private:
        enum class RowCreate
        {
            Init,
        };

    public:
        explicit Row(const ConstXMLDocumentSharedPtr& document, RowCreate cellCreate);

    private:
        PackageType impl;
    };

    CORE_TOOLS_DEFAULT_DECLARE NODISCARD bool operator==(const Row& lhs, const Row& rhs);
    CORE_TOOLS_DEFAULT_DECLARE NODISCARD bool operator<(const Row& lhs, const Row& rhs);
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_H
