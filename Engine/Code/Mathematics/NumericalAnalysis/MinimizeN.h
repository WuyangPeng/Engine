// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_H

#include "Mathematics/MathematicsDll.h"

#include "Minimize1.h"
#include "MinimizeNData.h"
#include "MinimizeNGetMinimum.h"

#include <vector>

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class MinimizeN
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = MinimizeN<Real, UserDataType>;
		using MinimizeNData = MinimizeNData<Real>;
		using RealVector = std::vector<Real>;

		// 被最小化的函数类型：result = f(t,userData)，其中t是d元组（d的尺寸在构造函数）。
		// userData是由构造函数或SetUserData(*)的指针提供。
		// 这使您可以通过类的静态函数包装到一个非静态成员函数，在这种情况下，用户数据是一个指向类对象的指针。
		// 当然，用户数据可以是复杂的，你需要它确保“函数”必须计算它需要的所有信息。
		using Function = Real(*)(const RealVector&, const UserDataType*);

	public:
		// 笛卡尔乘积域提供给GetMinimum(*)，具有最小值存储在t0[0..d-1] 和最大值存储在t1[0..d-1]，其中d是“尺寸”。
		// 该域是通过沿着当前估计线的最低位置搜索。每个这样的线搜索使用 Minimize1<Real>对象。
		// 这就是“鲍威尔的方向设定方法”（Powell's Direction Set Method）。
		// 参数“maxLevel”和“maxBracket”被用于Minimize1<Real>，
		// 阅读该类的文档（其头文件），以了解这些意味着什么。
		// 输入“maxIterations”是方向设定法的迭代数目。
		MinimizeN(int dimensions, Function function, int maxLevel, int maxBracket, int maxIterations, const UserDataType* userData);

		CLASS_INVARIANT_DECLARE;

		// 查找笛卡尔乘积域其最小值存储在t0[0..d-1] 和最大值存储在t1[0..d-1]，其中d是“尺寸”。
		// 最初的猜测是在ttInitial[0..d-1]中存储。最小值的位置是tMin[0..d-1] 和最小的值是fMin。
		const MinimizeNData GetMinimum(const RealVector& begin, const RealVector& end, const RealVector& initial) const;

	private:
		using MinimizeNGetMinimum = MinimizeNGetMinimum<Real, UserDataType>;

	private:
		int m_Dimensions;
		Function m_Function;
		int m_MaxLevel;
		int m_MaxBracket;
		int m_MaxIterations;
		const UserDataType* m_UserData;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_H
