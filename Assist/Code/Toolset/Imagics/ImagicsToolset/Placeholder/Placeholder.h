///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 11:41)

#ifndef IMAGICS_TOOLSET_PLACEHOLDER_H
#define IMAGICS_TOOLSET_PLACEHOLDER_H

#include "Toolset/Imagics/ImagicsToolset/ImagicsToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ImagicsToolset
{
    class IMAGICS_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // IMAGICS_TOOLSET_PLACEHOLDER_H
