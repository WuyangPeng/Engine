//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/19 16:45)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MEMORY_MANAGER_H
#define CORE_TOOLS_MEMORY_TOOLS_MEMORY_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <string>

CORE_TOOLS_EXPORT_UNIQUE_PTR(MemoryManager);
CORE_TOOLS_EXPORT_SHARED_PTR(MemoryManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE MemoryManager final : public CoreTools::Singleton<MemoryManager>
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(MemoryManager);

        using ParentType = Singleton<MemoryManager>;

        // ���û��ṩ�����Լ��ķ��亯�����ͷź�����
        using Allocator = void* (*)(size_t bytesNumber, const FunctionDescribed& functionDescribed);
        using Deallocator = void (*)(const void* memBlock, const FunctionDescribed& functionDescribed);

    private:
        enum class MemoryManagerCreate
        {
            Init,
        };

    public:
        explicit MemoryManager(Allocator allocator, Deallocator deallocator, MemoryManagerCreate memoryManagerCreate);
        ~MemoryManager() noexcept;
        MemoryManager(const MemoryManager&) = delete;
        MemoryManager& operator=(const MemoryManager&) = delete;
        MemoryManager(MemoryManager&&) noexcept = delete;
        MemoryManager& operator=(MemoryManager&&) noexcept = delete;

        SINGLETON_GET_PTR_DECLARE(MemoryManager);

        CLASS_INVARIANT_DECLARE;

    public:
        // ��ʼ������ֹ������main�����е��á�Ҫָ���Լ��ķ��亯�����ͷź������޸�Memory::Create������main��
        static void Create(Allocator allocator = &DefaultAllocator, Deallocator deallocator = &DefaultDeallocator);
        static void Destroy() noexcept;

        void PrintMemoryLeakInformation() const;
        [[nodiscard]] int GetMemBlockDimensions(const void* memBlock) const;
        [[nodiscard]] size_t GetBytesNumber(const void* memBlock) const;

        [[nodiscard]] void* CreateBlock(size_t bytesNumber, int dimensionsNumber, const FunctionDescribed& functionDescribed);
        void Delete(const void* memBlock);

    private:
        [[nodiscard]] static void* DefaultAllocator(size_t bytesNumber, const FunctionDescribed& functionDescribed) noexcept;
        [[nodiscard]] static void DefaultDeallocator(const void* memBlock, const FunctionDescribed& functionDescribed) noexcept;

    private:
        using MemoryManagerUniquePtr = std::unique_ptr<MemoryManager>;

    private:
        static MemoryManagerUniquePtr sm_MemoryManager;
        IMPL_TYPE_DECLARE(MemoryManager);
    };
}

#define MEMORY_MANAGER_SINGLETON CoreTools::MemoryManager::GetSingleton()

#endif  // CORE_TOOLS_MEMORY_TOOLS_MEMORY_MANAGER_H
