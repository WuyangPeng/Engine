//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/20 10:02)

#include "CoreTools/CoreToolsExport.h"

#include "MemoryManagerImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h" 

#include <sstream>

using std::ostringstream;
using std::string;
using namespace std::literals;

CoreTools::MemoryManagerImpl::MemoryManagerImpl(Allocator allocator, Deallocator deallocator)
    : m_MemoryContainer{}, m_Allocator{ allocator }, m_Deallocator{ deallocator }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::MemoryManagerImpl::IsValid() const noexcept
{
    if (m_Allocator != nullptr && m_Deallocator != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::MemoryManagerImpl::PrintMemoryLeakInformation() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    // 从基于唯一的ID的内存映射创建一个有序映射。
    SortedContainer sorted{};
    for (const auto& value : m_MemoryContainer)
    {
        if (!sorted.insert({ value.second.GetUniqueID(), value }).second)
        {
            CORE_TOOLS_ASSERTION_2(false, "unique ID 不是唯一的！");
        }
    }

    if (!sorted.empty())
    {
        ostringstream os{};

        os << "内存泄露：\n";

        // 保存有序映射到日志
        for (const auto& value : sorted)
        {
            auto uniqueID = value.first;
            auto address = value.second.first;
            auto info = value.second.second;
            const auto& functionDescribed = info.GetFunctionDescribed();

            os << "unique ID = " << uniqueID << '\n'
               << "地址 = " << address << '\n'
               << "字节大小 = " << info.GetBytesNumber() << '\n'
               << "维度大小 = " << info.GetDimensionsNumber() << '\n'
               << "所处文件 = " << functionDescribed.GetFileName() << ','
               << "函数 = " << functionDescribed.GetCurrentFunction()
               << "(" << functionDescribed.GetLine() << ")\n"
               << '\n';
        }

        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << os.str()
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

int CoreTools::MemoryManagerImpl::GetMemBlockDimensions(const void* memBlock) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto iter = m_MemoryContainer.find(memBlock);
    if (iter != m_MemoryContainer.cend())
    {
        return iter->second.GetDimensionsNumber();
    }
    else
    {
        CORE_TOOLS_ASSERTION_2(false, "内存块不在内存池中！\n");
        return -1;
    }
}

size_t CoreTools::MemoryManagerImpl::GetBytesNumber(const void* memBlock) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto iter = m_MemoryContainer.find(memBlock);
    if (iter != m_MemoryContainer.cend())
    {
        return iter->second.GetBytesNumber();
    }
    else
    {
        CORE_TOOLS_ASSERTION_2(false, "内存块不在内存池中！\n");
        return 0;
    }
}

void* CoreTools::MemoryManagerImpl::CreateBlock(size_t bytesNumber, int dimensionsNumber, const FunctionDescribed& functionDescribed)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto memBlock = m_Allocator(bytesNumber, functionDescribed);
    if (memBlock == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("内存不足！"s));
    }

    try
    {
        MemoryInformation memoryInformation{ bytesNumber, dimensionsNumber, functionDescribed };

        if (!m_MemoryContainer.insert({ memBlock, memoryInformation }).second)
        {
            CORE_TOOLS_ASSERTION_2(false, "生成的内存地址已被分配！");
        }

        return memBlock;
    }
    catch (...)
    {
        Delete(memBlock);
        throw;
    }
}

void CoreTools::MemoryManagerImpl::Delete(const void* memBlock)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto iter = m_MemoryContainer.find(memBlock);
    if (iter != m_MemoryContainer.cend())
    {
        m_Deallocator(iter->first, iter->second.GetFunctionDescribed());
        m_MemoryContainer.erase(iter);
    }
    else
    {
        CORE_TOOLS_ASSERTION_2(false, "内存块不在内存池中！\n");
    }
}
