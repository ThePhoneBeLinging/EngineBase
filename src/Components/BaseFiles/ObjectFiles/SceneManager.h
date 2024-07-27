//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H


class SceneManager
{
public:
    SceneManager() = default;
    void setScene(int scene);
    int getScene();

private:
    int mScene;
};


#endif //SCENEMANAGER_H
