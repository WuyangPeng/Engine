// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/19 11:22)

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
        // �����������ڴ���һ�������ʽͨ��ָ�������������ԡ�
        // �����������ֻ��һ��ͨ�õ�������Ϊ��(��������δʵ���κ���ֵ)��
        static VertexFormatSharedPtr Create(const std::vector<VertexFormatType> triple);

        static VertexFormatSharedPtr Create(const std::vector<VertexFormatElement> triple);

        static VertexFormatSharedPtr LoadFromFile(ReadFileManager& manager);

        // ֧���ӳٹ��졣���ù��캯��֮�󣬱���ͨ��ʹ�� SetAttribute 'numAttributes'�������������ԡ�
        // �����ʱ������SetStride������һ���źţ�����������ɡ�Ȼ�󴴽���ص���Ⱦ��Դ��

        // ע�⣺VertexBufferAccessor�����Ķ�/д���������Ե�ƫ�ơ�
        // VertexFormat::Create��֤��һ�㣬����ҲӦ����ȷ��ʹ��SetAttribute��
        void SetAttribute(int attribute, unsigned int streamIndex, unsigned int offset,
                          AttributeType type, AttributeUsage usage, unsigned int usageIndex);

        int GetNumAttributes() const noexcept;

        unsigned int GetStreamIndex(int attribute) const;
        unsigned int GetOffset(int attribute) const;
        AttributeType GetAttributeType(int attribute) const;
        AttributeUsage GetAttributeUsage(int attribute) const;
        unsigned int GetUsageIndex(int attribute) const;

        int GetStride() const noexcept;

        // ����ָ�����Ե�ʹ�������������ָ��ʹ������Ŀǰ�������ɫͨ������������ʹ�á�
        // �����Ե�ʹ�ó����ڸ�ʽ�У�����ֵ������i��0 <= i < GetNumAttributes()��
        // ������Ե�ʹ�ò������ڸ�ʽ�У�����ֵ��-1��
        int GetIndex(AttributeUsage usage, unsigned int usageIndex = 0) const noexcept;

        // ���Ե�һ�����������ֽ�����
        static int GetComponentSize(AttributeType type) noexcept;

        // ���Բ�����������
        static int GetNumComponents(AttributeType type) noexcept;

        // ���Ե�����������ֽ�������
        static int GetTypeSize(AttributeType type) noexcept;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

        virtual VertexFormatSharedPtr Clone() const;

        void SetStride(int stride);
        ObjectInterfaceSharedPtr CloneObject() const override;
    public:
        // ��ʱ�ĳɹ���
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
