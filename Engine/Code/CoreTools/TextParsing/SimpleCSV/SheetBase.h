/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 15:22)

#ifndef CORE_TOOLS_TEXT_PARSING_SHEET_BASE_H
#define CORE_TOOLS_TEXT_PARSING_SHEET_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "Color.h"
#include "XmlFile.h"

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE SheetBase : public XmlFile
    {
    public:
        using ClassType = SheetBase;
        using ParentType = XmlFile;

    public:
        explicit SheetBase(const XmlDataSharedPtr& xmlData);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual Color GetColor() const = 0;
        virtual void SetColor(const Color& color) = 0;

        NODISCARD std::string GetName() const;
        void SetName(const std::string& sheetName);

        NODISCARD virtual bool IsSelected() const = 0;
        virtual void SetSelected(bool selected) = 0;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SHEET_BASE_H
