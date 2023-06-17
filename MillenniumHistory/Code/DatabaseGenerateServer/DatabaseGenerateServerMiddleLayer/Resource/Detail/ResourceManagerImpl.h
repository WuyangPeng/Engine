///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.12 (2023/06/12 21:52)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RESOURCE_MANAGER_IMPL_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RESOURCE_MANAGER_IMPL_H

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/ExportMacro.h"

#include <mutex>
#include <thread>

namespace DatabaseGenerateServerMiddleLayer
{
    class DATABASE_GENERATE_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE ResourceManagerImpl
    {
    public:
        using ClassType = ResourceManagerImpl;
        using ConstAncientBooksContainerSharedPtr = std::shared_ptr<const AncientBooks::AncientBooksContainer>;

    public:
        explicit ResourceManagerImpl(const System::String& directory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Initialize();

        NODISCARD ConstAncientBooksContainerSharedPtr GetAncientBooksContainer();

    private:
        using AncientBooksContainerSharedPtr = std::shared_ptr<AncientBooks::AncientBooksContainer>;

    private:
        void InitAncientBooks();

    private:
        System::String directory;
        AncientBooksContainerSharedPtr ancientBooksContainer;
        std::shared_ptr<std::jthread> thread;
        std::mutex mutex;
    };
}

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RESOURCE_MANAGER_IMPL_H
