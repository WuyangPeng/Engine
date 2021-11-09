///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/10/11 22:03)

#ifndef CORE_TOOLS_TEXT_PARSING_SHEET_BASE_H
#define CORE_TOOLS_TEXT_PARSING_SHEET_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "Color.h"
#include "XmlFile.h"

namespace CoreTools
{
    namespace SimpleCSV
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
}

#endif  // CORE_TOOLS_TEXT_PARSING_SHEET_BASE_H
