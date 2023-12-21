/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/13 14:45)

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

        /// ��ʹ�õ�һ�����캯��ʱ������StandardUsage()����true��
        /// ��ʹ�õڶ������캯��ʱ����false��
        NODISCARD bool StandardUsage() const noexcept;

        /// ��ȡָ��ָ������͵�λ���������ݣ�������ڣ���ָ�롣
        /// ���⣬����Ҫ������������������б�λ��־���е�һ����
        /// ������������ͣ���Ϊ��������봫��Unknown��
        /// �������ʧ�ܣ����׳�һ���쳣��
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
        /// �˹��캯�������ڹ�դ����ʹ�ö��㻺�����򶥵���ɫ���ṩ����ı�׼��;��
        VertexBuffer(VertexBufferCreate vertexBufferCreate, const std::string& name, const VertexFormat& format, int numVertices, bool createStorage);

        /// �˹��캯�����ڻ��ڶ���id�Ļ��ƣ����ж����ǴӶ�����ɫ���еĽṹ����������Դ��ȡ�ġ�
        /// ����structuredBuffer����Ϊ��nullptr�������䶥���������Ƶ�'this'��������
        VertexBuffer(VertexBufferCreate vertexBufferCreate, const std::string& name, const VertexFormat& format, const StructuredBuffer& structuredBuffer);

        /// �˹��캯�����ڲ���Ҫ����Ļ��ڶ���id�Ļ�ͼ��
        /// ���磬��ɫ��������Ը��ݱ�ʶ������λ�á�
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
