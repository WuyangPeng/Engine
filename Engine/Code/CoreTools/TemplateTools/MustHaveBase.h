//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:26)

// 约束：类D是类B的派生类或相同类型
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename Derive, typename Base>
    struct MustHaveBase
    {
        ~MustHaveBase()
        {
            void (*ptr)(Derive*, Base*) = Constranints;
        }

    private:
        static void Constranints(Derive* derivePtr, Base* basePtr)
        {
            basePtr = derivePtr;
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H
