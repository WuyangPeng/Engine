///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/02 21:57)

#ifndef EXTENDED_STL_PREFACE_ARRANGEMENT_STYLE_DECLARATION_H
#define EXTENDED_STL_PREFACE_ARRANGEMENT_STYLE_DECLARATION_H

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookStandardLibrary
{
    namespace ExtendedSTL
    {
        // In namespace NamespaceName
        class ClassName
        {
            // something that's a given,or has been shown already
        public:
            ClassName() noexcept  // Class section Name,e.g.,"Construction"
            {
                this->SomethingEmphasized();
                SomethingNewOrChangedFromPreviousListing();
            }

            void SomethingEmphasized() noexcept
            {
            }

            void SomethingNewOrChangedFromPreviousListing() noexcept
            {
            }
        };

        namespace Better
        {
            template <typename I>
            struct Thing
            {
                using iterator = I;
            };
        }

        template <typename Iterator>
        struct Thing
        {
            using iterator = Iterator;
        };
    }
}

#endif  // EXTENDED_STL_PREFACE_ARRANGEMENT_STYLE_DECLARATION_H
