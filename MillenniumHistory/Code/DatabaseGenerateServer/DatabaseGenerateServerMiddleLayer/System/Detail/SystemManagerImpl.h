///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.11 (2023/06/06 22:13)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_IMPL_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_IMPL_H

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerConfiguration/AncientBooks/AncientBooksContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/ExportMacro.h"

namespace DatabaseGenerateServerMiddleLayer
{
    class DATABASE_GENERATE_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE SystemManagerImpl
    {
    public:
        using ClassType = SystemManagerImpl;

    public:
        explicit SystemManagerImpl(const System::String& directory);

        CLASS_INVARIANT_DECLARE;

    private:
        AncientBooks::AncientBooksContainer ancientBooksContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_IMPL_H
