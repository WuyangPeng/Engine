// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 09:50)

#include "CameraTesting.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"




#include <random> 
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering,CameraTesting) 

void Rendering::CameraTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	CameraManager::Create();

	CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Default);	

	ASSERT_NOT_THROW_EXCEPTION_0(FrameTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FrustumTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ProjectionMatrixTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AxesAlignBoundingBoxTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);	

	CameraManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::CameraTesting
	::FrameTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);  

	for(int loop = 0;loop < GetTestLoopCount();++loop)
	{
        Camera::APoint firstPosition(firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator));

        Camera::AVector firstVector(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));

        firstVector.Normalize();

        Camera::AVector secondVector(firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator));

        secondVector.Normalize();

        Camera::AVector thirdVector(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));

        thirdVector.Normalize();

//         Mathematics::AVectorOrthonormalizef orthonormalize = Orthonormalize(firstVector, secondVector, thirdVector,1e-5f);
//         
//         firstVector = orthonormalize.GetUVector();
//         secondVector = orthonormalize.GetVVector();
//         thirdVector = orthonormalize.GetWVector();
// 
//         Camera::Matrix firstMatrix(thirdVector[0], thirdVector[1], 
//                                    thirdVector[2],-Dot(firstPosition, thirdVector),
// 								   secondVector[0], secondVector[1], 
// 								   secondVector[2],-Dot(firstPosition, secondVector),
// 								   firstVector[0], firstVector[1], 
// 								   firstVector[2],-Dot(firstPosition, firstVector),
// 								   0.0f,0.0f,0.0f,1.0f);
// 
//         Camera::Matrix secondMatrix(secondVector[0], secondVector[1], 
//                                     secondVector[2],-Dot(firstPosition, secondVector),
// 									firstVector[0], firstVector[1], 
// 									firstVector[2],-Dot(firstPosition, firstVector),
// 									thirdVector[0], thirdVector[1], 
// 									thirdVector[2],-Dot(firstPosition, thirdVector),
// 									0.0f,0.0f,0.0f,1.0f);
// 
//         Camera firstCamera(true,1e-5f);
// 
//         firstCamera.SetFrame(firstPosition, firstVector,  secondVector, thirdVector);
// 
//         ASSERT_TRUE(Approximate(firstCamera.GetPosition(), firstPosition,1e-5f));
//         ASSERT_TRUE(Approximate(firstCamera.GetDirectionVector(), firstVector,1e-5f));
//         ASSERT_TRUE(Approximate(firstCamera.GetUpVector(), secondVector,1e-5f));
//         ASSERT_TRUE(Approximate(firstCamera.GetRightVector(), thirdVector,1e-5f));
//         ASSERT_TRUE(Approximate(firstCamera.GetViewMatrix(), firstMatrix,1e-3f));
//  
//         Camera secondCamera(false,1e-5f);      
// 
//         secondCamera.SetPosition(firstPosition);
//         secondCamera.SetAxes(thirdVector, firstVector, secondVector);
// 
//         ASSERT_TRUE(Approximate(secondCamera.GetPosition(), firstPosition,1e-5f));
//         ASSERT_TRUE(Approximate(secondCamera.GetDirectionVector(), thirdVector,1e-5f));
//         ASSERT_TRUE(Approximate(secondCamera.GetUpVector(), firstVector,1e-5f));
//         ASSERT_TRUE(Approximate(secondCamera.GetRightVector(), secondVector,1e-5f));
//         ASSERT_TRUE(Approximate(secondCamera.GetViewMatrix(), secondMatrix,1e-3f));  
	}	
}

void Rendering::CameraTesting
	::FrustumTest()
{
	std::default_random_engine generator;
	std::uniform_real<float>  firstFloatRandomDistribution(-100.0f,100.0f);  

	for(int loop = 0;loop < GetTestLoopCount();++loop)
	{
        float directionMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator))); 

        float directionMax = -directionMin; 
 
        float upMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator))); 

        float upMax = -upMin; 

        float rightMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator))); 

        float rightMax = -rightMin; 

        float frustum[6] = { directionMin * 2.0f , directionMax, upMin / 2.0f, upMax, rightMin , rightMax * 1.5f };

        float ratio = upMax / directionMin;
        float upFieldOfViewDegrees = 2.0f * Mathematics::FloatMath::ATan(ratio) * Mathematics::FloatMath::GetRadianToDegree();
        float aspectRatio = rightMin / upMin;

        Camera firstCamera(true);

        firstCamera.SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);

        ASSERT_TRUE(firstCamera.IsPerspective());

        const float* firstFrustum  = firstCamera.GetFrustum();

        ASSERT_APPROXIMATE(firstFrustum[0], directionMin,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[1], directionMax,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[2], upMin,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[3], upMax,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[4], rightMin,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[5], rightMax,1e-5f);

        ASSERT_APPROXIMATE(firstCamera.GetDirectionMin (), directionMin,1e-5f);
        ASSERT_APPROXIMATE(firstCamera.GetDirectionMax(), directionMax,1e-5f);
        ASSERT_APPROXIMATE(firstCamera.GetUpMin (), upMin,1e-5f);
        ASSERT_APPROXIMATE(firstCamera.GetUpMax (), upMax,1e-5f);
        ASSERT_APPROXIMATE(firstCamera.GetRightMin (), rightMin,1e-5f);
        ASSERT_APPROXIMATE(firstCamera.GetRightMax (), rightMax,1e-5f);

        CameraFrustumData data = firstCamera.GetFrustumData();

        ASSERT_APPROXIMATE(data.GetUpFieldOfViewDegrees(), upFieldOfViewDegrees,1e-5f);
        ASSERT_APPROXIMATE(data.GetAspectRatio(), aspectRatio,1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMin(), directionMin,1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMax(), directionMax,1e-5f);
        ASSERT_TRUE(data.IsSymmetric());


        Camera secondCamera(false);   

        secondCamera.SetFrustum(frustum);

        ASSERT_FALSE(secondCamera.IsPerspective());

        firstFrustum  = secondCamera.GetFrustum();

        ASSERT_APPROXIMATE(firstFrustum[0], directionMin * 2.0f,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[1], directionMax,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[2], upMin / 2.0f,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[3], upMax,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[4], rightMin,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[5], rightMax * 1.5f,1e-5f);

        ASSERT_APPROXIMATE(secondCamera.GetDirectionMin (), directionMin * 2.0f,1e-5f);
        ASSERT_APPROXIMATE(secondCamera.GetDirectionMax(), directionMax,1e-5f);
        ASSERT_APPROXIMATE(secondCamera.GetUpMin (), upMin / 2.0f,1e-5f);
        ASSERT_APPROXIMATE(secondCamera.GetUpMax (), upMax,1e-5f);
        ASSERT_APPROXIMATE(secondCamera.GetRightMin (), rightMin,1e-5f);
        ASSERT_APPROXIMATE(secondCamera.GetRightMax (), rightMax * 1.5f,1e-5f);

        data = secondCamera.GetFrustumData();

        ASSERT_FALSE(data.IsSymmetric());

        Camera thirdCamera(false);   

        thirdCamera.SetFrustum(upFieldOfViewDegrees, aspectRatio,directionMin, directionMax);

        ASSERT_FALSE(thirdCamera.IsPerspective());

        firstFrustum  = thirdCamera.GetFrustum();

        float halfAngleRadians = 0.5f * upFieldOfViewDegrees * Mathematics::FloatMath::GetDegreeToRadian();

        float tanHalfAngleRadians = Mathematics::FloatMath::Tan(halfAngleRadians);

        ASSERT_APPROXIMATE(firstFrustum[0], directionMin,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[1], directionMax,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[2], -directionMin * tanHalfAngleRadians,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[3], directionMin * tanHalfAngleRadians,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[4], -aspectRatio * directionMin * tanHalfAngleRadians,1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[5], aspectRatio * directionMin * tanHalfAngleRadians,1e-5f);

        ASSERT_APPROXIMATE(thirdCamera.GetDirectionMin(), directionMin,1e-5f);
        ASSERT_APPROXIMATE(thirdCamera.GetDirectionMax(), directionMax,1e-5f);
        ASSERT_APPROXIMATE(thirdCamera.GetUpMin(), -directionMin * tanHalfAngleRadians,1e-5f);
        ASSERT_APPROXIMATE(thirdCamera.GetUpMax(), directionMin * tanHalfAngleRadians,1e-5f);
        ASSERT_APPROXIMATE(thirdCamera.GetRightMin(), -aspectRatio * directionMin * tanHalfAngleRadians,1e-5f);
        ASSERT_APPROXIMATE(thirdCamera.GetRightMax(), aspectRatio * directionMin * tanHalfAngleRadians,1e-5f);

        data = thirdCamera.GetFrustumData();

        ASSERT_APPROXIMATE(data.GetUpFieldOfViewDegrees(), upFieldOfViewDegrees,1e-4f);
        ASSERT_APPROXIMATE(data.GetAspectRatio(), aspectRatio,1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMin(), directionMin,1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMax(), directionMax,1e-5f);
        ASSERT_TRUE(data.IsSymmetric());
	}	
}

void Rendering::CameraTesting
	::ProjectionMatrixTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);  
	std::uniform_real<float>  secondFloatRandomDistribution(0.0f,180.0f);  

	for(int loop = 0;loop < GetTestLoopCount();++loop)
	{
        float directionMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator))); 

        float directionMax = -directionMin; 
 
        float upMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator))); 

        float upMax = -upMin; 

        float rightMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator))); 

        float rightMax = -rightMin; 

        Camera firstCamera(true);

        firstCamera.SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);

        DepthType depthType = firstCamera.GetDepthType ();

        float invDirectionDifference = 1.0f / (directionMax - directionMin);  
        float invUpDifference = 1.0f / (upMax - upMin);
        float invRightDifference = 1.0f / (rightMax - rightMin);
        float rightSumDivideDifference = (rightMin + rightMax) * invRightDifference;
        float upSumDivideDifference = (upMin + upMax) * invUpDifference;
        float directionSumDivideDifference = (directionMin + directionMax) * invDirectionDifference;
 
        float twoDirectionMinMultiplyInvRightDifference = 2.0f * directionMin * invRightDifference; 
        float twoDirectionMinMultiplyInvUpDifference = 2.0f * directionMin * invUpDifference;
        float directionMaxMultiplyInvDirectionDifference = directionMax * invDirectionDifference;   
        float directionProductDivideDifference = directionMin * directionMaxMultiplyInvDirectionDifference;
        float twoDirectionProductDivideDifference =   2.0f * directionProductDivideDifference;

        if(depthType == DepthType::ZeroToOne)
        {
             Camera::Matrix projection(twoDirectionMinMultiplyInvRightDifference,0.0f,-rightSumDivideDifference,0.0f,
                                       0.0f,twoDirectionMinMultiplyInvUpDifference,-upSumDivideDifference,0.0f,
                                       0.0f,0.0f,directionMaxMultiplyInvDirectionDifference,-directionProductDivideDifference,
                                       0.0f,0.0f,1.0f,0.0f);

             ASSERT_TRUE(Approximate(firstCamera.GetProjectionMatrix (), projection,1e-5f));
             ASSERT_TRUE(Approximate(firstCamera.GetProjectionViewMatrix (), projection * firstCamera.GetViewMatrix(),1e-5f));
        }
        else
        {
             Camera::Matrix projection(twoDirectionMinMultiplyInvRightDifference,0.0f,-rightSumDivideDifference,0.0f,
                                       0.0f,twoDirectionMinMultiplyInvUpDifference,-upSumDivideDifference,0.0f,
                                       0.0f,0.0f,directionSumDivideDifference,-twoDirectionProductDivideDifference,
                                       0.0f,0.0f,1.0f,0.0f);

             ASSERT_TRUE(Approximate(firstCamera.GetProjectionMatrix (), projection,1e-5f)); 
             ASSERT_TRUE(Approximate(firstCamera.GetProjectionViewMatrix (),projection * firstCamera.GetViewMatrix(),1e-5f));
        }

        Camera secondCamera(false);

        secondCamera.SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);

		depthType = secondCamera.GetDepthType();
        float twoInvRightDifference = 2.0f * invRightDifference;
        
 
        float twoInvUpDifference = 2.0f * invUpDifference;
        
 
        float twoInvDirectionDifference = 2.0f * invDirectionDifference;
  
        float directionMinMultiplyInvDirectionDifference =
                 directionMin * invDirectionDifference;

        if(depthType == DepthType::ZeroToOne)
        {
             Camera::Matrix projection(twoInvRightDifference,0.0f,0.0f,-rightSumDivideDifference,
                                       0.0f,twoInvUpDifference,0.0f, -upSumDivideDifference,
                                       0.0f,0.0f,invDirectionDifference,-directionMinMultiplyInvDirectionDifference,
                                       0.0f,0.0f,0.0f,1.0f);

             ASSERT_TRUE(Approximate(secondCamera.GetProjectionMatrix (), projection,1e-5f));
             ASSERT_TRUE(Approximate(secondCamera.GetProjectionViewMatrix (),projection * secondCamera.GetViewMatrix(),1e-5f));
        }
        else
        {
             Camera::Matrix projection(twoInvRightDifference,0.0f,0.0f,-rightSumDivideDifference,
                                       0.0f,twoInvUpDifference,0.0f,-upSumDivideDifference,
                                       0.0f,0.0f,twoInvDirectionDifference,-directionSumDivideDifference,
                                       0.0f,0.0f,0.0f,1.0f);

             ASSERT_TRUE(Approximate(secondCamera.GetProjectionMatrix (), projection,1e-5f)); 
             ASSERT_TRUE(Approximate(secondCamera.GetProjectionViewMatrix (),projection * secondCamera.GetViewMatrix(),1e-5f));
        }
        
        Camera::Matrix firstMatrix(firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator), 
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator));
  
        firstCamera.SetProjectionMatrix(firstMatrix);
        secondCamera.SetProjectionMatrix(firstMatrix);
        
        ASSERT_TRUE(Approximate(firstCamera.GetProjectionMatrix (), firstMatrix,1e-5f));
        ASSERT_TRUE(Approximate(firstCamera.GetProjectionViewMatrix (), firstMatrix * firstCamera.GetViewMatrix(),1e-5f));
        
        ASSERT_TRUE(Approximate(secondCamera.GetProjectionMatrix (), firstMatrix,1e-5f));
        ASSERT_TRUE(Approximate(secondCamera.GetProjectionViewMatrix (),firstMatrix * secondCamera.GetViewMatrix(),1e-5f));
        
        ASSERT_TRUE(firstCamera.PreViewIsIdentity());
        ASSERT_TRUE(secondCamera.PreViewIsIdentity());
        ASSERT_TRUE(firstCamera.PostProjectionIsIdentity());
        ASSERT_TRUE(secondCamera.PostProjectionIsIdentity());
    
        ASSERT_TRUE(Approximate(firstCamera.GetPreViewMatrix (), Camera::Matrix::GetIdentityMatrix(),1e-5f));
        ASSERT_TRUE(Approximate(firstCamera.GetPostProjectionMatrix(), Camera::Matrix::GetIdentityMatrix(), 1e-5f));
        
        ASSERT_TRUE(Approximate(secondCamera.GetPreViewMatrix(), Camera::Matrix::GetIdentityMatrix(), 1e-5f));
        ASSERT_TRUE(Approximate(secondCamera.GetPostProjectionMatrix(), Camera::Matrix::GetIdentityMatrix(), 1e-5f));
        
        
        Camera::Matrix secondMatrix(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator));
        
        Camera::Matrix thirdMatrix(firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator));
        
        firstCamera.SetPreViewMatrix(secondMatrix);
        
        ASSERT_FALSE(firstCamera.PreViewIsIdentity());
        ASSERT_TRUE(Approximate(firstCamera.GetPreViewMatrix(), secondMatrix,1e-5f));
        ASSERT_TRUE(Approximate(firstCamera.GetProjectionViewMatrix (),(firstMatrix * firstCamera.GetViewMatrix()) * secondMatrix,1e-5f));
        
        secondCamera.SetPostProjectionMatrix(secondMatrix);
        
        ASSERT_FALSE(secondCamera.PostProjectionIsIdentity());
        ASSERT_TRUE(Approximate(secondCamera.GetPostProjectionMatrix(), secondMatrix,1e-5f));
        ASSERT_TRUE(Approximate(secondCamera.GetProjectionViewMatrix (),secondMatrix * (firstMatrix * secondCamera.GetViewMatrix()),1e-5f));
        
        firstCamera.SetPostProjectionMatrix(thirdMatrix);
        
        ASSERT_FALSE(firstCamera.PostProjectionIsIdentity());
        ASSERT_TRUE(Approximate(firstCamera.GetPostProjectionMatrix(), thirdMatrix,1e-5f));
        ASSERT_TRUE(Approximate(firstCamera.GetProjectionViewMatrix (), (thirdMatrix * (firstMatrix * firstCamera.GetViewMatrix())) * secondMatrix,1e-5f));
        
        Camera::APoint p00(-12.0f,-1.0f,1.0);
        Camera::APoint p10(1.0f,-11.0f,2.0);
        Camera::APoint p11(1.0f,2.0f,3.0);
        Camera::APoint p01(-1.0f,3.0f,-1.0);
        
        float nearExtrude = Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator));
        float farExtrude = nearExtrude + 100.0f;
        
        Camera thirdCamera(false);
        thirdCamera.SetProjectionMatrix(p00,p10,p11,p01,nearExtrude,farExtrude);
        
        Camera::APoint q000 = nearExtrude * p00;
        Camera::APoint q100 = nearExtrude * p10;
        Camera::APoint q110 = nearExtrude * p11;
        Camera::APoint q010 = nearExtrude * p01;
 
        Camera::APoint q001 = farExtrude * p00;
        Camera::APoint q101 = farExtrude * p10;
        Camera::APoint q111 = farExtrude * p11;
        Camera::APoint q011 = farExtrude * p01;
    
        Camera::AVector u0 = q100 - q000;
        Camera::AVector u1 = q010 - q000;
        Camera::AVector u2 = q001 - q000;
        
        Camera::Matrix fourthMatrix(u0, u1, u2, q000, Mathematics::MatrixMajorFlags::Column);
        Camera::Matrix inverseMatrix = fourthMatrix.Inverse();
        Camera::APoint point = inverseMatrix * q111;
  
        float twoPoint0 = 2.0f * point[0];
        float twoPoint1 = 2.0f * point[1];
        float twoPoint2 = 2.0f * point[2];
        float d0 = +point[0] - point[1] - point[2] + 1.0f;
        float d1 = -point[0] + point[1] - point[2] + 1.0f;
        float d2 = -point[0] - point[1] + point[2] + 1.0f;
        float d3 = +point[0] + point[1] + point[2] - 1.0f;
 
        float twoPoint2divide0 = twoPoint2 / twoPoint0;
        float twoPoint2divide1 = twoPoint2 / twoPoint1;
        
        Camera::Matrix fifthMatrix;
        fifthMatrix(0,0) = twoPoint2divide0 * (2.0f * d3 + d0);
        fifthMatrix(0,1) = twoPoint2divide1 * d1;
        fifthMatrix(0,2) = d2;
        fifthMatrix(0,3) = -twoPoint2;
        fifthMatrix(1,0) = twoPoint2divide0 * d0;
        fifthMatrix(1,1)= twoPoint2divide1 * (2.0f * d3 + d1);
        fifthMatrix(1,2) = d2;
        fifthMatrix(1,3) = -twoPoint2;
        
        if (depthType == DepthType::ZeroToOne)
        {
            fifthMatrix(2,0) = 0.0f;
            fifthMatrix(2,1) = 0.0f;
            fifthMatrix(2,2) = d3;
            fifthMatrix(2,3) = 0.0f;
        }
        else
        {
            fifthMatrix(2,0) = twoPoint2divide0 * d0;
            fifthMatrix(2,1) = twoPoint2divide1 * d1;
            fifthMatrix(2,2) = 2.0f * d3 + d2;
            fifthMatrix(2,3) = -twoPoint2;
        }
        
        fifthMatrix(3,0) = -twoPoint2divide0 * d0;
        fifthMatrix(3,1) = -twoPoint2divide1 * d1;
        fifthMatrix(3,2)  = -d2;
        fifthMatrix(3,3)  = twoPoint2;
        
        ASSERT_TRUE(Approximate(thirdCamera.GetProjectionMatrix (), fifthMatrix * inverseMatrix,1e-5f));
	}
}

void Rendering::CameraTesting
	::AxesAlignBoundingBoxTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);    

	for(int loop = 0;loop < GetTestLoopCount();++loop)
	{
        float directionMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator)));
        float directionMax = -directionMin;
        float upMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator)));
        float upMax = -upMin;
        float rightMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator)));
        float rightMax = -rightMin;
        
        Camera::Matrix firstMatrix(firstFloatRandomDistribution(generator),firstFloatRandomDistribution(generator),firstFloatRandomDistribution(generator),firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),firstFloatRandomDistribution(generator),firstFloatRandomDistribution(generator),firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),firstFloatRandomDistribution(generator),firstFloatRandomDistribution(generator),firstFloatRandomDistribution(generator),
								   firstFloatRandomDistribution(generator),firstFloatRandomDistribution(generator),firstFloatRandomDistribution(generator), firstFloatRandomDistribution(generator));
        
        Camera firstCamera(true);
        firstCamera.SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);
        
        Camera::Matrix viewProjectionMatrix = firstCamera.GetProjectionMatrix() * firstCamera.GetViewMatrix();
        Camera::Matrix worldViewProjectionMatrix = viewProjectionMatrix * firstMatrix;
        
        vector<float> buffer;
        const int numVertices = 100;
        
        for (int i = 0; i < numVertices * 3; ++i)
        {
            buffer.push_back(firstFloatRandomDistribution(generator));
        }
        
        Camera::AxesAlignBoundingBox2D aabb = firstCamera.ComputeBoundingAABB(numVertices, reinterpret_cast<const char*>(&buffer[0]), sizeof(float) * 3,firstMatrix);
        
        float xmin = Mathematics::FloatMath::sm_MaxReal;
        float xmax = -Mathematics::FloatMath::sm_MaxReal;
        float ymin = Mathematics::FloatMath::sm_MaxReal;
        float ymax = -Mathematics::FloatMath::sm_MaxReal;
        for (int i = 0; i < numVertices; ++i)
        {
            const float* vertex = &buffer[i * 3];
            Mathematics::FloatHomogeneousPoint position(vertex[0], vertex[1], vertex[2], 1.0f);
            Mathematics::FloatHomogeneousPoint homogeneousPosition = worldViewProjectionMatrix * position;
            float invW = 1.0f / homogeneousPosition[3];
            float xNormalizeDeviceCoordinate  = homogeneousPosition[0] * invW;
            float yNormalizeDeviceCoordinate = homogeneousPosition[1] * invW;
            if (xNormalizeDeviceCoordinate < xmin)
            {
                xmin = xNormalizeDeviceCoordinate;
            }
            if (xmax < xNormalizeDeviceCoordinate)
            {
                xmax = xNormalizeDeviceCoordinate;
            }
            if (yNormalizeDeviceCoordinate < ymin)
            {
                ymin = yNormalizeDeviceCoordinate;
            }
            if (ymax < yNormalizeDeviceCoordinate)
            {
                ymax = yNormalizeDeviceCoordinate;
            }
        }

// 		Camera::AxesAlignBoundingBox2D resultAabb = Mathematics::AxesAlignBoundingBox2Df(xmin,xmax,ymin,ymax);
// 		        
//         ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(resultAabb.GetMinPoint(),aabb.GetMinPoint(),1e-5f));
// 		ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(resultAabb.GetMaxPoint(),aabb.GetMaxPoint(),1e-5f));
	}
}

void Rendering::CameraTesting
	::StreamTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);    

	for(int loop = 0;loop < GetTestLoopCount();++loop)
	{
        Camera::APoint firstPosition(firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator));
        
        Camera::AVector firstVector(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));
        
        firstVector.Normalize();
        
        Camera::AVector secondVector(firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator));
        
        secondVector.Normalize();
        
        Camera::AVector thirdVector(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));
        
        thirdVector.Normalize();
        
//         Mathematics::AVectorOrthonormalizef orthonormalize = Orthonormalize(firstVector, secondVector, thirdVector,1e-4f);
//         
//         firstVector = orthonormalize.GetUVector();
//         secondVector = orthonormalize.GetVVector();
//         thirdVector = orthonormalize.GetWVector();
//         
//         float directionMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator)));
//         
//         float directionMax = -directionMin;
//         
//         float upMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator)));
//         
//         float upMax = -upMin;
//         
//         float rightMin(- Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator)));
//         
//         float rightMax = -rightMin;
//         
//         Camera::Matrix firstMatrix(firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator),
//                            firstFloatRandomDistribution(generator));
//         
//         
//         Camera::Matrix secondMatrix(firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator),
//                             firstFloatRandomDistribution(generator));
//         
//         CoreTools::OutTopLevel outTopLevel;
//         CoreTools::ObjectInterfaceSharedPtr objectPtr(new Camera(true,1e-4f));
// 
// 		Camera* firstCamera = CoreTools::PolymorphicDowncast<Camera>(objectPtr.GetData());
//         
//         firstCamera->SetFrame(firstPosition, firstVector,
//                               secondVector, thirdVector);
//         firstCamera->SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);
//         firstCamera->SetPostProjectionMatrix(firstMatrix);
//         firstCamera->SetPostProjectionMatrix(secondMatrix);
//         
//         firstCamera->SetUniqueID(1);
//         
//         outTopLevel.Insert(objectPtr);
//         
//         CoreTools::BufferOutStream outStream(outTopLevel);
//         
//         CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
//         
//         CoreTools::BufferInStream inStream(fileBufferPtr);
//         
//         CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
//         
//         CameraSharedPtr secondCamera =  inTopLevel[0].PolymorphicDowncastObjectSharedPtr<CameraSharedPtr>();
//         
//         ASSERT_TRUE(Approximate(firstCamera->GetPosition(),secondCamera->GetPosition(),1e-5f));
//         ASSERT_TRUE(Approximate(firstCamera->GetDirectionVector(),secondCamera->GetDirectionVector(),1e-5f));
//         ASSERT_TRUE(Approximate(firstCamera->GetUpVector(),secondCamera->GetUpVector(),1e-5f));
//         ASSERT_TRUE(Approximate(firstCamera->GetRightVector(),secondCamera->GetRightVector(),1e-5f));
//         ASSERT_TRUE(Approximate(firstCamera->GetViewMatrix(),secondCamera->GetViewMatrix(),1e-5f));
//         ASSERT_EQUAL(firstCamera->IsPerspective(),secondCamera->IsPerspective());
//         ASSERT_APPROXIMATE(firstCamera->GetDirectionMin (),secondCamera->GetDirectionMin (),1e-5f);
//         ASSERT_APPROXIMATE(firstCamera->GetDirectionMax (),secondCamera->GetDirectionMax (),1e-5f);
//         ASSERT_APPROXIMATE(firstCamera->GetUpMin (),secondCamera->GetUpMin (),1e-5f);
//         ASSERT_APPROXIMATE(firstCamera->GetUpMax (),secondCamera->GetUpMax (),1e-5f);
//         ASSERT_APPROXIMATE(firstCamera->GetRightMin (),secondCamera->GetRightMin (),1e-5f);
//         ASSERT_APPROXIMATE(firstCamera->GetRightMax (),secondCamera->GetRightMax (),1e-5f);
//         
//         ASSERT_TRUE(Approximate(firstCamera->GetProjectionMatrix(),secondCamera->GetProjectionMatrix(),1e-5f));
//         ASSERT_TRUE(Approximate(firstCamera->GetProjectionViewMatrix(),secondCamera->GetProjectionViewMatrix(),1e-5f));
//         ASSERT_TRUE(Approximate(firstCamera->GetPreViewMatrix(),secondCamera->GetPreViewMatrix(),1e-5f));
//         ASSERT_TRUE(Approximate(firstCamera->GetPostProjectionMatrix(),secondCamera->GetPostProjectionMatrix(),1e-5f));      
	}
}
