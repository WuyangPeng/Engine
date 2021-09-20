// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:35)

#ifndef RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_H
#define RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_H

#include "Rendering/RenderingDll.h" 

#include "ControllerKeyInfo.h"
#include "TransformController.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/AQuaternion.h"
#include "Rendering/DataTypes/Transform.h"
EXPORT_SHARED_PTR(Rendering, KeyframeControllerImpl, RENDERING_DEFAULT_DECLARE);
 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{	
	class RENDERING_DEFAULT_DECLARE KeyframeController : public TransformController
	{
	public:
            void Swap(KeyframeController& rhs) noexcept;

    public:
        TYPE_DECLARE(KeyframeController);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~KeyframeController() noexcept= default;
        KeyframeController(const KeyframeController& rhs);
        KeyframeController& operator=(const KeyframeController& rhs);
        KeyframeController(KeyframeController&& rhs) noexcept;
        KeyframeController& operator=(KeyframeController&& rhs) noexcept;
		using ParentType = TransformController;
		using Matrix = Mathematics::FloatMatrix;
		using AQuaternion = Mathematics::FloatAQuaternion;
		using APoint = Mathematics::FloatAPoint;

	public:
		// 如果平移，旋转和缩放都有着相同的关键帧时间，则numCommonTimes被设置为正数。
		// 每个剩余数量为numCommonTimes，当通道存在，或为零时。
		// 如果关键帧时间不共享，则numCommonTimes必须设置为零，而其余的数字设定为适当的值 
		// 当信道存在时为正值和其他方式为零。

		// 变换输入初始化控制对象的局部变换。
		// 这个类的以前的行为是为了填补只能由关键帧代表的通道变换，
		// 其中隐含依靠空间Spatial m_Object有它的应用程序适当地设置其他通道。
		// 现在KeyframeController设置*所有*的通道。
		KeyframeController(int numCommonTimes, int numTranslations,int numRotations, int numScales,const FloatTransform& localTransform);
	 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(KeyframeController); 

		// 调用构造函数后，您必须设置数据使用这些函数。
		int GetNumCommonTimes () const noexcept;
		float GetCommonTimes (int index) const;
		void SetCommonTimes(int index, float commonTimes);
		
		int GetNumTranslations () const noexcept;
		float GetTranslationTimes(int index) const;
		const APoint GetTranslations(int index) const;

		void SetTranslationTimes(int index, float translationTimes);
		void SetTranslations(int index, const APoint& translations);
		
		int GetNumRotations () const noexcept;
		float GetRotationTimes(int index) const;
		const AQuaternion GetRotations(int index) const;

		void SetRotationTimes(int index, float rotationTimes);
		void SetRotations(int index, const AQuaternion& rotations);
		
		int GetNumScales () const noexcept;
		float GetScaleTimes(int index) const;
		float GetScales(int index) const;

		void SetScaleTimes(int index, float scaleTimes);
		void SetScales(int index, float scales);   
 
		// 动画更新。应用程序时间以毫秒为单位。
		 bool Update(double applicationTime) override;
		 void SetObject(ControllerInterface* object) override;
		 void SetObjectInCopy(ControllerInterface* object)override;

		 ControllerInterfaceSharedPtr Clone() const override;
                 ObjectInterfaceSharedPtr CloneObject() const override;
	protected:
		// 支持查找给出指定时间的关键帧。
		const ControllerKeyInfo GetTranslateKeyInfo(float ctrlTime);
		const ControllerKeyInfo GetRotateKeyInfo(float ctrlTime);
		const ControllerKeyInfo GetScaleKeyInfo(float ctrlTime);
		const ControllerKeyInfo GetCommonKeyInfo(float ctrlTime);

		const APoint GetTranslate(const ControllerKeyInfo& keyInfo) const;
                const Matrix GetRotate(const ControllerKeyInfo& keyInfo) const noexcept;
		float GetScale(const ControllerKeyInfo& keyInfo) const noexcept;

	private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
	};
	
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(KeyframeController);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( KeyframeController); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_H
