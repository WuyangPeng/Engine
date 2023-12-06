/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/28 22:38)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_RESOURCE_RESOURCE_MANAGER_IMPL_H
#define DATABASE_GENERATE_MIDDLE_LAYER_RESOURCE_RESOURCE_MANAGER_IMPL_H

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerDll.h"

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/ExportMacro.h"

#include <mutex>
#include <thread>

namespace DatabaseGenerateMiddleLayer
{
    class DATABASE_GENERATE_MIDDLE_LAYER_HIDDEN_DECLARE ResourceManagerImpl
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

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_RESOURCE_RESOURCE_MANAGER_IMPL_H
