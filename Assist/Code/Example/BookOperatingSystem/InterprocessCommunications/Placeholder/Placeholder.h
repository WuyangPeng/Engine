///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/08 21:15)

#ifndef INTERPROCESS_COMMUNICATIONS_PLACEHOLDER_H
#define INTERPROCESS_COMMUNICATIONS_PLACEHOLDER_H

#include "Example/BookOperatingSystem/InterprocessCommunications/InterprocessCommunicationsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace InterprocessCommunications
{
    class INTERPROCESS_COMMUNICATIONS_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // INTERPROCESS_COMMUNICATIONS_PLACEHOLDER_H
