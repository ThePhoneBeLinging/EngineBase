//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "SampleClient.h"

#include <memory>

#include "SampleObject.h"

SampleClient::SampleClient()
{
    sampleObject_ = std::make_shared<SampleObject>();
}
