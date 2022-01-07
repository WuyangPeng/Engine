///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:47)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_REFERENCE_H
#define CORE_TOOLS_TEXT_PARSING_CELL_REFERENCE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::CellReferenceImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::DelayCopyUnsharedImpl<CoreTools::SimpleCSV::CellReference, CoreTools::SimpleCSV::CellReferenceImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE CellReference final : public boost::totally_ordered<CellReference>
        {
        public:
            DELAY_COPY_UNSHARED_TYPE_DECLARE(CellReference);

        public:
            explicit CellReference(const std::string& cellAddress);
            CellReference(int row, int column);
            CellReference(int row, const std::string& column);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetRow() const noexcept;
            void SetRow(int row);
            NODISCARD int GetColumn() const noexcept;
            void SetColumn(int column);
            void SetRowAndColumn(int row, int column);
            NODISCARD std::string GetAddress() const;
            void SetAddress(const std::string& address);

            NODISCARD static int GetColumn(const std::string& cellAddress);

        private:
            PackageType impl;
        };

        CORE_TOOLS_DEFAULT_DECLARE NODISCARD bool operator==(const CellReference& lhs, const CellReference& rhs) noexcept;
        CORE_TOOLS_DEFAULT_DECLARE NODISCARD bool operator<(const CellReference& lhs, const CellReference& rhs) noexcept;
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_REFERENCE_H
