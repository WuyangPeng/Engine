///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 16:23)

#include "Framework/FrameworkExport.h"

#include "NetworkManagerInterface.h"
#include "Flags/MiddleLayerPlatformFlags.h"
#include "Flags/NetworkMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "Detail/NetworkManagerImpl.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

Framework::NetworkManagerInterface::NetworkManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      impl{ System::EnumCastUnderlying(NetworkMiddleLayer::Count) },
      networkManager{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, NetworkManagerInterface)

bool Framework::NetworkManagerInterface::Create(const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Create(environmentParameter))
    {
        // 连接服务器和监听客户端。
        const auto networkFileName = GetEnvironmentDirectory().GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Network.json");

        networkManager->ResetSendSocketManager(CoreTools::StringConversion::StandardConversionMultiByte(networkFileName));

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::NetworkManagerInterface::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Initialize())
    {
        // 子类在这里注册消息。
        RegisteredMessages();

        return true;
    }
    else
    {
        return false;
    }
}

void Framework::NetworkManagerInterface::RegisteredMessages()
{
    CoreTools::DisableNoexcept();
}

bool Framework::NetworkManagerInterface::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Destroy())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::NetworkManagerInterface::Idle(int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Idle(timeDelta))
    {
        // 发送和接收消息

        return true;
    }
    else
    {
        return false;
    }
}

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Network, Input)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Network, ObjectLogic)

bool Framework::NetworkManagerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Paint();
}

bool Framework::NetworkManagerInterface::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Move(point);
}

bool Framework::NetworkManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Resize(windowDisplay, size);
}

bool Framework::NetworkManagerInterface::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::KeyUp(key, point);
}

bool Framework::NetworkManagerInterface::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::KeyDown(key, point);
}

bool Framework::NetworkManagerInterface::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::NetworkManagerInterface::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::NetworkManagerInterface::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::PassiveMotion(point);
}

bool Framework::NetworkManagerInterface::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::NetworkManagerInterface::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::NetworkManagerInterface::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}
