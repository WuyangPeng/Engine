///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 21:20)

#ifndef HACKERS_DELIGHT_PREFACE_PRINT_ITSELF_H
#define HACKERS_DELIGHT_PREFACE_PRINT_ITSELF_H

#include "Example/BookCpp/HackersDelight/HackersDelightDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAlgorithm
{
    namespace HackersDelight
    {
        class HACKERS_DELIGHT_DEFAULT_DECLARE PrintItself final
        {
        public:
            using ClassType = PrintItself;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            PrintItself() noexcept;

            void Main() const noexcept;
        };
    }
}

#endif  // HACKERS_DELIGHT_PREFACE_PRINT_ITSELF_H
