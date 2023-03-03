///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/11 10:54)

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

        // �����������ڴ���һ�������ʽͨ��ָ�������������ԡ�
        // �����������ֻ��һ��ͨ�õ�������Ϊ��(��������δʵ���κ���ֵ)��
        NODISCARD static VertexFormatSharedPtr Create(const AttributeContainer& triple);

        NODISCARD static VertexFormatSharedPtr LoadFromFile(ReadFileManager& manager);

        // ֧���ӳٹ��졣���ù��캯��֮�󣬱���ͨ��ʹ�� SetAttribute 'numAttributes'�������������ԡ�
        // �����ʱ������SetStride������һ���źţ�����������ɡ�Ȼ�󴴽���ص���Ⱦ��Դ��

        // ע�⣺VertexBuffer�����Ķ�/д���������Ե�ƫ�ơ�
        // VertexFormat::Create��֤��һ�㣬����ҲӦ����ȷ��ʹ��SetAttribute��
        void SetAttribute(int attribute, DataFormatType type, Semantic usage, int usageIndex, int offset);

        NODISCARD int GetNumAttributes() const noexcept;

        NODISCARD int GetOffset(int attribute) const;
        NODISCARD DataFormatType GetAttributeType(int attribute) const;
        NODISCARD Semantic GetAttributeUsage(int attribute) const;
        NODISCARD int GetUsageIndex(int attribute) const;

        NODISCARD int GetStride() const noexcept;
        void SetStride(int stride);

        // ����ָ�����Ե�ʹ�������������ָ��ʹ������Ŀǰ�������ɫͨ������������ʹ�á�
        // �����Ե�ʹ�ó����ڸ�ʽ�У�����ֵ������i��0 <= i < GetNumAttributes()��
        // ������Ե�ʹ�ò������ڸ�ʽ�У�����ֵ��-1��
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
