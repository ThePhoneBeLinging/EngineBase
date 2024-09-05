//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef SAMPLECLIENT_H
#define SAMPLECLIENT_H
#include <memory>

#include "SampleObject.h"


class SampleClient
{
public:
    SampleClient();
    static void update(float deltaTime);

private:
    static inline std::shared_ptr<SampleObject> sampleObject_;
};


#endif //SAMPLECLIENT_H
