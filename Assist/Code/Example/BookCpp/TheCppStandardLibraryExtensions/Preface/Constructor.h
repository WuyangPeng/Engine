///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/12 21:17)

#ifndef THE_CPP_STANDARD_LIBRARY_EXTENSIONS_PREFACE_CONSTRUCTOR_H
#define THE_CPP_STANDARD_LIBRARY_EXTENSIONS_PREFACE_CONSTRUCTOR_H

#include "Example/BookCpp/TheCppStandardLibraryExtensions/TheCppStandardLibraryExtensionsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookBoost
{
    namespace TheCppStandardLibraryExtensions
    {
        class THE_CPP_STANDARD_LIBRARY_EXTENSIONS_DEFAULT_DECLARE Constructor final
        {
        public:
            using ClassType = Constructor;

        public:
            Constructor() noexcept;

            CLASS_INVARIANT_DECLARE;

            void Main() const noexcept;
        };
    }
}

#endif  // THE_CPP_STANDARD_LIBRARY_EXTENSIONS_PREFACE_CONSTRUCTOR_H
