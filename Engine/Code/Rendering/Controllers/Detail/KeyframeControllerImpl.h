// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:14)

#ifndef RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_IMPL_H 

#include "Rendering/RenderingDll.h"
 
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/AQuaternion.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/Controllers/ControllerKeyInfo.h"

#include <vector>

namespace CoreTools
{
	class BufferTarget;
	class BufferSource;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE KeyframeControllerImpl
	{
	public:
		using ClassType = KeyframeControllerImpl;
		using AQuaternion = Mathematics::AQuaternionf;
		using APoint = Mathematics::FloatAPoint;
		using Matrix = Mathematics::FloatMatrix;

	public:
		// ���ƽ�ƣ���ת�����Ŷ�������ͬ�Ĺؼ�֡ʱ�䣬��numCommonTimes������Ϊ������
		// ÿ��ʣ������ΪnumCommonTimes����ͨ�����ڣ���Ϊ��ʱ��
		// ����ؼ�֡ʱ�䲻������numCommonTimes��������Ϊ�㣬������������趨Ϊ�ʵ���ֵ 
		// ���ŵ�����ʱΪ��ֵ��������ʽΪ�㡣
		
		// �任�����ʼ�����ƶ���ľֲ��任��
		// ��������ǰ����Ϊ��Ϊ���ֻ���ɹؼ�֡�����ͨ���任��
		// �������������ռ�Spatial m_Object������Ӧ�ó����ʵ�����������ͨ����
		// ����KeyframeController����*����*��ͨ����
            KeyframeControllerImpl() noexcept;
		KeyframeControllerImpl(int numCommonTimes, int numTranslations,int numRotations, int numScales);

		CLASS_INVARIANT_DECLARE;

		int GetStreamingSize() const;
		void Save(CoreTools::BufferTarget& target) const;
		void Load(CoreTools::BufferSource& source);
 
	public:		
		// ���ù��캯������������������ʹ����Щ������
            int GetNumCommonTimes() const noexcept;
		float GetCommonTimes (int index) const;
		void SetCommonTimes(int index, float commonTimes);
		
		int GetNumTranslations() const noexcept;
		float GetTranslationTimes(int index) const;
		const APoint GetTranslations(int index) const;

		void SetTranslationTimes(int index, float translationTimes);
		void SetTranslations(int index, const APoint& translations);
		
		int GetNumRotations() const noexcept;
		float GetRotationTimes(int index) const;
		const AQuaternion GetRotations(int index) const;

		void SetRotationTimes(int index, float rotationTimes);
		void SetRotations(int index, const AQuaternion& rotations);
		
		int GetNumScales() const noexcept;
		float GetScaleTimes(int index) const;
		float GetScales(int index) const ;

		void SetScaleTimes(int index, float scaleTimes);
		void SetScales(int index, float scales);		

		const ControllerKeyInfo GetTranslateKeyInfo(float ctrlTime);
		const ControllerKeyInfo GetRotateKeyInfo(float ctrlTime);
		const ControllerKeyInfo GetScaleKeyInfo(float ctrlTime);
		const ControllerKeyInfo GetCommonKeyInfo(float ctrlTime);
		
		const APoint GetTranslate(const ControllerKeyInfo& keyInfo) const;
		const Matrix GetRotate(const ControllerKeyInfo& keyInfo) const;
                float GetScale(const ControllerKeyInfo& keyInfo) const noexcept;

	private:
		// ֧�ֲ��Ҹ���ָ��ʱ��Ĺؼ�֡��
		static const ControllerKeyInfo GetKeyInfo(float ctrlTime, const std::vector<float>& times,int& lastIndex);

		void ResetArraySize();

	private:		
		// times��ƽ�ƣ���ת�ͱ��������������ʱ��ʹ�á�
		int m_NumCommonTimes;
		std::vector<float> m_CommonTimes;
		
		int m_NumTranslations;
		std::vector<float> m_TranslationTimes;
		std::vector<APoint> m_Translations;
		
		int m_NumRotations;
		std::vector<float> m_RotationTimes;
		std::vector<AQuaternion> m_Rotations;
		
		int m_NumScales;
		std::vector<float> m_ScaleTimes;
		std::vector<float> m_Scales;
		
		// �����ڹ�ȥ�Ĳ��ҵ��ļ���������
		// ����ʱ�����У��Ᵽ֤��O(1) ���ҡ�
		int m_TranslationLastIndex;
		int m_RotationLastIndex;
		int m_ScaleLastIndex;
		int m_CommonLastIndex;
	};
}

#endif // RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_IMPL_H
