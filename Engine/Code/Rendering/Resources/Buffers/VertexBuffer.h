/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/13 14:45)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "VertexFormat.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <set>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(VertexBuffer, VertexBufferImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexBuffer : public Buffer
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(VertexBuffer);
        using ParentType = Buffer;

        using VertexBufferSharedPtr = std::shared_ptr<ClassType>;
        using ConstVertexBufferSharedPtr = std::shared_ptr<const ClassType>;
        using StructuredBufferSharedPtr = std::shared_ptr<StructuredBuffer>;
        using ConstStructuredBufferSharedPtr = std::shared_ptr<const StructuredBuffer>;
        using DataFormatTypeContainer = std::set<DataFormatType>;
        using Semantic = VertexFormatFlags::Semantic;

    public:
        NODISCARD static VertexBufferSharedPtr Create(const std::string& name, int numVertices);
        NODISCARD static VertexBufferSharedPtr Create(const std::string& name, const VertexFormat& format, const StructuredBuffer& structuredBuffer);
        NODISCARD static VertexBufferSharedPtr Create(const std::string& name, const VertexFormat& format, int numVertices, bool createStorage = true);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VertexBuffer);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD VertexFormat GetFormat() const;
        NODISCARD StructuredBufferSharedPtr GetStructuredBuffer();
        NODISCARD ConstStructuredBufferSharedPtr GetStructuredBuffer() const;

        /// 当使用第一个构造函数时，函数StandardUsage()返回true，
        /// 当使用第二个构造函数时返回false。
        NODISCARD bool StandardUsage() const noexcept;

        /// 获取指向指定语义和单位的属性数据（如果存在）的指针。
        /// 此外，您还要求该属性是所需类型列表（位标志）中的一个。
        /// 如果不关心类型，请为所需的输入传递Unknown。
        /// 如果请求失败，将抛出一个异常。
        NODISCARD SpanIterator GetChannel(Semantic semantic, int unit, const DataFormatTypeContainer& requiredTypes);
        NODISCARD ConstSpanIterator GetConstChannel(Semantic semantic, int unit, const DataFormatTypeContainer& requiredTypes) const;

        NODISCARD virtual VertexBufferSharedPtr Clone() const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    protected:
        enum class VertexBufferCreate
        {
            Init,
        };

    public:
        /// 此构造函数适用于光栅化器使用顶点缓冲区向顶点着色器提供顶点的标准用途。
        VertexBuffer(VertexBufferCreate vertexBufferCreate, const std::string& name, const VertexFormat& format, int numVertices, bool createStorage);

        /// 此构造函数用于基于顶点id的绘制，其中顶点是从顶点着色器中的结构化缓冲区资源读取的。
        /// 输入structuredBuffer必须为非nullptr，并且其顶点数将复制到'this'顶点数。
        VertexBuffer(VertexBufferCreate vertexBufferCreate, const std::string& name, const VertexFormat& format, const StructuredBuffer& structuredBuffer);

        /// 此构造函数用于不需要顶点的基于顶点id的绘图；
        /// 例如，着色器本身可以根据标识符生成位置。
        VertexBuffer(VertexBufferCreate vertexBufferCreate, const std::string& name, int numVertices);

    private:
        NODISCARD int CheckChannel(Semantic semantic, int unit, const DataFormatTypeContainer& requiredTypes) const;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(VertexBuffer);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VertexBuffer);
}

#endif  // RENDERING_RESOURCES_VERTEX_BUFFER_H
