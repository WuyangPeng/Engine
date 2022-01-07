///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:35)

#ifndef CORE_TOOLS_TEXT_PARSING_COLUMN_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COLUMN_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE ColumnImpl final
        {
        public:
            using ClassType = ColumnImpl;

        public:
            ColumnImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& columnNode) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD float GetWidth() const;
            void SetWidth(float width);
            NODISCARD bool IsHidden() const;
            void SetHidden(bool state);

            NODISCARD XMLNode GetColumnNode() const;

        private:
            ConstXMLDocumentWeakPtr document;
            XMLNode columnNode;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COLUMN_IMPL_H
