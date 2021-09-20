// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:35)

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
		// ���ƽ�ƣ���ת�����Ŷ�������ͬ�Ĺؼ�֡ʱ�䣬��numCommonTimes������Ϊ������
		// ÿ��ʣ������ΪnumCommonTimes����ͨ�����ڣ���Ϊ��ʱ��
		// ����ؼ�֡ʱ�䲻������numCommonTimes��������Ϊ�㣬������������趨Ϊ�ʵ���ֵ 
		// ���ŵ�����ʱΪ��ֵ��������ʽΪ�㡣

		// �任�����ʼ�����ƶ���ľֲ��任��
		// ��������ǰ����Ϊ��Ϊ���ֻ���ɹؼ�֡�����ͨ���任��
		// �������������ռ�Spatial m_Object������Ӧ�ó����ʵ�����������ͨ����
		// ����KeyframeController����*����*��ͨ����
		KeyframeController(int numCommonTimes, int numTranslations,int numRotations, int numScales,const FloatTransform& localTransform);
	 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(KeyframeController); 

		// ���ù��캯������������������ʹ����Щ������
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
 
		// �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
		 bool Update(double applicationTime) override;
		 void SetObject(ControllerInterface* object) override;
		 void SetObjectInCopy(ControllerInterface* object)override;

		 ControllerInterfaceSharedPtr Clone() const override;
                 ObjectInterfaceSharedPtr CloneObject() const override;
	protected:
		// ֧�ֲ��Ҹ���ָ��ʱ��Ĺؼ�֡��
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
