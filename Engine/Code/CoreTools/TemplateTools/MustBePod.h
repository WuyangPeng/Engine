//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:26)

// 约束：必须是POD
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    struct MustBePod
    {
        ~MustBePod()
        {
            void (*ptr)() = Constranints;
        }

    private:
        static void Constranints()
        {
            union
            {
                T TIsNotPODType;
            } unionType;
        }
    };

    template <typename T>
    struct MustBePodOrVoid
    {
        ~MustBePodOrVoid()
        {
            void (*ptr)() = Constranints;
        }

    private:
        static void Constranints()
        {
            union
            {
                T TIsNotPODTypeOrVoid;
            } unionType;
        }
    };

    template <>
    struct MustBePodOrVoid<void>
    {
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H
