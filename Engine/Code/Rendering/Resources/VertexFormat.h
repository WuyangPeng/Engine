///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/31 16:55)

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

        // �����������ڴ���һ�������ʽͨ��ָ�������������ԡ�
        // �����������ֻ��һ��ͨ�õ�������Ϊ��(��������δʵ���κ���ֵ)��
        NODISCARD static VertexFormatSharedPtr Create(const std::vector<VertexFormatType>& triple);

        NODISCARD static VertexFormatSharedPtr Create(const std::vector<VertexFormatElement>& triple);

        NODISCARD static VertexFormatSharedPtr LoadFromFile(ReadFileManager& manager);

        // ֧���ӳٹ��졣���ù��캯��֮�󣬱���ͨ��ʹ�� SetAttribute 'numAttributes'�������������ԡ�
        // �����ʱ������SetStride������һ���źţ�����������ɡ�Ȼ�󴴽���ص���Ⱦ��Դ��

        // ע�⣺VertexBufferAccessor�����Ķ�/д���������Ե�ƫ�ơ�
        // VertexFormat::Create��֤��һ�㣬����ҲӦ����ȷ��ʹ��SetAttribute��
        void SetAttribute(int attribute, int32_t streamIndex, int32_t offset, AttributeType type, AttributeUsage usage, int32_t usageIndex);

        NODISCARD int GetNumAttributes() const noexcept;

        NODISCARD int32_t GetStreamIndex(int attribute) const;
        NODISCARD int32_t GetOffset(int attribute) const;
        NODISCARD AttributeType GetAttributeType(int attribute) const;
        NODISCARD AttributeUsage GetAttributeUsage(int attribute) const;
        NODISCARD int32_t GetUsageIndex(int attribute) const;

        NODISCARD int GetStride() const noexcept;

        // ����ָ�����Ե�ʹ�������������ָ��ʹ������Ŀǰ�������ɫͨ������������ʹ�á�
        // �����Ե�ʹ�ó����ڸ�ʽ�У�����ֵ������i��0 <= i < GetNumAttributes()��
        // ������Ե�ʹ�ò������ڸ�ʽ�У�����ֵ��-1��
        NODISCARD int GetIndex(AttributeUsage usage, int32_t usageIndex = 0) const noexcept;

        // ���Ե�һ�����������ֽ�����
        NODISCARD static int GetComponentSize(AttributeType type) noexcept;

        // ���Բ�����������
        NODISCARD static int GetNumComponents(AttributeType type) noexcept;

        // ���Ե�����������ֽ�������
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
