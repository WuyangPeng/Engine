/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/11 19:33)

#ifndef RENDERING_RESOURCES_RESOURCE_H
#define RENDERING_RESOURCES_RESOURCE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/Base/GraphicsObject.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Resource, ResourceImpl);

// ��������������Դ������ϵͳ�ڴ�洢�������Դ������ΪGPU��Դ�����ṩ��Ϣ��������һ����Ҫϵͳ�ڴ档
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Resource : public GraphicsObject
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Resource);
        using ParentType = GraphicsObject;

        using StorageType = std::vector<char>;
        using SpanIterator = CoreTools::SpanIterator<StorageType::iterator>;
        using ConstSpanIterator = CoreTools::SpanIterator<StorageType::const_iterator>;

    public:
        // Ĭ�ϵ�UsageTypeΪUsageType::Immutable��
        Resource(const std::string& name, GraphicsObjectType type);
        Resource(const std::string& name, int numElements, int elementSize, GraphicsObjectType type, bool createStorage = true);
        Resource(const std::string& name, int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Resource);

        NODISCARD bool IsCreateStorage() const noexcept;

        /// ��������������Դ������ϵͳ�ڴ�洢��
        /// �����Դ������ΪGPU��Դ�����ṩ��Ϣ��������һ����Ҫϵͳ�ڴ档
        void CreateStorage();
        void DestroyStorage();

        NODISCARD int GetNumElements() const noexcept;
        NODISCARD int GetElementSize() const noexcept;
        NODISCARD int GetNumBytes() const noexcept;

        void SetUsage(UsageType usageType) noexcept;
        NODISCARD UsageType GetUsage() const noexcept;

        void SetCopy(CopyType copyType) noexcept;
        NODISCARD CopyType GetCopy() const noexcept;

        /// ָ����Դ�лԪ�ص������顣һ��Ԫ��ռ��elementSize�ֽڡ�
        /// ������������ΪԪ�����飬offset�ǵ�һ���Ԫ�ص�������Ҳ����˵����һ��Ԫ�ؾ��е�ַ��
        /// data + offset * elementSize
        /// ƫ������������
        /// offset < numElements
        /// �Ԫ�ص�����ΪnumActiveElements�����������㣺
        /// nNumActiveElements <= numElements - offset
        /// ����ƻ�ͬʱ�޸�ͬһ�����offset��numActiveElements��
        /// ����SetNumActiveElement()֮ǰ����SetOffset()����Ϊ�����Լ��������ƫ������
        void SetOffset(int offset);
        NODISCARD int GetOffset() const noexcept;

        void SetNumActiveElements(int numActiveElements);
        NODISCARD int GetNumActiveElements() const noexcept;
        NODISCARD int GetNumActiveBytes() const noexcept;

        NODISCARD ConstSpanIterator GetStorage() const noexcept;
        NODISCARD SpanIterator GetStorage() noexcept;

        NODISCARD ConstSpanIterator GetStorage(int offset) const;
        NODISCARD SpanIterator GetStorage(int offset);

        void SetStorage(const StorageType& storage);

        // ͬϵͳAPI�Ľ�����
        NODISCARD const char* GetOriginalData() const;
        NODISCARD const char* GetOriginalData(int offset) const;

        NODISCARD char* GetOriginalData();
        NODISCARD char* GetOriginalData(int offset);

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Resource);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Resource);
}

#endif  // RENDERING_RESOURCES_RESOURCE_H