///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/08 17:04)

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
        Resource(int numElements, int elementSize, GraphicsObjectType type = GraphicsObjectType::Resource);
        Resource(int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type = GraphicsObjectType::Resource);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Resource);

        NODISCARD int GetNumElements() const noexcept;
        NODISCARD int GetElementSize() const noexcept;
        NODISCARD int GetNumBytes() const noexcept;

        void SetUsage(UsageType usageType) noexcept;
        NODISCARD UsageType GetUsage() const noexcept;

        void SetCopy(CopyType copyType) noexcept;
        NODISCARD CopyType GetCopy() const noexcept;

        NODISCARD ConstSpanIterator GetData() const noexcept;
        NODISCARD SpanIterator GetData() noexcept;

        NODISCARD ConstSpanIterator GetData(int aOffset) const;
        NODISCARD SpanIterator GetData(int aOffset);

        void SetOffset(int aOffset);
        NODISCARD int GetOffset() const noexcept;

        // 应用程序可能需要不同数量的活跃索引。使用这个函数设置。
        // 它不改变数据存储,只改变缓冲区的numActiveElements成员。
        // 调用者负责保存的原始数量索引和当完成索引缓冲区时重置。
        // 调用者还不应该传入比原来的索引数量大的索引数量。
        void SetNumActiveElements(int aNumActiveElements);
        NODISCARD int GetNumActiveElements() const noexcept;
        NODISCARD int GetNumActiveBytes() const noexcept;

        void SetNewData(const StorageType& newStorage);

        NODISCARD const char* GetOriginalData() const;
        NODISCARD const char* GetOriginalData(int aOffset) const;

        NODISCARD char* GetOriginalData(int aOffset);

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Resource);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Resource);
}

#endif  // RENDERING_RESOURCES_RESOURCE_H