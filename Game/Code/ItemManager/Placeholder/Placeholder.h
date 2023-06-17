///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:46)

#ifndef ITEM_MANAGER_PLACEHOLDER_PLACEHOLDER_H
#define ITEM_MANAGER_PLACEHOLDER_PLACEHOLDER_H

#include "ItemManager/ItemManagerDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ItemManager
{
    class ITEM_MANAGER_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ITEM_MANAGER_PLACEHOLDER_PLACEHOLDER_H
