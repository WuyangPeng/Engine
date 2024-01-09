/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/29 13:48)

#ifndef RENDERING_RESOURCES_BUFFER_H
#define RENDERING_RESOURCES_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Resource.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Buffer : public Resource
    {
    public:
        using ClassType = Buffer;
        using ParentType = Resource;

    public:
        Buffer(const std::string& name, GraphicsObjectType type);
        Buffer(const std::string& name, int numElements, int elementSize, GraphicsObjectType type, bool createStorage = true);
        Buffer(const std::string& name, int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Buffer);

    protected:
        template <typename T>
        void CheckMember(const T& layout) const;

        template <typename T>
        void CheckMember(int index, const T& layout) const;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Buffer);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Buffer);
}

#endif  // RENDERING_RESOURCES_BUFFER_H
