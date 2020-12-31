// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:49)

#ifndef FRAMEWORK_MIDDLE_LAYER_FWD_H
#define FRAMEWORK_MIDDLE_LAYER_FWD_H

namespace Framework
{
	enum class MiddleLayerPlatform;
	enum class AudioMiddleLayer;
	enum class CameraSystemsMiddleLayer;
	enum class EventMiddleLayer;
	enum class GUIMiddleLayer;
	enum class InputMiddleLayer;
	enum class MessageMiddleLayer;
	enum class NetworkMiddleLayer;
	enum class ObjectLogicMiddleLayer;
	enum class PhysicalModellingMiddleLayer;
	enum class RenderingMiddleLayer;
	enum class ResourceMiddleLayer;
	enum class SystemMiddleLayer;

	class MiddleLayerInterface;
	class ModelViewControllerMiddleLayer;

	template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
	class ModelViewControllerMiddleLayerContainer;

	class ModelMiddleLayer;
	class ViewMiddleLayer;

	template <typename ApplicationTrait>
	class ControllerMiddleLayer;

	class PixelViewMiddleLayer;
	class CameraModelMiddleLayer;
	class CameraViewMiddleLayer;

	template <typename ApplicationTrait>
	class CameraControllerMiddleLayer;

	class EngineMiddleLayerInterface;
	class NetworkManagerInterface;
	class ObjectLogicManagerInterface;

	template<typename ObjectLogic, typename ArtificialIntellegence>
	class ObjectLogicManager;

	class ObjectLogicInterface;
	class ArtificialIntellegenceInterface;
	class InputManagerInterface;

	template <typename ApplicationTrait>
	class InputManager;

	class PhysicalModellingManagerInterface;
	class MessageManagerInterface;
	class EventManagerInterface;
	class SystemManagerInterface;
	class ResourceManagerInterface;
	class AudioManagerInterface;
	class CameraSystemsManagerInterface;
	class RenderingManagerInterface;
	class GUIManagerInterface;

	template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
			  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
			  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
	class EngineMiddleLayerContainer;
}

#endif // FRAMEWORK_MIDDLE_LAYER_FWD_H