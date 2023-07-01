///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 21:50)

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
        using ConstAncientBooksContainerSharedPtr = std::shared_ptr<const AncientBooks::AncientBooksContainer>;

    public:
        explicit ResourceManagerImpl(const System::String& directory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Initialize();

        NODISCARD ConstAncientBooksContainerSharedPtr GetAncientBooksContainer();

    private:
        using AncientBooksContainerSharedPtr = std::shared_ptr<AncientBooks::AncientBooksContainer>;
        using ThreadSharedPtr = std::shared_ptr<std::jthread>;

    private:
        void InitAncientBooks();

    private:
        System::String directory;
        AncientBooksContainerSharedPtr ancientBooksContainer;
        ThreadSharedPtr thread;
        std::mutex mutex;
    };
}

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RESOURCE_RESOURCE_MANAGER_IMPL_H
