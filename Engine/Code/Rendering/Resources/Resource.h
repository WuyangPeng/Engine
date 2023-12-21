/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/11 19:33)

#ifndef RENDERING_RESOURCES_RESOURCE_H
#define RENDERING_RESOURCES_RESOURCE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/Base/GraphicsObject.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Resource, ResourceImpl);

// 创建或销毁与资源关联的系统内存存储。如果资源仅用于为GPU资源创建提供信息，则它不一定需要系统内存。
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Resource : public GraphicsObject
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Resource);
        using ParentType = GraphicsObject;

        using StorageType = std::vector<char>;
        using SpanIterator = CoreTools::SpanIterator<StorageType::iterator>;
        using ConstSpanIterator = CoreTools::SpanIterator<StorageType::const_iterator>;

    public:
        // 默认的UsageType为UsageType::Immutable。
        Resource(const std::string& name, GraphicsObjectType type);
        Resource(const std::string& name, int numElements, int elementSize, GraphicsObjectType type, bool createStorage = true);
        Resource(const std::string& name, int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Resource);

        NODISCARD bool IsCreateStorage() const noexcept;

        /// 创建或销毁与资源关联的系统内存存储。
        /// 如果资源仅用于为GPU资源创建提供信息，则它不一定需要系统内存。
        void CreateStorage();
        void DestroyStorage();

        NODISCARD int GetNumElements() const noexcept;
        NODISCARD int GetElementSize() const noexcept;
        NODISCARD int GetNumBytes() const noexcept;

        void SetUsage(UsageType usageType) noexcept;
        NODISCARD UsageType GetUsage() const noexcept;

        void SetCopy(CopyType copyType) noexcept;
        NODISCARD CopyType GetCopy() const noexcept;

        /// 指定资源中活动元素的连续块。一个元素占用elementSize字节。
        /// 将数据数组视为元素数组，offset是第一个活动元素的索引；也就是说，第一个元素具有地址：
        /// data + offset * elementSize
        /// 偏移量必须满足
        /// offset < numElements
        /// 活动元素的数量为numActiveElements。它必须满足：
        /// nNumActiveElements <= numElements - offset
        /// 如果计划同时修改同一对象的offset和numActiveElements，
        /// 请在SetNumActiveElement()之前调用SetOffset()，因为活动数量约束依赖于偏移量。
        void SetOffset(int offset);
        NODISCARD int GetOffset() const noexcept;

        void SetNumActiveElements(int numActiveElements);
        NODISCARD int GetNumActiveElements() const noexcept;
        NODISCARD int GetNumActiveBytes() const noexcept;

        NODISCARD ConstSpanIterator GetStorage() const noexcept;
        NODISCARD SpanIterator GetStorage() noexcept;

        NODISCARD ConstSpanIterator GetStorage(int offset) const;
        NODISCARD SpanIterator GetStorage(int offset);

        void SetStorage(const StorageType& storage);

        // 同系统API的交互。
        NODISCARD const char* GetOriginalData() const;
        NODISCARD const char* GetOriginalData(int offset) const;

        NODISCARD char* GetOriginalData();
        NODISCARD char* GetOriginalData(int offset);

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Resource);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Resource);
}

#endif  // RENDERING_RESOURCES_RESOURCE_H