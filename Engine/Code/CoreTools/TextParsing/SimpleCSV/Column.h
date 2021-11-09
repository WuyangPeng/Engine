///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/09 16:40)

#ifndef CORE_TOOLS_TEXT_PARSING_COLUMN_H
#define CORE_TOOLS_TEXT_PARSING_COLUMN_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::ColumnImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::DelayCopyUnsharedImpl<CoreTools::SimpleCSV::Column, CoreTools::SimpleCSV::ColumnImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE Column final
        {
        public:
            DELAY_COPY_UNSHARED_TYPE_DECLARE(Column);

        public:
            Column(const ConstXMLDocumentSharedPtr& document, const XMLNode& columnNode);

            CLASS_INVARIANT_DECLARE;

            NODISCARD float GetWidth() const;
            void SetWidth(float width);
            NODISCARD bool IsHidden() const;
            void SetHidden(bool state);

            NODISCARD XMLNode GetColumnNode() const;

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COLUMN_H
