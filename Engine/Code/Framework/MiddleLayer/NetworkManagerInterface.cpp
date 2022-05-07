///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 13:51)

#include "Framework/FrameworkExport.h"

#include "NetworkManagerInterface.h"
#include "Flags/MiddleLayerPlatformFlags.h"
#include "Flags/NetworkMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "Detail/NetworkManagerImpl.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using std::make_shared;
using std::move;
using namespace std::literals;

Framework::NetworkManagerInterface::NetworkManagerInterface(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform },
      impl{ System::EnumCastUnderlying(NetworkMiddleLayer::Count) },
      networkManager{ make_shared<NetworkManagerImpl>() }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::NetworkManagerInterface::NetworkManagerInterface(NetworkManagerInterface&& rhs) noexcept
    : ParentType{ move(rhs) }, impl{ move(rhs.impl) }, networkManager{ move(rhs.networkManager) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::NetworkManagerInterface& Framework::NetworkManagerInterface::operator=(NetworkManagerInterface&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(move(rhs));

    impl = move(rhs.impl);

    networkManager = move(rhs.networkManager);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::NetworkManagerInterface::IsValid() const noexcept
{
    if (ParentType::IsValid() && networkManager != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool Framework::NetworkManagerInterface::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::PreCreate(environmentDirectory))
    {
        // 连接服务器和监听客户端。

        auto networkFileName = environmentDirectory.GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Network.json");

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
    FRAMEWORK_CLASS_IS_VALID_1;

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

// private
void Framework::NetworkManagerInterface::RegisteredMessages()
{
    CoreTools::DisableNoexcept();
}

bool Framework::NetworkManagerInterface::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_1;

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
    FRAMEWORK_CLASS_IS_VALID_1;

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

void Framework::NetworkManagerInterface::Send(const Network::SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    networkManager->Send(socketData, socketID, message);
}

// protected
Framework::NetworkManagerInterface::SendSocketManagerSharedPtr Framework::NetworkManagerInterface::GetSendSocketManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto sendSocketManager = networkManager->GetSendSocketManager();

    if (sendSocketManager != nullptr)
    {
        return sendSocketManager;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("网络管理器不存在！"s));
    }
}

// protected
Network::ConstSendSocketManagerSharedPtr Framework::NetworkManagerInterface::GetSendSocketManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    auto sendSocketManager = networkManager->GetSendSocketManager();

    if (sendSocketManager != nullptr)
    {
        return sendSocketManager;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("网络管理器不存在！"s));
    }
}

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Network, Input)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Network, ObjectLogic)

bool Framework::NetworkManagerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Paint();
}

bool Framework::NetworkManagerInterface::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Move(point);
}

bool Framework::NetworkManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Resize(windowDisplay, size);
}

bool Framework::NetworkManagerInterface::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyUp(key, point);
}

bool Framework::NetworkManagerInterface::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyDown(key, point);
}

bool Framework::NetworkManagerInterface::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::NetworkManagerInterface::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::NetworkManagerInterface::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::PassiveMotion(point);
}

bool Framework::NetworkManagerInterface::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::NetworkManagerInterface::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::NetworkManagerInterface::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}
