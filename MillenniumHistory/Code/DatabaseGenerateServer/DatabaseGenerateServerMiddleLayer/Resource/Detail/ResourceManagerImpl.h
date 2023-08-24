///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/09 22:24)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RESOURCE_RESOURCE_MANAGER_IMPL_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RESOURCE_RESOURCE_MANAGER_IMPL_H

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

        using String = System::String;
        using ConstAncientBooksContainerSharedPtr = std::shared_ptr<const AncientBooks::AncientBooksContainer>;

    public:
        explicit ResourceManagerImpl(const String& directory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Initialize();
        NODISCARD bool Destroy() noexcept;

        NODISCARD ConstAncientBooksContainerSharedPtr GetAncientBooksContainer();

    private:
        using ThreadSharedPtr = std::shared_ptr<std::jthread>;
        using AncientBooksContainerSharedPtr = std::shared_ptr<AncientBooks::AncientBooksContainer>;

    private:
        void InitAncientBooks();

    private:
        String directory;
        AncientBooksContainerSharedPtr ancientBooksContainer;
        ThreadSharedPtr thread;
        std::mutex mutex;
    };
}

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RESOURCE_RESOURCE_MANAGER_IMPL_H
