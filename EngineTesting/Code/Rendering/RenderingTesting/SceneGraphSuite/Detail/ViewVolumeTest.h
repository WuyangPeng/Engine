/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/22 12:31)

#ifndef RENDERING_SCENE_GRAPH_SUITE_VIEW_VOLUME_TEST_H
#define RENDERING_SCENE_GRAPH_SUITE_VIEW_VOLUME_TEST_H

#include "Rendering/SceneGraph/ViewVolume.h"

namespace Rendering
{
    class ViewVolumeTest final : public ViewVolume
    {
    public:
        using ClassType = ViewVolumeTest;
        using ParentType = ViewVolume;

        using ViewVolumeTestSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static ViewVolumeTestSharedPtr Create(bool isPerspective, DepthType depthType, float epsilon);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ViewVolumeTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        enum class Constructor
        {
            Default,
        };

    public:
        ViewVolumeTest(bool isPerspective, DepthType depthType, float epsilon, Constructor constructor);

    protected:
        void UpdateProjectionViewMatrix() noexcept override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ViewVolumeTest);

#include SYSTEM_WARNING_POP
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_VIEW_VOLUME_TEST_H