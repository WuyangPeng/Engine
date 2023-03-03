///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/11 10:54)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "VertexFormatAttribute.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

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
        using Semantic = VertexFormatFlags::Semantic;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;
        using AttributeContainer = std::vector<VertexFormatAttribute>;

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VertexFormat);

        NODISCARD static VertexFormatSharedPtr Create();

        // 便利函数用于创建一个顶点格式通过指定它的所有属性。
        // 现在这个工作只有一个通用的流索引为零(流索引尚未实现任何数值)。
        NODISCARD static VertexFormatSharedPtr Create(const AttributeContainer& triple);

        NODISCARD static VertexFormatSharedPtr LoadFromFile(ReadFileManager& manager);

        // 支持延迟构造。调用构造函数之后，必须通过使用 SetAttribute 'numAttributes'次设置所有属性。
        // 当完成时，调用SetStride，这是一个信号，即构造已完成。然后创建相关的渲染资源。

        // 注意：VertexBuffer所述的读/写条件是属性的偏移。
        // VertexFormat::Create保证这一点，但你也应该明确的使用SetAttribute。
        void SetAttribute(int attribute, DataFormatType type, Semantic usage, int usageIndex, int offset);

        NODISCARD int GetNumAttributes() const noexcept;

        NODISCARD int GetOffset(int attribute) const;
        NODISCARD DataFormatType GetAttributeType(int attribute) const;
        NODISCARD Semantic GetAttributeUsage(int attribute) const;
        NODISCARD int GetUsageIndex(int attribute) const;

        NODISCARD int GetStride() const noexcept;
        void SetStride(int stride);

        // 返回指定属性的使用情况的索引。指定使用索引目前仅针对颜色通道和纹理坐标使用。
        // 当属性的使用出现在格式中，返回值的索引i在0 <= i < GetNumAttributes()。
        // 如果属性的使用不出现在格式中，返回值是-1。
        NODISCARD int GetIndex(Semantic usage, int usageIndex = 0) const noexcept;

        void Reset() noexcept;

        void Bind(Semantic semantic, DataFormatType type, int unit);

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

        NODISCARD virtual VertexFormatSharedPtr Clone() const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        enum class VertexFormatCreate
        {
            Init,
        };

    public:
        VertexFormat(MAYBE_UNUSED VertexFormatCreate vertexFormatCreate, int numAttributes);

    private:
        void SetAttribute(int attribute, const VertexFormatAttribute& vertexFormatElement);

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(VertexFormat);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VertexFormat);
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_H
