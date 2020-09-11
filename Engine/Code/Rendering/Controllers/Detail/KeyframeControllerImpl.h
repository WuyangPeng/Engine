// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:14)

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
		// 如果平移，旋转和缩放都有着相同的关键帧时间，则numCommonTimes被设置为正数。
		// 每个剩余数量为numCommonTimes，当通道存在，或为零时。
		// 如果关键帧时间不共享，则numCommonTimes必须设置为零，而其余的数字设定为适当的值 
		// 当信道存在时为正值和其他方式为零。
		
		// 变换输入初始化控制对象的局部变换。
		// 这个类的以前的行为是为了填补只能由关键帧代表的通道变换，
		// 其中隐含依靠空间Spatial m_Object有它的应用程序适当地设置其他通道。
		// 现在KeyframeController设置*所有*的通道。
            KeyframeControllerImpl() noexcept;
		KeyframeControllerImpl(int numCommonTimes, int numTranslations,int numRotations, int numScales);

		CLASS_INVARIANT_DECLARE;

		int GetStreamingSize() const;
		void Save(CoreTools::BufferTarget& target) const;
		void Load(CoreTools::BufferSource& source);
 
	public:		
		// 调用构造函数后，您必须设置数据使用这些函数。
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
		// 支持查找给出指定时间的关键帧。
		static const ControllerKeyInfo GetKeyInfo(float ctrlTime, const std::vector<float>& times,int& lastIndex);

		void ResetArraySize();

	private:		
		// times当平移，旋转和比例共享这个数组时才使用。
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
		
		// 缓存在过去的查找到的键对索引。
		// 对于时间序列，这保证了O(1) 查找。
		int m_TranslationLastIndex;
		int m_RotationLastIndex;
		int m_ScaleLastIndex;
		int m_CommonLastIndex;
	};
}

#endif // RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_IMPL_H
