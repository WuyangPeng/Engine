///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 14:54)

#ifndef CORE_TOOLS_TEXT_PARSING_COLUMN_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COLUMN_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"

namespace CoreTools::SimpleCSV
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

#endif  // CORE_TOOLS_TEXT_PARSING_COLUMN_IMPL_H
