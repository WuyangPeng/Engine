// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 15:28)

#include "TransformTesting.h"
#include "Rendering/DataTypes/Transform.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"

#include <random>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering,TransformTesting) 

void Rendering::TransformTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InverseTest);
}
  #include SYSTEM_WARNING_DISABLE(26440)
void Rendering::TransformTesting
	::BaseTest()
{
//     std::default_random_engine generator;
// 	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);
//     std::uniform_real<float> secondFloatRandomDistribution(0.0f,Mathematics::MathF::sm_TwoPI);
//     
//     Transform transform2;
//     
//     ASSERT_TRUE(transform2.IsIdentity());
//     ASSERT_TRUE(transform2.IsRotationOrScaleMatrix());
//     ASSERT_TRUE(transform2.IsUniformScale());
//     
//     ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity, transform2.GetRotate(),1e-8f));
//     ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity, transform2.GetMatrix(),1e-8f));
//     ASSERT_TRUE(Approximate(Transform::APoint(0.0f,0.0f,0.0f), transform2.GetTranslate(),1e-8f));
//     ASSERT_TRUE(Approximate(Transform::APoint(1.0f,1.0f,1.0f), transform2.GetScale(),1e-8f));
//     ASSERT_APPROXIMATE(1.0f, transform2.GetUniformScale(),1e-8f);
//     ASSERT_APPROXIMATE(1.0f, transform2.GetNorm(),1e-8f);
//     ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity, transform2.GetHomogeneousMatrix(),1e-8f));
//     
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
//         Transform::AVector axis(firstFloatRandomDistribution(generator),
//                                 firstFloatRandomDistribution(generator),
//                                 firstFloatRandomDistribution(generator));
//         axis.Normalize();
//         
//         float angle = secondFloatRandomDistribution(generator);
//         
//         Transform::Matrix rotate(axis,angle);
// 
// 		Transform transform;
//         
//         transform.SetRotate(rotate);
//         
//         ASSERT_FALSE(transform.IsIdentity());
//         ASSERT_TRUE(transform.IsRotationOrScaleMatrix());
//         ASSERT_TRUE(transform.IsUniformScale());
//         
//         ASSERT_TRUE(Approximate(rotate,transform.GetRotate(),1e-8f));
//         ASSERT_TRUE(Approximate(rotate,transform.GetMatrix(),1e-8f));
//         ASSERT_TRUE(Approximate(Transform::APoint(0.0f,0.0f,0.0f),transform.GetTranslate(),1e-8f));
//         ASSERT_TRUE(Approximate(Transform::APoint(1.0f,1.0f,1.0f),transform.GetScale(),1e-8f));
//         ASSERT_APPROXIMATE(1.0f,transform.GetUniformScale(),1e-8f);
//         ASSERT_APPROXIMATE(1.0f,transform.GetNorm(),1e-8f);
//         ASSERT_TRUE(Approximate(rotate,transform.GetHomogeneousMatrix(),1e-8f));
//         
//         Transform::APoint  scale(firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator));
//         
//         transform.SetUniformScale(scale[0]);
//         
//         ASSERT_FALSE(transform.IsIdentity());
//         ASSERT_TRUE(transform.IsRotationOrScaleMatrix());
//         ASSERT_TRUE(transform.IsUniformScale());
//         
//         ASSERT_TRUE(Approximate(rotate,transform.GetRotate(),1e-8f));
//         ASSERT_TRUE(Approximate(rotate,transform.GetMatrix(),1e-8f));
//         ASSERT_TRUE(Approximate(Transform::APoint(0.0f,0.0f,0.0f),transform.GetTranslate(),1e-8f));
//         ASSERT_TRUE(Approximate(Transform::APoint(scale[0],scale[0],scale[0]),
//                                 transform.GetScale(),1e-8f));
//         ASSERT_APPROXIMATE(scale[0],transform.GetUniformScale(),1e-8f);
//         ASSERT_APPROXIMATE(Mathematics::MathF::FAbs(scale[0]),transform.GetNorm(),1e-8f);
//         ASSERT_TRUE(Approximate(rotate * Transform::Matrix(scale[0],scale[0],scale[0]),
//                                 transform.GetHomogeneousMatrix(),1e-8f));
//         
//         transform.MakeIdentity();
//         
//         ASSERT_TRUE(transform.IsIdentity());
//         ASSERT_TRUE(transform.IsRotationOrScaleMatrix());
//         ASSERT_TRUE(transform.IsUniformScale());
//         
//         ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity,transform.GetRotate(),1e-8f));
//         ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity,transform.GetMatrix(),1e-8f));
//         ASSERT_TRUE(Approximate(Transform::APoint(0.0f,0.0f,0.0f),transform.GetTranslate(),1e-8f));
//         ASSERT_TRUE(Approximate(Transform::APoint(1.0f,1.0f,1.0f),transform.GetScale(),1e-8f));
//         ASSERT_APPROXIMATE(1.0f,transform.GetUniformScale(),1e-8f);
//         ASSERT_APPROXIMATE(1.0f,transform.GetNorm(),1e-8f);
//         ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity,transform.GetHomogeneousMatrix(),1e-8f));
//         
//         transform.SetRotate(rotate);
//         transform.SetScale(scale);
//         
//         ASSERT_FALSE(transform.IsIdentity());
//         ASSERT_TRUE(transform.IsRotationOrScaleMatrix());
//         ASSERT_FALSE(transform.IsUniformScale());
//         
//         float maxScale = Mathematics::MathF::FAbs(scale[0]);
//         
//         if(maxScale < Mathematics::MathF::FAbs(scale[1]))
//         {
//             maxScale = Mathematics::MathF::FAbs(scale[1]);
//         }
//         
//         if(maxScale < Mathematics::MathF::FAbs(scale[2]))
//         {
//             maxScale = Mathematics::MathF::FAbs(scale[2]);
//         }
//         
//         ASSERT_TRUE(Approximate(rotate,transform.GetRotate(),1e-8f));
//         ASSERT_TRUE(Approximate(rotate,transform.GetMatrix(),1e-8f));
//         ASSERT_TRUE(Approximate(Transform::APoint(0.0f,0.0f,0.0f),transform.GetTranslate(),1e-8f));
//         ASSERT_TRUE(Approximate(scale,transform.GetScale(),1e-8f));
//         ASSERT_APPROXIMATE(maxScale,transform.GetNorm(),1e-8f);
//         ASSERT_TRUE(Approximate(rotate * Transform::Matrix(scale[0],scale[1],scale[2]),
//                                 transform.GetHomogeneousMatrix(),1e-8f));
//         
//         Transform::APoint translate(firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator));
//         
//         transform.SetTranslate(translate);
//         
//         ASSERT_FALSE(transform.IsIdentity());
//         ASSERT_TRUE(transform.IsRotationOrScaleMatrix());
//         ASSERT_FALSE(transform.IsUniformScale());
//         
//         ASSERT_TRUE(Approximate(rotate,transform.GetRotate(),1e-8f));
//         ASSERT_TRUE(Approximate(rotate,transform.GetMatrix(),1e-8f));
//         ASSERT_TRUE(Approximate(translate,transform.GetTranslate(),1e-8f));
//         ASSERT_TRUE(Approximate(scale,transform.GetScale(),1e-8f));
//         ASSERT_APPROXIMATE(maxScale,transform.GetNorm(),1e-8f);
//         ASSERT_TRUE(Approximate(rotate * Transform::Matrix(scale[0],scale[1],scale[2]) +
//                                 Transform::Matrix(0.0f,0.0f,0.0f,translate[0],
//                                                   0.0f,0.0f,0.0f,translate[1],
//                                                   0.0f,0.0f,0.0f,translate[2],
//                                                   0.0f,0.0f,0.0f,0.0f),
//                                 transform.GetHomogeneousMatrix(),1e-8f));
//         
//         transform.MakeUnitScale();
//         
//         ASSERT_FALSE(transform.IsIdentity());
//         ASSERT_TRUE(transform.IsRotationOrScaleMatrix());
//         ASSERT_TRUE(transform.IsUniformScale());
//         
//         ASSERT_TRUE(Approximate(rotate,transform.GetRotate(),1e-8f));
//         ASSERT_TRUE(Approximate(rotate,transform.GetMatrix(),1e-8f));
//         ASSERT_TRUE(Approximate(translate,transform.GetTranslate(),1e-8f));
//         ASSERT_TRUE(Approximate(Transform::APoint(1.0f,1.0f,1.0f),
//                                 transform.GetScale(),1e-8f));
//         ASSERT_APPROXIMATE(1.0f,transform.GetUniformScale(),1e-8f);
//         ASSERT_APPROXIMATE(1.0f,transform.GetNorm(),1e-8f);
//         ASSERT_TRUE(Approximate(rotate + Transform::Matrix(0.0f,0.0f,0.0f,translate[0],
//                                                            0.0f,0.0f,0.0f,translate[1],
//                                                            0.0f,0.0f,0.0f,translate[2],
//                                                            0.0f,0.0f,0.0f,0.0f),
//                                 transform.GetHomogeneousMatrix(),1e-8f));
//         
//         Transform::Matrix matrix(firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  0.0f,firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  0.0f,firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),0.0f,
//                                  0.0f,0.0f,0.0f,1.0f);
//         
//         transform.SetMatrix(matrix);
//         
//         ASSERT_FALSE(transform.IsIdentity());
//         ASSERT_FALSE(transform.IsRotationOrScaleMatrix());
//         ASSERT_FALSE(transform.IsUniformScale());
//         
//         float maxRowSum =
//             Mathematics::MathF::FAbs(matrix(0,0)) +
//             Mathematics::MathF::FAbs(matrix(0,1)) +
//             Mathematics::MathF::FAbs(matrix(0,2));
//         
//         float rowSum =
//             Mathematics::MathF::FAbs(matrix(1,0)) +
//             Mathematics::MathF::FAbs(matrix(1,1)) +
//             Mathematics::MathF::FAbs(matrix(1,2));
//         
//         if (maxRowSum < rowSum)
//         {
//             maxRowSum = rowSum;
//         }
//         
//         rowSum =
//             Mathematics::MathF::FAbs(matrix(2,0)) +
//             Mathematics::MathF::FAbs(matrix(2,1)) +
//             Mathematics::MathF::FAbs(matrix(2,2));
//         
//         if (maxRowSum < rowSum)
//         {
//             maxRowSum = rowSum;
//         }
//     
//         ASSERT_TRUE(Approximate(matrix,transform.GetMatrix(),1e-8f));
//         ASSERT_TRUE(Approximate(translate,transform.GetTranslate(),1e-8f));
//         ASSERT_APPROXIMATE(maxRowSum,transform.GetNorm(),1e-8f);
//         ASSERT_TRUE(Approximate(matrix + Transform::Matrix(0.0f,0.0f,0.0f,translate[0],
//                                                            0.0f,0.0f,0.0f,translate[1],
//                                                            0.0f,0.0f,0.0f,translate[2],
//                                                            0.0f,0.0f,0.0f,0.0f),
//                                 transform.GetHomogeneousMatrix(),1e-8f));
// 
//     }
}

void Rendering::TransformTesting
 ::OperatorTest()
{
//     std::default_random_engine generator;
// 	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);
//     std::uniform_real<float> secondFloatRandomDistribution(0.0f,Mathematics::MathF::sm_TwoPI);
//     
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
//         Transform::APoint firstPoint(firstFloatRandomDistribution(generator),
//                                      firstFloatRandomDistribution(generator),
//                                      firstFloatRandomDistribution(generator));
//         
//         Transform::AVector firstVector(firstFloatRandomDistribution(generator),
//                                        firstFloatRandomDistribution(generator),
//                                        firstFloatRandomDistribution(generator));
//         
//         firstVector.Normalize();
//         
//         Transform::AVector axis(firstFloatRandomDistribution(generator),
//                                 firstFloatRandomDistribution(generator),
//                                 firstFloatRandomDistribution(generator));
//         axis.Normalize();
//         
//         float angle = secondFloatRandomDistribution(generator);
//         
//         Transform::Matrix rotate(axis,angle);
//         
//         Transform::APoint translate(firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator));
//         
//         Transform::APoint scale(firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator));
//         
//         Transform firstTransform;
//         
//         firstTransform.SetRotate(rotate);
//         firstTransform.SetScale(scale);
//         firstTransform.SetTranslate(translate);
//         
//         Transform::APoint secondPoint = firstTransform * firstPoint;
//         
//         ASSERT_TRUE(Approximate(secondPoint,firstTransform.GetHomogeneousMatrix() * firstPoint,1e-8f));
//         
//         Transform::AVector secondVector = firstTransform * firstVector;
//         
//         ASSERT_TRUE(Approximate(secondVector,firstTransform.GetHomogeneousMatrix() * firstVector,1e-8f));
//         
//         Transform::Matrix matrix(firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  0.0f,firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  0.0f,firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),0.0f,
//                                  0.0f,0.0f,0.0f,1.0f);
//         
//         Transform secondTransform;
//         
//         secondTransform.SetMatrix(matrix);
//         
//         secondPoint = secondTransform * firstPoint;
//         
//         ASSERT_TRUE(Approximate(secondPoint,secondTransform.GetHomogeneousMatrix() * firstPoint,1e-8f));
//         
//         secondVector = secondTransform * firstVector;
//         
//         ASSERT_TRUE(Approximate(secondVector,secondTransform.GetHomogeneousMatrix() * firstVector,1e-8f));
//         
//         Transform thirdTransform = firstTransform * secondTransform;
//         
//         ASSERT_TRUE(Approximate(thirdTransform.GetHomogeneousMatrix(),
//                                 firstTransform.GetHomogeneousMatrix() *
//                                 secondTransform.GetHomogeneousMatrix(),1e-8f));
//         
//         Transform fourthTransform = firstTransform;
//         
//         fourthTransform *= secondTransform;
//         
//         ASSERT_TRUE(Approximate(fourthTransform.GetHomogeneousMatrix(),
//                                 firstTransform.GetHomogeneousMatrix() *
//                                 secondTransform.GetHomogeneousMatrix(),1e-8f));
//     }
}

void Rendering::TransformTesting
 ::InverseTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);
// 	std::uniform_real<float> secondFloatRandomDistribution(0.0f,Mathematics::MathF::sm_TwoPI);
//     
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
//         Transform::AVector axis(firstFloatRandomDistribution(generator),
//                                 firstFloatRandomDistribution(generator),
//                                 firstFloatRandomDistribution(generator));
//         axis.Normalize();
//         
//         float angle = secondFloatRandomDistribution(generator);
//         
//         Transform::Matrix rotate(axis,angle);
//         
//         Transform::APoint translate(firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator));
//         
//         Transform::APoint scale(firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator));
// 
//         Transform firstTransform;
//         
//         firstTransform.SetRotate(rotate);
//         firstTransform.SetScale(scale);
//         firstTransform.SetTranslate(translate);
//         
//         ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity,
//                                 firstTransform.GetHomogeneousMatrix() *
//                                 firstTransform.GetInverseMatrix(),1e-4f));
//         
//         Transform::Matrix matrix(firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  0.0f,firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  0.0f,firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),0.0f,
//                                  0.0f,0.0f,0.0f,1.0f);
// 
// 		Mathematics::Matrix3f matrix3 = matrix.GetMatrix3();
// 
// 		if(Mathematics::MathF::sm_ZeroTolerance <
// 		   Mathematics::MathF::FAbs(matrix3.Determinant()))
// 		{
// 			Transform secondTransform;
// 
// 			secondTransform.SetMatrix(matrix);
// 
// 			ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity,
// 				                    secondTransform.GetHomogeneousMatrix() *
// 									secondTransform.GetInverseMatrix(),1e-4f));
// 
// 			Transform thirdTransform = firstTransform.GetInverseTransform();
// 			Transform fourthTransform = thirdTransform.GetInverseTransform();
// 			
// 			ASSERT_TRUE(Approximate(firstTransform.GetHomogeneousMatrix(),
// 									fourthTransform.GetHomogeneousMatrix(),1e-4f));
// 			
// 			ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity,
// 				                    thirdTransform.GetHomogeneousMatrix() *
// 									firstTransform.GetHomogeneousMatrix(),1e-4f));
// 					
// 		    ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity,
// 				                    thirdTransform.GetInverseMatrix() *
// 									firstTransform.GetInverseMatrix(),1e-4f));			
// 
// 			thirdTransform = secondTransform.GetInverseTransform(1e-8f);
// 			fourthTransform = thirdTransform.GetInverseTransform(1e-8f);
// 
// 			ASSERT_TRUE(Approximate(secondTransform.GetHomogeneousMatrix(),
// 									fourthTransform.GetHomogeneousMatrix(),1e-3f));
// 
// 			ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity,
// 				                    thirdTransform.GetHomogeneousMatrix() *
// 									secondTransform.GetHomogeneousMatrix(),1e-5f));
// 
// 			ASSERT_TRUE(Approximate(Transform::Matrix::sm_Identity,
// 				                    thirdTransform.GetInverseMatrix(1e-8f) *
// 									secondTransform.GetInverseMatrix(1e-8f),1e-4f));
// 		}
//     }
}