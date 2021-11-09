/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#ifndef C_S_V_CONFIGURE_SCENE_CONTAINER_H
#define C_S_V_CONFIGURE_SCENE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <unordered_map>
#include <vector>

namespace CSVConfigure
{
    class SceneContainer final
    {
    public:
        using ClassType = SceneContainer;
        using ConstSceneSharedPtr = std::shared_ptr<const Scene>;
        using MappingContainer = std::unordered_map<int, ConstSceneSharedPtr>;
        using Container = std::vector<ConstSceneSharedPtr>;

    public:
        explicit SceneContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSceneSharedPtr GetFirstScene() const;
        NODISCARD ConstSceneSharedPtr GetScene(int key) const;
        NODISCARD MappingContainer GetContainer() const;

        template <typename Function>
        NODISCARD ConstSceneSharedPtr GetFirstScene(Function function) const;

        template <typename Function>
        NODISCARD Container GetScene(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        MappingContainer scene;
    };
}

#endif  // C_S_V_CONFIGURE_SCENE_CONTAINER_H
