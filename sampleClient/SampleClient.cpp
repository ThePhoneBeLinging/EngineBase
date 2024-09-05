//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "SampleClient.h"

#include <memory>

#include "SampleObject.h"
#include "EngineBase/EngineBase.h"
#include "EngineBase/KeyBoardKeys.h"

SampleClient::SampleClient()
{
    sampleObject_ = std::make_shared<SampleObject>();
}

void SampleClient::update(float deltaTime)
{
    sampleObject_->speedAble_.update(deltaTime);
    if (EngineBase::keyPressed(ENGINEBASE_KEY_S))
    {
        sampleObject_->speedAble_.xSpeed(100);
    }
}
