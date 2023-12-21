/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/18 15:01)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "VertexFormatAttribute.h"
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
        using AttributeContainer = std::vector<VertexFormatAttribute>;

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VertexFormat);

        NODISCARD static VertexFormatSharedPtr Create(const std::string& name);

        // �����������ڴ���һ�������ʽͨ��ָ�������������ԡ�
        // �����������ֻ��һ��ͨ�õ�������Ϊ��(��������δʵ���κ���ֵ)��
        NODISCARD static VertexFormatSharedPtr Create(const std::string& name, const AttributeContainer& triple);

        NODISCARD int GetNumAttributes() const noexcept;

        NODISCARD int GetOffset(int attribute) const;
        NODISCARD DataFormatType GetAttributeType(int attribute) const;
        NODISCARD Semantic GetSemantic(int attribute) const;
        NODISCARD int GetUnit(int attribute) const;

        NODISCARD int GetVertexSize() const noexcept;

        // ����ָ�����Ե�ʹ�������������ָ��ʹ������Ŀǰ�������ɫͨ������������ʹ�á�
        // �����Ե�ʹ�ó����ڸ�ʽ�У�����ֵ������i��0 <= i < GetNumAttributes()��
        // ������Ե�ʹ�ò������ڸ�ʽ�У�����ֵ��-1��
        NODISCARD int GetIndex(Semantic semantic, int unit = 0) const noexcept;

        /// ֧���ڷ�Χ������VertexFormat���󡣴˵��ý���������ΪĬ�Ϲ��캯�����ò�����״̬��
        void Reset() noexcept;

        /// ����һ��ѹ�������ʽ�����������������ڴ��ж��������ġ����Ե�˳����Bind���õ�˳�������
        void Bind(DataFormatType type, Semantic semantic, int unit);

        NODISCARD virtual VertexFormatSharedPtr Clone() const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        enum class VertexFormatCreate
        {
            Init,
        };

    public:
        VertexFormat(VertexFormatCreate vertexFormatCreate, const std::string& name, int numAttributes);

    private:
        // ֧���ӳٹ��졣���ù��캯��֮�󣬱���ͨ��ʹ�� SetAttribute 'numAttributes'�������������ԡ�
        // �����ʱ������SetVertexSize������һ���źţ�����������ɡ�Ȼ�󴴽���ص���Ⱦ��Դ��

        // ע�⣺VertexBuffer�����Ķ�/д���������Ե�ƫ�ơ�
        // VertexFormat::Create��֤��һ�㣬����ҲӦ����ȷ��ʹ��SetAttribute��
        void SetAttribute(int attribute, DataFormatType type, Semantic semantic, int unit, int offset);

        void SetAttribute(int attribute, const VertexFormatAttribute& vertexFormatElement);

        void SetVertexSize(int vertexSize);

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(VertexFormat);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VertexFormat);
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_H
