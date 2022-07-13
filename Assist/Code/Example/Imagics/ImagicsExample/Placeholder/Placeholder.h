///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 13:57)

#ifndef IMAGICS_EXAMPLE_PLACEHOLDER_H
#define IMAGICS_EXAMPLE_PLACEHOLDER_H

#include "Example/Imagics/ImagicsExample/ImagicsExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ImagicsExample
{
    class IMAGICS_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // IMAGICS_EXAMPLE_PLACEHOLDER_H
