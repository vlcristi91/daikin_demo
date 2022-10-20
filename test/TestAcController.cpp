#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "AcController.h"
#include "IAcControllerInput.h"
#include "IAcControllerOutput.h"
#include "AcControllerStates.h"
#include "common.h"

class MockInput : public IAcControllerInput
{
  public:
    MOCK_METHOD(void, cycle, (), (override)); 
    MOCK_METHOD(temp, getInteriorTemperature, (), (const, override));
    MOCK_METHOD(temp, getDesiredTemperature, (), (const, override));
};


class MockOutput : public IAcControllerOutput
{
  public:
    MOCK_METHOD(void, cycle, (), (override)); 
    MOCK_METHOD(void, setCoolingHeatingDemand, (percentage), (override));
};

class TestAcController : public ::testing::Test
{
  public:
    TestAcController() : _acController(_input, _output) {}

    void SetUp() override
    {

    }

    void TearDown() override
    {

    }


    ::testing::StrictMock<MockInput> _input;
    ::testing::StrictMock<MockOutput> _output;
    AcController _acController;
};


using ::testing::Return;
using ::testing::_;

TEST_F(TestAcController, TestStateOffToOff) 
{

  // interior temperature == desired temperature
  EXPECT_CALL(_input, getInteriorTemperature()).WillRepeatedly(Return(2300));
  EXPECT_CALL(_input, getDesiredTemperature()).WillRepeatedly(Return(2300));

  _acController.setState(AcControllerOff::getInstance());

  EXPECT_CALL(_output, setCoolingHeatingDemand(0)).Times(1);
  _acController.cycle();
  EXPECT_EQ(_acController.getCurrentState(), &AcControllerOff::getInstance()); 


  // temperature delta is within tolerance
  EXPECT_CALL(_input, getInteriorTemperature()).WillRepeatedly(Return(2400));
  EXPECT_CALL(_input, getDesiredTemperature()).WillRepeatedly(Return(2300));
  EXPECT_CALL(_output, setCoolingHeatingDemand(0)).Times(1);
  _acController.cycle();
  EXPECT_EQ(_acController.getCurrentState(), &AcControllerOff::getInstance()); 

  // temperature delta is within tolerance
  EXPECT_CALL(_input, getInteriorTemperature()).WillRepeatedly(Return(2200));
  EXPECT_CALL(_input, getDesiredTemperature()).WillRepeatedly(Return(2300));
  EXPECT_CALL(_output, setCoolingHeatingDemand(0)).Times(1);
  _acController.cycle();
  EXPECT_EQ(_acController.getCurrentState(), &AcControllerOff::getInstance()); 

}

TEST_F(TestAcController, TestStateOffToHeating) 
{
  // temperature delta is above tolerance, turn heating on
  EXPECT_CALL(_input, getInteriorTemperature()).WillRepeatedly(Return(2199));
  EXPECT_CALL(_input, getDesiredTemperature()).WillRepeatedly(Return(2300));

  _acController.setState(AcControllerOff::getInstance());

  EXPECT_CALL(_output, setCoolingHeatingDemand(25)).Times(1);
  // this cycle changes state to heating
  _acController.cycle();
  //cycle again so coolingHeatingDemand is sent.
  _acController.cycle();
  EXPECT_EQ(_acController.getCurrentState(), &AcControllerHeating::getInstance()); 

}

TEST_F(TestAcController, TestStateOffToCooling) 
{
  // temperature delta is below lower tolerance, turn cooling on
  EXPECT_CALL(_input, getInteriorTemperature()).WillRepeatedly(Return(2401));
  EXPECT_CALL(_input, getDesiredTemperature()).WillRepeatedly(Return(2300));

  _acController.setState(AcControllerOff::getInstance());

  EXPECT_CALL(_output, setCoolingHeatingDemand(-25)).Times(1);
  // enter to state cooling
  _acController.cycle();
  //cycle again so coolingHeatingDemand is sent.
  _acController.cycle();
  EXPECT_EQ(_acController.getCurrentState(), &AcControllerCooling::getInstance()); 
}

TEST_F(TestAcController, TestStateCooling) 
{
  _acController.setState(AcControllerCooling::getInstance());

  // interior temperature is > than desired temp
  EXPECT_CALL(_input, getInteriorTemperature()).WillRepeatedly(Return(2450));
  EXPECT_CALL(_input, getDesiredTemperature()).WillRepeatedly(Return(2300));
  EXPECT_CALL(_output, setCoolingHeatingDemand(-37)).Times(1);
  _acController.cycle();
  EXPECT_EQ(_acController.getCurrentState(), &AcControllerCooling::getInstance()); 

  // room cools down
  EXPECT_CALL(_input, getInteriorTemperature()).WillRepeatedly(Return(2370));
  EXPECT_CALL(_output, setCoolingHeatingDemand(-17)).Times(1);
  _acController.cycle();
  EXPECT_EQ(_acController.getCurrentState(), &AcControllerCooling::getInstance()); 

  // room reaches desired temperature, cooling turns off
  EXPECT_CALL(_input, getInteriorTemperature()).WillRepeatedly(Return(2300));
  _acController.cycle();
  EXPECT_EQ(_acController.getCurrentState(), &AcControllerOff::getInstance()); 
}

TEST_F(TestAcController, TestStateHeating) 
{
  _acController.setState(AcControllerHeating::getInstance());

  // heating required
  EXPECT_CALL(_input, getInteriorTemperature()).WillRepeatedly(Return(2150));
  EXPECT_CALL(_input, getDesiredTemperature()).WillRepeatedly(Return(2300));
  EXPECT_CALL(_output, setCoolingHeatingDemand(37)).Times(1);
  _acController.cycle();
  EXPECT_EQ(_acController.getCurrentState(), &AcControllerHeating::getInstance()); 

  // room is heating up
  EXPECT_CALL(_input, getInteriorTemperature()).WillRepeatedly(Return(2230));
  EXPECT_CALL(_output, setCoolingHeatingDemand(17)).Times(1);
  _acController.cycle();
  EXPECT_EQ(_acController.getCurrentState(), &AcControllerHeating::getInstance()); 

  // target temperature reached, turn heating off.
  EXPECT_CALL(_input, getInteriorTemperature()).WillRepeatedly(Return(2300));
  _acController.cycle();
  EXPECT_EQ(_acController.getCurrentState(), &AcControllerOff::getInstance()); 
}