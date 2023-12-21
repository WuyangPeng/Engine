/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/18 15:01)

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

        // 便利函数用于创建一个顶点格式通过指定它的所有属性。
        // 现在这个工作只有一个通用的流索引为零(流索引尚未实现任何数值)。
        NODISCARD static VertexFormatSharedPtr Create(const std::string& name, const AttributeContainer& triple);

        NODISCARD int GetNumAttributes() const noexcept;

        NODISCARD int GetOffset(int attribute) const;
        NODISCARD DataFormatType GetAttributeType(int attribute) const;
        NODISCARD Semantic GetSemantic(int attribute) const;
        NODISCARD int GetUnit(int attribute) const;

        NODISCARD int GetVertexSize() const noexcept;

        // 返回指定属性的使用情况的索引。指定使用索引目前仅针对颜色通道和纹理坐标使用。
        // 当属性的使用出现在格式中，返回值的索引i在0 <= i < GetNumAttributes()。
        // 如果属性的使用不出现在格式中，返回值是-1。
        NODISCARD int GetIndex(Semantic semantic, int unit = 0) const noexcept;

        /// 支持在范围内重用VertexFormat对象。此调用将对象重置为默认构造函数调用产生的状态。
        void Reset() noexcept;

        /// 创建一个压缩顶点格式，其中所有属性在内存中都是连续的。属性的顺序由Bind调用的顺序决定。
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
        // 支持延迟构造。调用构造函数之后，必须通过使用 SetAttribute 'numAttributes'次设置所有属性。
        // 当完成时，调用SetVertexSize，这是一个信号，即构造已完成。然后创建相关的渲染资源。

        // 注意：VertexBuffer所述的读/写条件是属性的偏移。
        // VertexFormat::Create保证这一点，但你也应该明确的使用SetAttribute。
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
