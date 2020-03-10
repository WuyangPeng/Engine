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

RENDERING_EXPORT_SHARED_PTR(KeyframeControllerImpl);

namespace Rendering
{	
	class RENDERING_DEFAULT_DECLARE KeyframeController : public TransformController
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(KeyframeController);
		using ParentType = TransformController;
		using Matrix = Mathematics::Matrixf;
		using AQuaternion = Mathematics::AQuaternionf;
		using APoint = Mathematics::APointf;

	public:
		// ���ƽ�ƣ���ת�����Ŷ�������ͬ�Ĺؼ�֡ʱ�䣬��numCommonTimes������Ϊ������
		// ÿ��ʣ������ΪnumCommonTimes����ͨ�����ڣ���Ϊ��ʱ��
		// ����ؼ�֡ʱ�䲻������numCommonTimes��������Ϊ�㣬������������趨Ϊ�ʵ���ֵ 
		// ���ŵ�����ʱΪ��ֵ��������ʽΪ�㡣

		// �任�����ʼ�����ƶ���ľֲ��任��
		// ��������ǰ����Ϊ��Ϊ���ֻ���ɹؼ�֡�����ͨ���任��
		// �������������ռ�Spatial m_Object������Ӧ�ó����ʵ�����������ͨ����
		// ����KeyframeController����*����*��ͨ����
		KeyframeController(int numCommonTimes, int numTranslations,int numRotations, int numScales,const Transform& localTransform);

		virtual ~KeyframeController();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(KeyframeController); 

		// ���ù��캯������������������ʹ����Щ������
		int GetNumCommonTimes () const;
		float GetCommonTimes (int index) const;
		void SetCommonTimes(int index, float commonTimes);
		
		int GetNumTranslations () const;
		float GetTranslationTimes(int index) const;
		const APoint GetTranslations(int index) const;

		void SetTranslationTimes(int index, float translationTimes);
		void SetTranslations(int index, const APoint& translations);
		
		int GetNumRotations () const;
		float GetRotationTimes(int index) const;
		const AQuaternion GetRotations(int index) const;

		void SetRotationTimes(int index, float rotationTimes);
		void SetRotations(int index, const AQuaternion& rotations);
		
		int GetNumScales () const;
		float GetScaleTimes(int index) const;
		float GetScales(int index) const;

		void SetScaleTimes(int index, float scaleTimes);
		void SetScales(int index, float scales);   
 
		// �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
		virtual bool Update(double applicationTime) override;
		virtual void SetObject(ControllerInterface* object) override;
		virtual void SetObjectInCopy(ControllerInterface* object)override;

		virtual ControllerInterfaceSmartPointer Clone() const override;
		
	protected:
		// ֧�ֲ��Ҹ���ָ��ʱ��Ĺؼ�֡��
		const ControllerKeyInfo GetTranslateKeyInfo(float ctrlTime);
		const ControllerKeyInfo GetRotateKeyInfo(float ctrlTime);
		const ControllerKeyInfo GetScaleKeyInfo(float ctrlTime);
		const ControllerKeyInfo GetCommonKeyInfo(float ctrlTime);

		const APoint GetTranslate(const ControllerKeyInfo& keyInfo) const;
		const Matrix GetRotate(const ControllerKeyInfo& keyInfo) const;
		float GetScale(const ControllerKeyInfo& keyInfo) const;

	private:
		IMPL_TYPE_DECLARE(KeyframeController);
	};
	
	CORE_TOOLS_STREAM_REGISTER(KeyframeController);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Sixth, KeyframeController); 
}

#endif // RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_H
