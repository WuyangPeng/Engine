///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/19 21:51)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_SYSTEM_SYSTEM_MANAGER_IMPL_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_SYSTEM_SYSTEM_MANAGER_IMPL_H

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/ExportMacro.h"

namespace DatabaseGenerateServerMiddleLayer
{
    class DATABASE_GENERATE_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE SystemManagerImpl
    {
    public:
        using ClassType = SystemManagerImpl;

    public:
        SystemManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Initialize() noexcept;
    };
}

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_SYSTEM_MANAGER_IMPL_H
