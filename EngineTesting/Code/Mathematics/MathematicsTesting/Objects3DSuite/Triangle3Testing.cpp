// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 18:01)

#include "Triangle3Testing.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_real;
using std::default_random_engine;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
namespace Mathematics
{
	template class Triangle3<float>;
	template class Triangle3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Triangle3Testing) 

void Mathematics::Triangle3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
}

void Mathematics::Triangle3Testing
	::TriangleTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D firstPoint(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		Vector3D secondPoint(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		Vector3D thirdPoint(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		Triangle3D triangle(firstPoint,secondPoint,thirdPoint);

		vector<Vector3D> vertex = triangle.GetVertex();

		ASSERT_TRUE(Vector3ToolsD::Approximate(vertex[0],firstPoint));
		ASSERT_TRUE(Vector3ToolsD::Approximate(vertex[1],secondPoint));
		ASSERT_TRUE(Vector3ToolsD::Approximate(vertex[2],thirdPoint));

		Vector3D fourthPoint(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		
		Vector3D diff = firstPoint - fourthPoint;
		Vector3D edge0 = secondPoint - firstPoint;
		Vector3D edge1 = thirdPoint - firstPoint;
		double a00 = Vector3ToolsD::GetLengthSquared(edge0);
		double a01 = Vector3ToolsD::DotProduct(edge0,edge1);
		double a11 = Vector3ToolsD::GetLengthSquared(edge1);
		double b0 = Vector3ToolsD::DotProduct(diff,edge0);
		double b1 = Vector3ToolsD::DotProduct(diff,edge1);
		double c = Vector3ToolsD::GetLengthSquared(diff);
		double det = MathD::FAbs(a00 * a11 - a01 * a01);
		double s = a01 * b1 - a11 * b0;
		double t = a01 * b0 - a00 * b1;

		if (s + t <= det)
		{
			if (s < 0.0)
			{
				if (t < 0.0) 
				{
					if (b0 < 0.0)
					{
						if (-b0 >= a00)
						{
							ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								               MathD::Sqrt(MathD::FAbs(a00 + 2.0 * b0 + c)),
											   1e-10);							
						}
						else
						{
							ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								               MathD::Sqrt(MathD::FAbs(c - b0 * b0 / a00)),
											   1e-10);	
						}
					}
					else
					{
						if (b1 >= 0.0)
						{
							ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								               MathD::Sqrt(MathD::FAbs(c)),
											   1e-10);	
						}
						else if (-b1 >= a11)
						{
							ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								               MathD::Sqrt(MathD::FAbs(a11 + 2.0 * b1 + c)),
											   1e-10);		
						}
						else
						{
							ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								               MathD::Sqrt(MathD::FAbs(c - b1 * b1 / a11)),
											   1e-10);				
						}
					}
				}
				else  
				{
					if (b1 >= 0.0)
					{
						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								           MathD::Sqrt(MathD::FAbs(c)),
										   1e-10);				
	
					}
					else if (-b1 >= a11)
					{
						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								           MathD::Sqrt(MathD::FAbs(a11 + 2.0 * b1 + c)),
										   1e-10);			
							
					}
					else
					{
						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								           MathD::Sqrt(MathD::FAbs(c - b1 * b1 / a11)),
										   1e-10);		
									
					}
				}
			}
			else if (t < 0.0)  
			{
				if (b0 >= 0.0)
				{
					ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								       MathD::Sqrt(MathD::FAbs(c)),
									   1e-10);		
			
				}
				else if (-b0 >= a00)
				{
					ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								       MathD::Sqrt(MathD::FAbs(a00 + 2.0 * b0 + c)),
									   1e-10);					

				}
				else
				{
					ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								       MathD::Sqrt(MathD::FAbs(b0 * s + c - b0 * b0/ a00)),
									   1e-10);					
				}
			}
			else  
			{
				double invDet = 1.0 / det;
				s *= invDet;
				t *= invDet;			

				ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								   MathD::Sqrt(MathD::FAbs(s * (a00 * s + a01 * t + 2.0 * b0) + t * (a01 * s + a11 * t + 2.0 * b1) + c)),
								   1e-10);	
			
			}
		}
		else
		{
			if (s < 0.0)  
			{
				double tmp0 = a01 + b0;
				double tmp1 = a11 + b1;
				if (tmp1 > tmp0)
				{
					double numer = tmp1 - tmp0;
					double denom = a00 - 2.0 * a01 + a11;
					if (numer >= denom)
					{
						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt (MathD::FAbs(a00 + 2.0 * b0 + c)), 1e-10);			
			
					}
					else
					{
						s = numer / denom;
						t = 1.0 - s;

						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), 
										   MathD::Sqrt (MathD::FAbs  (s * (a00 * s + a01 * t + 2.0 * b0) + t * (a01 * s + a11 * t + 2.0 * b1) + c)),
										   1e-10);	
										
					}
				}
				else
				{
					if (tmp1 <= 0.0)
					{
						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt  (MathD::FAbs(a11 + 2.0 * b1 + c)), 1e-10);					
	
					}
					else if (b1 >= 0.0)
					{
						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),  MathD::Sqrt (MathD::FAbs(c)), 1e-10);		
	
					}
					else
					{
						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),  MathD::Sqrt (MathD::FAbs(c - b1 * b1 / a11)),  1e-10); 
					}
				}
			}
			else if (t < 0.0) 
			{
				double tmp0 = a01 + b1;
				double tmp1 = a00 + b0;
				if (tmp1 > tmp0)
				{
					double numer = tmp1 - tmp0;
					double denom = a00 - 2.0 * a01 + a11;
					if (numer >= denom)
					{
						t = 1.0;
						s = 0.0;

						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt (MathD::FAbs(a11 + 2.0 * b1 + c)), 1e-10);	
						
		
					}
					else
					{
						t = numer / denom;
						s = 1.0 - t;

						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), 
										   MathD::Sqrt (MathD::FAbs(s * (a00 * s + a01 * t + 2.0 * b0) + t * (a01 * s + a11 * t + 2.0 * b1) + c)),
									      1e-10);						
					}
				}
				else
				{
					if (tmp1 <= 0.0)
					{
			
						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
								           MathD::Sqrt (MathD::FAbs(a00 + 2.0 * b0 + c)),
									       1e-10);					

					}
					else if (b0 >= 0.0)
					{

						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt (MathD::FAbs(c)),  1e-10);					

					}
					else
					{
		
						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt (MathD::FAbs(c - b0 * b0 / a00)),  1e-10);						
	
					}
				}
			}
			else  
			{
				double numer = a11 + b1 - a01 - b0;
				if (numer <= 0.0)
				{
					ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt (MathD::FAbs(a11 + 2.0 * b1 + c)), 1e-10);					
			
				}
				else
				{
					double denom = a00 - 2.0 * a01 + a11;
					if (numer >= denom)
					{
						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt (MathD::FAbs(a00 + 2.0 * b0 + c)), 1e-10);				

					}
					else
					{
						s = numer / denom;
						t = 1.0 - s;					

						ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), 
							               MathD::Sqrt(MathD::FAbs (s * (a00 * s + a01 * t + 2.0 * b0) + t * (a01 * s + a11 * t + 2.0 * b1) + c)),
									       1e-10);
					}
				}
			}
		}
	}
}

