///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 14:41)

#ifndef FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_DETAIL_H

#include "EngineMiddleLayerContainer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                      InputManager,
                                      NetworkManager,
                                      ObjectLogicManager,
                                      PhysicalModellingManager,
                                      MessageManager,
                                      EventManager,
                                      SystemManager,
                                      ResourceManager,
                                      AudioManager,
                                      CameraSystemsManager,
                                      RenderingManager,
                                      GUIManager>::EngineMiddleLayerContainer(MiddleLayerPlatform modelViewController, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ modelViewController, environmentDirectory },
      network{ std::make_shared<NetworkManagerType>(modelViewController, environmentDirectory) },
      input{ std::make_shared<InputManagerType>(modelViewController, environmentDirectory) },
      objectLogic{ std::make_shared<ObjectLogicManagerType>(modelViewController, environmentDirectory) },
      physicalModelling{ std::make_shared<PhysicalModellingManagerType>(modelViewController, environmentDirectory) },
      message{ std::make_shared<MessageManagerType>(modelViewController, environmentDirectory) },
      event{ std::make_shared<EventManagerType>(modelViewController, environmentDirectory) },
      system{ std::make_shared<SystemManagerType>(modelViewController, environmentDirectory) },
      resource{ std::make_shared<ResourceManagerType>(modelViewController, environmentDirectory) },
      audio{ std::make_shared<AudioManagerType>(modelViewController, environmentDirectory) },
      cameraSystems{ std::make_shared<CameraSystemsManagerType>(modelViewController, environmentDirectory) },
      rendering{ std::make_shared<RenderingManagerType>(modelViewController, environmentDirectory) },
      gui{ std::make_shared<GUIManagerType>(modelViewController, environmentDirectory) }
{
    Init();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::Init()
{
    InitNetworkManager();
    InitInputManager();
    InitObjectLogicManager();
    InitPhysicalModellingManager();
    InitMessageManager();
    InitEventManager();
    InitSystemManager();
    InitResourceManager();
    InitAudioManager();
    InitCameraSystemsManager();
    InitRenderingManager();
    InitGUIManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitNetworkManager()
{
    network->SetInputManager(input);
    network->SetObjectLogicManager(objectLogic);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitInputManager()
{
    input->SetNetworkManager(network);
    input->SetObjectLogicManager(objectLogic);
    input->SetSystemManager(system);
    input->SetCameraSystemsManager(cameraSystems);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitObjectLogicManager()
{
    objectLogic->SetNetworkManager(network);
    objectLogic->SetInputManager(input);
    objectLogic->SetPhysicalModellingManager(physicalModelling);
    objectLogic->SetMessageManager(message);
    objectLogic->SetSystemManager(system);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitPhysicalModellingManager()
{
    physicalModelling->SetObjectLogicManager(objectLogic);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitMessageManager()
{
    message->SetObjectLogicManager(objectLogic);
    message->SetSystemManager(system);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitEventManager()
{
    event->SetMessageManager(message);
    event->SetSystemManager(system);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitSystemManager()
{
    system->SetInputManager(input);
    system->SetObjectLogicManager(objectLogic);
    system->SetMessageManager(message);
    system->SetEventManager(event);
    system->SetResourceManager(resource);
    system->SetAudioManager(audio);
    system->SetCameraSystemsManager(cameraSystems);
    system->SetRenderingManager(rendering);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitResourceManager()
{
    resource->SetSystemManager(system);
    resource->SetAudioManager(audio);
    resource->SetRenderingManager(rendering);
    resource->SetGUIManager(gui);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitAudioManager()
{
    audio->SetSystemManager(system);
    audio->SetResourceManager(resource);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitCameraSystemsManager()
{
    cameraSystems->SetSystemManager(system);
    cameraSystems->SetRenderingManager(rendering);
    cameraSystems->SetGUIManager(gui);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitRenderingManager()
{
    rendering->SetSystemManager(system);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitGUIManager()
{
    gui->SetRenderingManager(rendering);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                      InputManager,
                                      NetworkManager,
                                      ObjectLogicManager,
                                      PhysicalModellingManager,
                                      MessageManager,
                                      EventManager,
                                      SystemManager,
                                      ResourceManager,
                                      AudioManager,
                                      CameraSystemsManager,
                                      RenderingManager,
                                      GUIManager>::EngineMiddleLayerContainer(EngineMiddleLayerContainer&& rhs) noexcept
    : ParentType{ std::move(rhs) },
      network{ std::move(rhs.network) },
      input{ std::move(rhs.input) },
      objectLogic{ std::move(rhs.objectLogic) },
      physicalModelling{ std::move(rhs.physicalModelling) },
      message{ std::move(rhs.message) },
      event{ std::move(rhs.event) },
      system{ std::move(rhs.system) },
      resource{ std::move(rhs.resource) },
      audio{ std::move(rhs.audio) },
      cameraSystems{ std::move(rhs.cameraSystems) },
      rendering{ std::move(rhs.rendering) },
      gui{ std::move(rhs.gui) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                      InputManager,
                                      NetworkManager,
                                      ObjectLogicManager,
                                      PhysicalModellingManager,
                                      MessageManager,
                                      EventManager,
                                      SystemManager,
                                      ResourceManager,
                                      AudioManager,
                                      CameraSystemsManager,
                                      RenderingManager,
                                      GUIManager>&
    Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                          InputManager,
                                          NetworkManager,
                                          ObjectLogicManager,
                                          PhysicalModellingManager,
                                          MessageManager,
                                          EventManager,
                                          SystemManager,
                                          ResourceManager,
                                          AudioManager,
                                          CameraSystemsManager,
                                          RenderingManager,
                                          GUIManager>::operator=(EngineMiddleLayerContainer&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));
    network = std::move(rhs.network);
    input = std::move(rhs.input);
    objectLogic = std::move(rhs.objectLogic);
    physicalModelling = std::move(rhs.physicalModelling);
    message = std::move(rhs.message);
    event = std::move(rhs.event);
    system = std::move(rhs.system);
    resource = std::move(rhs.resource);
    audio = std::move(rhs.audio);
    cameraSystems = std::move(rhs.cameraSystems);
    rendering = std::move(rhs.rendering);
    gui = std::move(rhs.gui);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::IsValid() const noexcept
{
    if (ParentType::IsValid() &&
        network != nullptr &&
        input != nullptr &&
        objectLogic != nullptr &&
        physicalModelling != nullptr &&
        message != nullptr &&
        event != nullptr &&
        system != nullptr &&
        resource != nullptr &&
        audio != nullptr &&
        cameraSystems != nullptr &&
        rendering != nullptr &&
        gui != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    input = boost::polymorphic_pointer_downcast<InputManagerInterface>(inputManager);

    InitInputManager();
    ResetInputManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    network = boost::polymorphic_pointer_downcast<NetworkManagerInterface>(networkManager);

    InitNetworkManager();
    ResetNetworkManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetObjectLogicManager(const MiddleLayerInterfaceSharedPtr& objectLogicManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    objectLogic = boost::polymorphic_pointer_downcast<ObjectLogicManagerInterface>(objectLogicManager);

    InitObjectLogicManager();
    ResetObjectLogicManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    physicalModelling = boost::polymorphic_pointer_downcast<PhysicalModellingManagerInterface>(physicalModellingManager);

    InitPhysicalModellingManager();
    ResetPhysicalModellingManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    message = boost::polymorphic_pointer_downcast<MessageManagerInterface>(messageManager);

    InitMessageManager();
    ResetMessageManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetEventManager(const MiddleLayerInterfaceSharedPtr& eventManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    event = boost::polymorphic_pointer_downcast<EventManagerInterface>(eventManager);

    InitEventManager();
    ResetEventManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    system = boost::polymorphic_pointer_downcast<SystemManagerInterface>(systemManager);

    InitSystemManager();

    if (!InitSystemEngineInterface())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("InitSystemEngineInterface失败。"));
    }

    ResetSystemManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetResourceManager(const MiddleLayerInterfaceSharedPtr& resourceManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    resource = boost::polymorphic_pointer_downcast<ResourceManagerInterface>(resourceManager);

    InitResourceManager();
    ResetResourceManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetAudioManager(const MiddleLayerInterfaceSharedPtr& audioManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    audio = boost::polymorphic_pointer_downcast<AudioManagerInterface>(audioManager);

    InitAudioManager();
    ResetAudioManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetCameraSystemsManager(const MiddleLayerInterfaceSharedPtr& cameraSystemsManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    cameraSystems = boost::polymorphic_pointer_downcast<CameraSystemsManagerInterface>(cameraSystemsManager);

    InitCameraSystemsManager();
    ResetCameraSystemsManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetRenderingManager(const MiddleLayerInterfaceSharedPtr& renderingManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    rendering = boost::polymorphic_pointer_downcast<RenderingManagerInterface>(renderingManager);

    InitRenderingManager();
    ResetRenderingManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SetGUIManager(const MiddleLayerInterfaceSharedPtr& guiManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    gui = boost::polymorphic_pointer_downcast<GUIManagerInterface>(guiManager);

    InitGUIManager();
    ResetGUIManager();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetNetworkManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    input->SetNetworkManager(network);
    objectLogic->SetNetworkManager(network);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetInputManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    network->SetInputManager(input);
    objectLogic->SetInputManager(input);
    system->SetInputManager(input);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetObjectLogicManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    network->SetObjectLogicManager(objectLogic);
    input->SetObjectLogicManager(objectLogic);
    physicalModelling->SetObjectLogicManager(objectLogic);
    message->SetObjectLogicManager(objectLogic);
    system->SetObjectLogicManager(objectLogic);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetPhysicalModellingManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    objectLogic->SetPhysicalModellingManager(physicalModelling);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetMessageManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    objectLogic->SetMessageManager(message);
    event->SetMessageManager(message);
    system->SetMessageManager(message);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetEventManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    system->SetEventManager(event);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetSystemManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    input->SetSystemManager(system);
    objectLogic->SetSystemManager(system);
    message->SetSystemManager(system);
    event->SetSystemManager(system);
    resource->SetSystemManager(system);
    audio->SetSystemManager(system);
    cameraSystems->SetSystemManager(system);
    rendering->SetSystemManager(system);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetResourceManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    system->SetResourceManager(resource);
    audio->SetResourceManager(resource);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetAudioManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    system->SetAudioManager(audio);
    resource->SetAudioManager(audio);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetCameraSystemsManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    input->SetCameraSystemsManager(cameraSystems);
    system->SetCameraSystemsManager(cameraSystems);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetRenderingManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    system->SetRenderingManager(rendering);
    resource->SetRenderingManager(rendering);
    cameraSystems->SetRenderingManager(rendering);
    gui->SetRenderingManager(rendering);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::ResetGUIManager()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    resource->SetGUIManager(gui);
    cameraSystems->SetGUIManager(gui);
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::PreCreate() &&
        InitSystemEngineInterface() &&
        system->PreCreate() &&
        network->PreCreate() &&
        input->PreCreate() &&
        objectLogic->PreCreate() &&
        physicalModelling->PreCreate() &&
        message->PreCreate() &&
        event->PreCreate() &&
        audio->PreCreate() &&
        resource->PreCreate() &&
        cameraSystems->PreCreate() &&
        gui->PreCreate() &&
        rendering->PreCreate())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Initialize() &&
        system->Initialize() &&
        network->Initialize() &&
        input->Initialize() &&
        objectLogic->Initialize() &&
        physicalModelling->Initialize() &&
        message->Initialize() &&
        event->Initialize() &&
        audio->Initialize() &&
        resource->Initialize() &&
        cameraSystems->Initialize() &&
        gui->Initialize() &&
        rendering->Initialize())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::PreIdle();
    system->PreIdle();
    network->PreIdle();
    input->PreIdle();
    objectLogic->PreIdle();
    physicalModelling->PreIdle();
    message->PreIdle();
    event->PreIdle();
    audio->PreIdle();
    resource->PreIdle();
    cameraSystems->PreIdle();
    gui->PreIdle();
    rendering->PreIdle();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::Terminate();
    network->Terminate();
    input->Terminate();
    objectLogic->Terminate();
    physicalModelling->Terminate();
    message->Terminate();
    event->Terminate();
    audio->Terminate();
    resource->Terminate();
    cameraSystems->Terminate();
    gui->Terminate();
    system->Terminate();
    rendering->Terminate();
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Paint() &&
        rendering->Paint())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Move(point) &&
        rendering->Move(point))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Resize(windowDisplay, size) &&
        rendering->Resize(windowDisplay, size))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::KeyDown(key, point) &&
        input->KeyDown(key, point))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::KeyUp(key, point) &&
        input->KeyUp(key, point))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::SpecialKeyDown(key, point) &&
        input->SpecialKeyDown(key, point))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::SpecialKeyUp(key, point) &&
        input->SpecialKeyUp(key, point))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::MouseClick(button, state, point, virtualKeys) &&
        input->MouseClick(button, state, point, virtualKeys))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Motion(point, virtualKeys) &&
        input->Motion(point, virtualKeys))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::PassiveMotion(point) &&
        input->PassiveMotion(point))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::MouseWheel(delta, point, virtualKeys) &&
        input->MouseWheel(delta, point, virtualKeys))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::Create(const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Create(environmentParameter) &&
        system->Create(environmentParameter) &&
        network->Create(environmentParameter) &&
        input->Create(environmentParameter) &&
        objectLogic->Create(environmentParameter) &&
        physicalModelling->Create(environmentParameter) &&
        message->Create(environmentParameter) &&
        event->Create(environmentParameter) &&
        audio->Create(environmentParameter) &&
        resource->Create(environmentParameter) &&
        cameraSystems->Create(environmentParameter) &&
        gui->Create(environmentParameter) &&
        rendering->Create(environmentParameter))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Destroy() &&
        network->Destroy() &&
        input->Destroy() &&
        objectLogic->Destroy() &&
        physicalModelling->Destroy() &&
        message->Destroy() &&
        event->Destroy() &&
        audio->Destroy() &&
        resource->Destroy() &&
        cameraSystems->Destroy() &&
        gui->Destroy() &&
        rendering->Destroy() &&
        system->Destroy())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::Idle(int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Idle(timeDelta) &&
        system->Idle(timeDelta) &&
        network->Idle(timeDelta) &&
        input->Idle(timeDelta) &&
        objectLogic->Idle(timeDelta) &&
        physicalModelling->Idle(timeDelta) &&
        message->Idle(timeDelta) &&
        event->Idle(timeDelta) &&
        audio->Idle(timeDelta) &&
        resource->Idle(timeDelta) &&
        cameraSystems->Idle(timeDelta) &&
        gui->Idle(timeDelta) &&
        rendering->Idle(timeDelta))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait,
          template <typename> class InputManager,
          typename NetworkManager,
          typename ObjectLogicManager,
          typename PhysicalModellingManager,
          typename MessageManager,
          typename EventManager,
          typename SystemManager,
          typename ResourceManager,
          typename AudioManager,
          typename CameraSystemsManager,
          typename RenderingManager,
          typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,
                                           InputManager,
                                           NetworkManager,
                                           ObjectLogicManager,
                                           PhysicalModellingManager,
                                           MessageManager,
                                           EventManager,
                                           SystemManager,
                                           ResourceManager,
                                           AudioManager,
                                           CameraSystemsManager,
                                           RenderingManager,
                                           GUIManager>::InitSystemEngineInterface()
{
    system->SetEngineManager(shared_from_this());

    return true;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_DETAIL_H
