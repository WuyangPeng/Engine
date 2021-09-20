///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/02 22:00)

#ifndef EXTENDED_STL_PREFACE_ARRANGEMENT_STYLE_H
#define EXTENDED_STL_PREFACE_ARRANGEMENT_STYLE_H

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookStandardLibrary
{
    namespace ExtendedSTL
    {
        class EXTENDED_STL_DEFAULT_DECLARE ArrangementStyle final
        {
        public:
            using ClassType = ArrangementStyle;

        public:
            ArrangementStyle() noexcept;

            CLASS_INVARIANT_DECLARE;

            void Main() const noexcept;
        };
    }
}

#endif  // EXTENDED_STL_PREFACE_ARRANGEMENT_STYLE_H
