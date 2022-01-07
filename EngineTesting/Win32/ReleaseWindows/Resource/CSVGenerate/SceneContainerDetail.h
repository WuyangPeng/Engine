/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#ifndef C_S_V_CONFIGURE_SCENE_CONTAINER_DETAIL_H
#define C_S_V_CONFIGURE_SCENE_CONTAINER_DETAIL_H

#include "SceneContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
CSVConfigure::SceneContainer::ConstSceneSharedPtr CSVConfigure::SceneContainer::GetFirstScene(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    for (const auto& value : scene)
    {
        if (function(value.second))
        {
            return value.second;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("scene��δ�ҵ�����������������Ϣ��"s));
}

template <typename Function>
CSVConfigure::SceneContainer::Container CSVConfigure::SceneContainer::GetScene(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& value : scene)
    {
        if (function(value.second))
        {
            result.emplace_back(value.second);
        }
    }

    return result;
}

#endif  // C_S_V_CONFIGURE_SCENE_CONTAINER_DETAIL_H
