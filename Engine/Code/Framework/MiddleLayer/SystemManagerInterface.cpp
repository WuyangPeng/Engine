/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 22:57)

#include "Framework/FrameworkExport.h"

#include "SystemManagerInterface.h"
#include "Flags/SystemMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "Detail/SystemManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::SystemManagerInterface::SystemManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      impl{ System::EnumCastUnderlying(SystemMiddleLayer::Count) },
      system{ environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SystemManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Input)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, ObjectLogic)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Message)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Event)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Resource)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Audio)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, CameraSystems)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Rendering)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Engine)

CoreTools::GlobalConfig Framework::SystemManagerInterface::GetGlobalConfig() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return system->GetGlobalConfig();
}

void Framework::SystemManagerInterface::SendSmtpTransportMessage(const std::string& title, const std::string& content)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return system->SendSmtpTransportMessage(title, content);
}

void Framework::SystemManagerInterface::ChangeDatabase(const String& databaseIndex, int64_t userId, const BasisDatabaseManager& basisDatabaseContainer)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return system->ChangeDatabase(databaseIndex, userId, basisDatabaseContainer);
}

Framework::SystemManagerInterface::BasisDatabaseManager Framework::SystemManagerInterface::SelectOne(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return system->SelectOne(databaseIndex, basisDatabaseContainer, fieldNameContainer);
}

Framework::SystemManagerInterface::ResultContainer Framework::SystemManagerInterface::SelectAll(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return system->SelectAll(databaseIndex, basisDatabaseContainer, fieldNameContainer);
}

bool Framework::SystemManagerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Paint();
}

bool Framework::SystemManagerInterface::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Move(point);
}

bool Framework::SystemManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Resize(windowDisplay, size);
}

bool Framework::SystemManagerInterface::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::KeyUp(key, point);
}

bool Framework::SystemManagerInterface::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::KeyDown(key, point);
}

bool Framework::SystemManagerInterface::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::SystemManagerInterface::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::SystemManagerInterface::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::PassiveMotion(point);
}

bool Framework::SystemManagerInterface::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::SystemManagerInterface::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::SystemManagerInterface::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}
