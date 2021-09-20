// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/19 11:22)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "VertexFormatElement.h"
#include "VertexFormatType.h"
#include "Flags/VertexFormatFlags.h"
#include "CoreTools/ObjectSystems/Object.h"

#include <vector>
EXPORT_SHARED_PTR(Rendering, VertexFormatImpl, RENDERING_DEFAULT_DECLARE);
 

namespace CoreTools
{
    class WriteFileManager;
    class ReadFileManager;
}

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexFormat : public CoreTools::Object
    {
    public:
        void Swap(VertexFormat& rhs) noexcept;
        
            public:
                TYPE_DECLARE(VertexFormat);
                using ClassShareType = CoreTools::CopyUnsharedClasses;
                ~VertexFormat() noexcept;
                VertexFormat(const VertexFormat& rhs);
                VertexFormat& operator=(const VertexFormat& rhs);
                VertexFormat(VertexFormat&& rhs) noexcept;
                VertexFormat& operator=(VertexFormat&& rhs) noexcept;
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
        static VertexFormatSharedPtr Create(const std::vector<VertexFormatType> triple);

        static VertexFormatSharedPtr Create(const std::vector<VertexFormatElement> triple);

        static VertexFormatSharedPtr LoadFromFile(ReadFileManager& manager);

        // 支持延迟构造。调用构造函数之后，必须通过使用 SetAttribute 'numAttributes'次设置所有属性。
        // 当完成时，调用SetStride，这是一个信号，即构造已完成。然后创建相关的渲染资源。

        // 注意：VertexBufferAccessor所述的读/写条件是属性的偏移。
        // VertexFormat::Create保证这一点，但你也应该明确的使用SetAttribute。
        void SetAttribute(int attribute, unsigned int streamIndex, unsigned int offset,
                          AttributeType type, AttributeUsage usage, unsigned int usageIndex);

        int GetNumAttributes() const noexcept;

        unsigned int GetStreamIndex(int attribute) const;
        unsigned int GetOffset(int attribute) const;
        AttributeType GetAttributeType(int attribute) const;
        AttributeUsage GetAttributeUsage(int attribute) const;
        unsigned int GetUsageIndex(int attribute) const;

        int GetStride() const noexcept;

        // 返回指定属性的使用情况的索引。指定使用索引目前仅针对颜色通道和纹理坐标使用。
        // 当属性的使用出现在格式中，返回值的索引i在0 <= i < GetNumAttributes()。
        // 如果属性的使用不出现在格式中，返回值是-1。
        int GetIndex(AttributeUsage usage, unsigned int usageIndex = 0) const noexcept;

        // 属性的一个组件所需的字节数。
        static int GetComponentSize(AttributeType type) noexcept;

        // 属性部件的数量。
        static int GetNumComponents(AttributeType type) noexcept;

        // 属性的所有组件的字节数量。
        static int GetTypeSize(AttributeType type) noexcept;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

        virtual VertexFormatSharedPtr Clone() const;

        void SetStride(int stride);
        ObjectInterfaceSharedPtr CloneObject() const override;
    public:
        // 暂时改成公有
        explicit VertexFormat(int numAttributes);

        private:
        void SetAttribute(int attribute, unsigned int streamIndex, unsigned int offset, const VertexFormatType& vertexFormatType);

        void SetAttribute(int attribute, const VertexFormatElement& vertexFormatElement);

    private:
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(VertexFormat);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( VertexFormat);
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_H
