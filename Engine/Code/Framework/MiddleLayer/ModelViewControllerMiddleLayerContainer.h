// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:49)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_H

#include "ModelViewControllerMiddleLayer.h"

#include <type_traits> 

namespace Framework
{
	template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer,
			  template<typename> class ControllerMiddleLayer>
	class ModelViewControllerMiddleLayerContainer final : public MiddleLayerInterface
	{
	public:
		static_assert(std::is_base_of_v<ModelViewControllerMiddleLayer, ModelMiddleLayer>);
		static_assert(std::is_base_of_v<ModelViewControllerMiddleLayer, ViewMiddleLayer>);
		static_assert(std::is_base_of_v<ModelViewControllerMiddleLayer, ControllerMiddleLayer<ApplicationTrait>>);

	public:
		using ClassType = ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>;
		using ParentType = MiddleLayerInterface;
		using ClassShareType = CoreTools::NonCopyClasses;
		using ModelMiddleLayerType = ModelMiddleLayer;
		using ViewMiddleLayerType = ViewMiddleLayer;
		using ControllerMiddleLayerType = ControllerMiddleLayer<ApplicationTrait>;
		using MiddleLayerSharedPtr = ModelViewControllerMiddleLayerSharedPtr;

	public:
		explicit ModelViewControllerMiddleLayerContainer(MiddleLayerPlatform middleLayerPlatform);
		~ModelViewControllerMiddleLayerContainer() noexcept = default;
		ModelViewControllerMiddleLayerContainer(const ModelViewControllerMiddleLayerContainer& rhs) noexcept = delete;
		ModelViewControllerMiddleLayerContainer& operator=(const ModelViewControllerMiddleLayerContainer& rhs) noexcept = delete;
		ModelViewControllerMiddleLayerContainer(ModelViewControllerMiddleLayerContainer&& rhs) noexcept;
		ModelViewControllerMiddleLayerContainer& operator=(ModelViewControllerMiddleLayerContainer&& rhs) noexcept;

		CLASS_INVARIANT_VIRTUAL_FINAL_DECLARE;

		bool PreCreate(const EnvironmentDirectory& environmentDirectory) final;
		bool Create() final;
		bool Initialize() final;

		bool Destroy() final;
		void Terminate() final;

		void PreIdle() final;
		bool Idle(int64_t timeDelta) final;

		bool Paint() final;
		bool Move(const WindowPoint& point) final;
		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

		bool KeyUp(int key, const WindowPoint& point) final;
		bool KeyDown(int key, const WindowPoint& point) final;
		bool SpecialKeyUp(int key, const WindowPoint& point) final;
		bool SpecialKeyDown(int key, const WindowPoint& point) final;

		bool PassiveMotion(const WindowPoint& point) final;
		bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
		bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
		bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

	private:		
		MiddleLayerSharedPtr m_ModelMiddleLayer;
		MiddleLayerSharedPtr m_ViewMiddleLayer;
		MiddleLayerSharedPtr m_ControllerMiddleLayer;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_H

