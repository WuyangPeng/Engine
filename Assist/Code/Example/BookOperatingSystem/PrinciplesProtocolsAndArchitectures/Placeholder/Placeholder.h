///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 8:45)

#ifndef PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_PLACEHOLDER_H
#define PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_PLACEHOLDER_H

#include "Example/BookOperatingSystem/PrinciplesProtocolsAndArchitectures/PrinciplesProtocolsAndArchitecturesDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace PrinciplesProtocolsAndArchitectures
{
    class PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_PLACEHOLDER_H
