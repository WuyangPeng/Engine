/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/12 15:09)

#ifndef RENDERING_RESOURCES_SUITE_RESOURCES_TEST_H
#define RENDERING_RESOURCES_SUITE_RESOURCES_TEST_H

#include "Rendering/Resources/Resource.h"

namespace Rendering
{
    class ResourcesTest final : public Resource
    {
    public:
        using ClassType = ResourcesTest;
        using ParentType = Resource;

    public:
        ResourcesTest(const std::string& name, GraphicsObjectType type);
        ResourcesTest(const std::string& name, int numElements, int elementSize, GraphicsObjectType type, bool createStorage);
        ResourcesTest(const std::string& name, int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ResourcesTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ResourcesTest);

#include SYSTEM_WARNING_POP

}

#endif  // RENDERING_RESOURCES_SUITE_RESOURCES_TEST_H