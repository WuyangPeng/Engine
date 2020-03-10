// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:50)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_H

#include "ModelViewControllerMiddleLayer.h"

#include <type_traits> 

namespace Framework
{
	template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
			  template<typename > class ControllerMiddleLayer>
	class ModelViewControllerMiddleLayerContainer : public MiddleLayerInterface
	{
	public:
		static_assert(std::is_base_of<ModelViewControllerMiddleLayer,ModelMiddleLayer>::value);
		static_assert(std::is_base_of<ModelViewControllerMiddleLayer,ViewMiddleLayer>::value);
		static_assert(std::is_base_of<ModelViewControllerMiddleLayer,ControllerMiddleLayer<ApplicationTrait> >::value);

	public:
		using ClassType = ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>;
		using ParentType = MiddleLayerInterface;
		using ModelMiddleLayerType = ModelMiddleLayer;
		using ViewMiddleLayerType = ViewMiddleLayer;
		using ControllerMiddleLayerType = ControllerMiddleLayer<ApplicationTrait>;

	public:
		ModelViewControllerMiddleLayerContainer();
		virtual ~ModelViewControllerMiddleLayerContainer();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE; 

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();
		virtual bool Paint();
		virtual bool Move(const WindowPoint& point);		
		virtual bool Resize(WindowDisplayFlags type,const WindowSize& size);
		virtual bool KeyDown(uint8_t key,const WindowPoint& point);
	    virtual bool KeyUp(uint8_t key, const WindowPoint& point);
		virtual bool SpecialKeyDown (int key, const WindowPoint& point);
		virtual bool SpecialKeyUp (int key, const WindowPoint& point);
		virtual bool MouseClick(MouseButtonsTypes button,MouseStateTypes state,const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Motion(const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes);
		virtual bool PassiveMotion(const WindowPoint& point);
		virtual bool MouseWheel(int delta,const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes);	
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);
		
	private:
		ModelViewControllerMiddleLayerSmartPointer m_ModelMiddleLayer;
		ModelViewControllerMiddleLayerSmartPointer m_ViewMiddleLayer;
		ModelViewControllerMiddleLayerSmartPointer m_ControllerMiddleLayer;		
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_H

