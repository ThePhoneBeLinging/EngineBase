//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//


#include <cassert>
#include "SceneManager.h"

void SceneManager::setScene(int scene)
{
    assert(scene >= 0);
    this->mScene = scene;
}

int SceneManager::getScene()
{
    return this->mScene;
}
