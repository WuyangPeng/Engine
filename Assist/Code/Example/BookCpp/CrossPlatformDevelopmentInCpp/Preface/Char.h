///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/12 21:17)

#ifndef CROSS_PLATFORM_DEVELOPMENT_IN_CPP_PREFACE_CHAR_H
#define CROSS_PLATFORM_DEVELOPMENT_IN_CPP_PREFACE_CHAR_H

#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/CrossPlatformDevelopmentInCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace CrossPlatformDevelopmentInCpp
    {
        class CROSS_PLATFORM_DEVELOPMENT_IN_CPP_DEFAULT_DECLARE Char final
        {
        public:
            using ClassType = Char;

        public:
            Char() noexcept;

            CLASS_INVARIANT_DECLARE;

            void Main() const noexcept;
        };
    }
}

#endif  // CROSS_PLATFORM_DEVELOPMENT_IN_CPP_PREFACE_CHAR_H