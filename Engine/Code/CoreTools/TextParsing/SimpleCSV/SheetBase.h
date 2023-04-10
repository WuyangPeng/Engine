///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:18)

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
