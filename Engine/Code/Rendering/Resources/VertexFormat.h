///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 16:55)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "VertexFormatElement.h"
#include "VertexFormatType.h"
#include "Flags/VertexFormatFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(VertexFormat, VertexFormatImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexFormat : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(VertexFormat);
        using ParentType = Object;
        using VertexFormatSharedPtr = std::shared_ptr<ClassType>;
        using ConstVertexFormatSharedPtr = std::shared_ptr<const ClassType>;
        using AttributeType = VertexFormatFlags::AttributeType;
        using AttributeUsage = VertexFormatFlags::AttributeUsage;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VertexFormat)

        // 便利函数用于创建一个顶点格式通过指定它的所有属性。
        // 现在这个工作只有一个通用的流索引为零(流索引尚未实现任何数值)。
        NODISCARD static VertexFormatSharedPtr Create(const std::vector<VertexFormatType>& triple);

        NODISCARD static VertexFormatSharedPtr Create(const std::vector<VertexFormatElement>& triple);

        NODISCARD static VertexFormatSharedPtr LoadFromFile(ReadFileManager& manager);

        // 支持延迟构造。调用构造函数之后，必须通过使用 SetAttribute 'numAttributes'次设置所有属性。
        // 当完成时，调用SetStride，这是一个信号，即构造已完成。然后创建相关的渲染资源。

        // 注意：VertexBufferAccessor所述的读/写条件是属性的偏移。
        // VertexFormat::Create保证这一点，但你也应该明确的使用SetAttribute。
        void SetAttribute(int attribute, int32_t streamIndex, int32_t offset, AttributeType type, AttributeUsage usage, int32_t usageIndex);

        NODISCARD int GetNumAttributes() const noexcept;

        NODISCARD int32_t GetStreamIndex(int attribute) const;
        NODISCARD int32_t GetOffset(int attribute) const;
        NODISCARD AttributeType GetAttributeType(int attribute) const;
        NODISCARD AttributeUsage GetAttributeUsage(int attribute) const;
        NODISCARD int32_t GetUsageIndex(int attribute) const;

        NODISCARD int GetStride() const noexcept;

        // 返回指定属性的使用情况的索引。指定使用索引目前仅针对颜色通道和纹理坐标使用。
        // 当属性的使用出现在格式中，返回值的索引i在0 <= i < GetNumAttributes()。
        // 如果属性的使用不出现在格式中，返回值是-1。
        NODISCARD int GetIndex(AttributeUsage usage, int32_t usageIndex = 0) const noexcept;

        // 属性的一个组件所需的字节数。
        NODISCARD static int GetComponentSize(AttributeType type) noexcept;

        // 属性部件的数量。
        NODISCARD static int GetNumComponents(AttributeType type) noexcept;

        // 属性的所有组件的字节数量。
        NODISCARD static int GetTypeSize(AttributeType type) noexcept;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

        NODISCARD virtual VertexFormatSharedPtr Clone() const;

        void SetStride(int stride);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        enum class VertexFormatCreate
        {
            Init,
        };

    public:
        VertexFormat(MAYBE_UNUSED VertexFormatCreate vertexFormatCreate, int numAttributes);

    private:
        void SetAttribute(int attribute, int32_t streamIndex, int32_t offset, const VertexFormatType& vertexFormatType);

        void SetAttribute(int attribute, const VertexFormatElement& vertexFormatElement);

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(VertexFormat);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VertexFormat);
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_H
